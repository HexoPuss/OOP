cmake_minimum_required(VERSION 3.10)
project(OOP_LABS)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)
include_directories(heads)

# Добавляем исходники (при необходимости добавьте Five.cpp)
add_library(Hexagon src/hexagon.cpp)
add_library(Octagon src/octagon.cpp)
add_library(Pentagon src/pentagon.cpp)

# Находим Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(main main.cpp)
target_link_libraries(main Hexagon Pentagon Octagon)

# Создаём исполняемый файл для тестов
add_executable(PolygonTest test.cpp)
target_link_libraries(PolygonTest Hexagon Pentagon Octagon GTest::gtest GTest::gtest_main)

enable_testing()
add_test(NAME PolygonTests COMMAND PolygonTest)
