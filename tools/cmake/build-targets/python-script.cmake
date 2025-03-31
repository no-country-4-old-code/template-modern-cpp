##
# Creates a custom target to run a python script.
##
function(create_target_python_script)
    # Use function to not pollute shared namespace with custom variables
    set(_TOOL_TARGET_NAME "python-script")
    set(_TOOL_OUTPUT_PATH "${PROJECT_REPORT_PATH}/metrics")
    set(_TOOL_OUTPUT_FILENAME "${_TOOL_OUTPUT_PATH}/Stats.txt")

    find_package(Python3 3.8 REQUIRED)

    if(NOT Python3_FOUND)
        message(
            FATAL_ERROR
                "'Python > v3.8' was not found. Install Python or disable 'Code Metric' option !")
    else()
        message(STATUS "Use Python : ${Python3_EXECUTABLE}")
    endif()

    if(NOT TARGET ${_TOOL_TARGET_NAME})

        set(_SCRIPT_NAME "detect-dependencies.py")

        add_custom_target(
            ${_TOOL_TARGET_NAME}
            # Ensure the output directory is created
            COMMAND ${CMAKE_COMMAND} -E make_directory "${_TOOL_OUTPUT_PATH}"
            # Run python script
            COMMAND ${Python3_EXECUTABLE} ${_SCRIPT_NAME} ${SRC_FOLDER_PATH}
            WORKING_DIRECTORY ${TOOLS_FOLDER_PATH}/scripts
            COMMENT "Runs python script: ${_SCRIPT_NAME}")
    endif()
endfunction()

create_target_python_script()
