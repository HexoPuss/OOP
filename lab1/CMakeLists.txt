cmake_minimum_required(VERSION 3.10)
project(Lab1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_library(LabLib lab1.cpp)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(LabTest labTest.cpp)
target_link_libraries(LabTest LabLib GTest::gtest GTest::gtest_main)

enable_testing()
add_test(NAME LabTests COMMAND labTest)
