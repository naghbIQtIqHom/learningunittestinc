cmake_minimum_required(VERSION 3.12)

project(calc C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_C_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
file(GLOB SRC_FILES ${SRC_DIR}/*.c)
add_executable(calc ${SRC_FILES})

add_library(calc_lib src/calc.c)

target_include_directories(calc_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_subdirectory(test)

enable_testing()
add_test(NAME test_calc_dec COMMAND test_calc_declare_dummy_func)
add_test(NAME test_calc_opt COMMAND test_calc_with_option_unsolved_symbol)


