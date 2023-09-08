

macro(create_gtest libraryName)
    if(${CMAKE_PROJECT_NAME} STREQUAL ${libraryName})
        enable_testing()
        include(GoogleTest)
        add_executable(test_${libraryName} test.cpp)
        target_link_libraries(test_${libraryName} gtest gtest_main pthread ${PROJECT_NAME})
        gtest_discover_tests(test_${libraryName})
    endif()
endmacro()


macro(create_gtest_with_argn testName)
    set (extra_args ${ARGN})
    list(LENGTH extra_args extra_count)
    if (${extra_count} GREATER 0)
        list(GET extra_args 0 optional_arg)
        if(optional_arg STREQUAL "TEST")
            create_gtest(${testName})
        endif()
    endif ()
endmacro()


