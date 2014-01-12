link_directories(${CMAKE_CURRENT_SOURCE_DIR}/build/lib/file_system)

add_unit_test(test_path)
target_link_libraries(test_path zlibc-file_system ${COMMON_TARGET_LINK_LIBRARIES})
