cmake_minimum_required(VERSION 3.5)

project(icp-robots VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        src/runApp.cpp
        src/models/robotBase.cpp
        src/models/robotBase.hpp
        src/models/automaticRobot.cpp
        src/models/automaticRobot.hpp
        src/models/manualRobot.cpp
        src/models/manualRobot.hpp
        src/models/wall.cpp
        src/models/wall.hpp
        src/controllers/controller.cpp
        src/controllers/controller.hpp
        src/gui/gui.cpp
        src/gui/gui.hpp
        src/gui/areaWidget.cpp
        src/gui/areaWidget.hpp
        src/gui/menuBar.hpp
        src/gui/menuBar.cpp
        src/gui/sideBar.hpp
        src/gui/sideBar.cpp
        src/gui/simulationControlWidget.hpp
        src/gui/simulationControlWidget.cpp
        src/gui/robotOverviewWidget.hpp
        src/gui/robotOverviewWidget.cpp
        src/models/robotBase.cpp
        src/models/robotBase.hpp
        src/utilities/vector2d.cpp
        src/utilities/vector2d.hpp
        src/services/saver.cpp
        src/services/saver.hpp
        src/services/loader.cpp
        src/services/loader.hpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(icp-robots
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET icp-robots APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(icp-robots SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(icp-robots
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(icp-robots PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.icp-robots)
endif()
set_target_properties(icp-robots PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS icp-robots
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(icp-robots)
endif()
