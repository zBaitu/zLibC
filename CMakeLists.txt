cmake_minimum_required(VERSION 2.8)

project(zLibC)

find_program(CLANG "clang")
if (EXISTS ${CLANG})
    set(CMAKE_C_COMPILER "clang")
endif()

set(CMAKE_C_FLAGS "-std=gnu99 -Wall -Wextra -Werror")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(lib)
add_subdirectory(unit-tests)
