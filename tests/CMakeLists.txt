cmake_minimum_required(VERSION 3.5)
project(MyProject)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(GTest REQUIRED)

set(SOURCES 
    ../src/models/robot.cpp
)

set(HEADERS 
    ../src/models/robot.h
)

add_executable(tests test1.cpp ${SOURCES} ${HEADERS})
target_link_libraries(tests GTest::GTest GTest::Main)
target_include_directories(tests PRIVATE /usr/include/x86_64-linux-gnu/qt5)
target_link_libraries(tests Qt5::Widgets)
