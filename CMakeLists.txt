cmake_minimum_required(VERSION 2.8)

project(zLibC)

set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(lib)
add_subdirectory(unit-tests)
