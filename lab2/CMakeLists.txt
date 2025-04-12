cmake_minimum_required(VERSION 3.10)
project(FiveProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_library(FiveLib Five.cpp)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(FiveTests test_Five.cpp)
target_link_libraries(FiveTests FiveLib GTest::gtest GTest::gtest_main)

enable_testing()
add_test(NAME FiveUnitTests COMMAND FiveTests)
