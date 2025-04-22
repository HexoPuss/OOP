
cmake_minimum_required(VERSION 3.10)
project(OOP_LABS)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Пути до заголовков и .ipp — глобально
include_directories(
    ${CMAKE_SOURCE_DIR}/heads
    ${CMAKE_SOURCE_DIR}/src
)

# ----------------------------------------
# Основная программа
# ----------------------------------------
add_executable(main
    main.cpp
)
# не нужно ничего линковать — шаблоны header‑only

# ----------------------------------------
# Настройка Google Test
# ----------------------------------------
find_package(GTest REQUIRED)
if (GTest_FOUND)
    enable_testing()
    include_directories(${GTEST_INCLUDE_DIRS})

    add_executable(PolygonTestFloat
        figures_test_float.cpp
    )

    add_executable(PolygonTestInt
        figures_test_int.cpp
    )
    
    target_link_libraries(PolygonTestInt PRIVATE GTest::gtest GTest::gtest_main)

    target_link_libraries(PolygonTestFloat PRIVATE GTest::gtest GTest::gtest_main)

    add_test(NAME PolygonTestsFloat COMMAND PolygonTestFloat)
endif()
