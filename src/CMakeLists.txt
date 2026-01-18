cmake_minimum_required(VERSION 3.14)
project(IoCTDD VERSION 1.0.0 LANGUAGES CXX)

add_library(IoC INTERFACE)
target_include_directories(IoC INTERFACE include)


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

add_executable(IoCTests 
    Init.cpp
    tests/main.cpp
)


target_link_libraries(IoCTests 
    PRIVATE 
    IoC 
    GTest::gtest_main 
    GTest::gmock
)

include(GoogleTest)
gtest_discover_tests(IoCTests)

