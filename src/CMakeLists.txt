cmake_minimum_required(VERSION 3.14)
project(MacroCommandTDD VERSION 1.0.0 LANGUAGES CXX)

add_library(MacroCommand INTERFACE)
target_include_directories(MacroCommand INTERFACE include)


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

add_executable(MacroCommandTests 
    tests/main.cpp
)


target_link_libraries(MacroCommandTests 
    PRIVATE 
    MacroCommand 
    GTest::gtest_main 
    GTest::gmock
)

include(GoogleTest)
gtest_discover_tests(MacroCommandTests)

