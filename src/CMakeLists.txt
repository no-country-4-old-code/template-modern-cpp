# add main app
add_subdirectory(main)

# add libraries
add_subdirectory(build-info)
add_subdirectory(print)

# link libraries to main app
target_link_libraries(${EXECUTABLE_NAME} PUBLIC BuildInfo)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC PrettyPrintLib)
