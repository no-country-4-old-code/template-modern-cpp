add_subdirectory(other)
add_gtest("${CMAKE_CURRENT_SOURCE_DIR}/print/test_print.cpp" PrettyPrintLib)
add_gtest("${CMAKE_CURRENT_SOURCE_DIR}/other/specfic/test_nested2.cpp" "")
