cmake_minimum_required(VERSION 3.14)
project(QuadraticEquationTDD VERSION 1.0.0 LANGUAGES CXX)

add_library(MoveRotate INTERFACE)
target_include_directories(MoveRotate INTERFACE include)

add_executable(MoveRotateTests 
    tests/main.cpp
)

target_link_libraries(MoveRotateTests 
    PRIVATE 
    MoveRotate 
    GTest::gtest_main 
    GTest::gmock
)

include(GoogleTest)
gtest_discover_tests(MoveRotateTests)

