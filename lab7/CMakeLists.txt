
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
    main.cpp
)

find_package(GTest REQUIRED)
if (GTest_FOUND)
    enable_testing()
    include_directories(${GTEST_INCLUDE_DIRS})

    add_executable(Test
        test.cpp
    )

    
    target_link_libraries(Test PRIVATE GTest::gtest GTest::gtest_main)

    add_test(NAME TestGame COMMAND TestGame)
endif()
# не нужно ничего линковать — шаблоны header‑only

