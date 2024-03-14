cmake_minimum_required(VERSION 3.5)
project(MyProject)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(GTest REQUIRED)

set(SOURCES 
    ../src/models/robot.cpp
    ../src/models/wall.cpp
    ../src/controllers/robot_controller.cpp
    ../tests/simple_robot_tests.cpp
    ../tests/wall_tests.cpp
    ../tests/robot_controller_tests.cpp
    ../tests/collision_tests.cpp
)

set(HEADERS 
    ../src/models/robot.h
    ../src/models/wall.h
    ../src/controllers/robot_controller.h
    ../tests/simple_robot_tests.h
    ../tests/wall_tests.h
    ../tests/robot_controller_tests.h
    ../tests/collision_tests.h
)

add_executable(tests ../run_tests.cpp ${SOURCES} ${HEADERS})
target_link_libraries(tests GTest::GTest GTest::Main)
target_include_directories(tests PRIVATE /usr/include/x86_64-linux-gnu/qt5)
target_link_libraries(tests Qt5::Widgets)
