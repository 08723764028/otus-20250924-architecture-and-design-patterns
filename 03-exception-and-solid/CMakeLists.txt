cmake_minimum_required(VERSION 3.14)
project(ExceptionAndSolidTDD VERSION 1.0.0 LANGUAGES CXX)

add_library(ExceptionAndSolid INTERFACE)
target_include_directories(ExceptionAndSolid INTERFACE include)


# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
        -Werror
        # Отключаем варнинги на неиспользуемые переменные и параметры
        -Wno-unused-parameter
        -Wno-unused-variable
        -Wno-unused-but-set-variable
    )

add_executable(ExceptionAndSolidTests 
    tests/main.cpp
)


target_link_libraries(ExceptionAndSolidTests 
    PRIVATE 
    ExceptionAndSolid 
    GTest::gtest_main 
    GTest::gmock
)

include(GoogleTest)
gtest_discover_tests(ExceptionAndSolidTests)

