cmake_minimum_required(VERSION 3.2...3.27.5)

project(Hometask)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(bubble_sort)
add_subdirectory(29.11.2025)
add_subdirectory(unit_test_example)

set(CMAKE_SUPPRESS_REGENERATION true)