link_directories(${CMAKE_CURRENT_SOURCE_DIR}/build/lib/adt)

add_unit_test(test_string)
target_link_libraries(test_string zlibc-adt ${COMMON_TARGET_LINK_LIBRARIES})
