

macro(install_library libraryName)
    if(${CMAKE_PROJECT_NAME} STREQUAL ${libraryName})
        install(
            TARGETS ${libraryName}
            LIBRARY DESTINATION lib
        )
        install(
            FILES ${CMAKE_SOURCE_DIR}/${libraryName}/${libraryName}Config.cmake
            DESTINATION lib/${libraryName}/cmake/
        )
        install(
            DIRECTORY "${CMAKE_SOURCE_DIR}/" # source directory
            DESTINATION "include" # target directory
            FILES_MATCHING # install only matched files
            PATTERN "*.h" # select header files
        )
    endif()
endmacro()

