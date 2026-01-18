cmake_minimum_required(VERSION 3.14)
project(EducationProjects VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_compile_options(-Wall -Wextra -Wpedantic -Werror -Wconversion -Werror=unused-parameter)


include(FetchContent)

# Настройка GoogleTest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Добавление подпроекта с unit-тестами
add_subdirectory(src)