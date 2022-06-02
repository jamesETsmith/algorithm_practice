cmake_minimum_required(VERSION 3.15)

project(dijkstra LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")


set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
include_directories(${SRC_DIR})
add_library(dijkstra SHARED ${SRC_DIR}/dijkstra.cpp)

#
# Tests
#
enable_testing()
include_directories(${CMAKE_SOURCE_DIR}/../external/doctest)
add_executable(tests ${SRC_DIR}/tests.cpp)
target_link_libraries(tests PRIVATE dijkstra)
add_test(NAME tests COMMAND tests)