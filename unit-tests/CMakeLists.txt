function(add_unit_test name)
    add_executable(${name} "${name}.c")
endfunction()

set(COMMON_TARGET_LINK_LIBRARIES zcut_main)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(adt)
add_subdirectory(file_system)
