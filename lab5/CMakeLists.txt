
cmake_minimum_required(VERSION 3.10)
project(OOP_LABS)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Пути до заголовков — глобально
include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

# ----------------------------------------
# Основная программа
# ----------------------------------------
add_executable(main
    test.cpp
)
# не нужно ничего линковать — шаблоны header‑only

