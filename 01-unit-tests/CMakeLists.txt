cmake_minimum_required(VERSION 3.14)
project(QuadraticEquationTDD VERSION 1.0.0 LANGUAGES CXX)

# Интерфейсная библиотека для заголовков
add_library(QuadraticEquationSolve INTERFACE)
target_include_directories(QuadraticEquationSolve INTERFACE include)

# Основные тесты
add_executable(QuadraticEquationSolveTests 
    tests/test_quadratic_equation_solve.cpp
)

# Связывание с библиотекой и GTest
target_link_libraries(QuadraticEquationSolveTests 
    PRIVATE 
    QuadraticEquationSolve 
    GTest::gtest_main 
    GTest::gmock
)

# Автоматическое обнаружение тестов
include(GoogleTest)
gtest_discover_tests(QuadraticEquationSolveTests)

