cmake_minimum_required(VERSION 3.28.3)
project(MathLibProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(MathLibProject src/main.cpp src/math_functions.cpp)
enable_testing()
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.2
)
FetchContent_MakeAvailable(Catch2)

# Test executable
add_executable(tests tests/math_tests.cpp src/math_functions.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(tests PRIVATE include)
include(${catch2_SOURCE_DIR}/extras/Catch.cmake)
catch_discover_tests(tests)
enable_testing()
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.2
)
FetchContent_MakeAvailable(Catch2)

