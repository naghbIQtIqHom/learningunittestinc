cmake_minimum_required(VERSION 3.12)
project(hello)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

file(GLOB SRC_FILES ${SRC_DIR}/*.c)
file(GLOB TEST_FILES ${TEST_DIR}/*.cpp)

add_executable(hello ${SRC_FILES})
target_include_directories(hello PRIVATE ${SRC_DIR})

enable_testing()
add_test(NAME run_test_hello COMMAND test_hello)
add_executable(test_hello ${TEST_FILES} ${SRC_FILES})
target_include_directories(test_hello PRIVATE ${SRC_DIR})
target_include_directories(test_hello PRIVATE ${TEST_DIR})
target_compile_definitions(test_hello PRIVATE MAIN_FOR_UNITTEST)
target_link_libraries(test_hello PRIVATE Catch2Main Catch2)

