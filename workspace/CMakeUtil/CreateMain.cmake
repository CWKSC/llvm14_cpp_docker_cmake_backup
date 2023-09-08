

function(create_main)
    add_executable(Main main.cpp)
    auto_add_subdir()
endfunction()

function(create_main_and_link)
    add_executable(Main main.cpp)
    auto_add_subdir()
    target_link_libraries(Main ${ARGN})
endfunction()

function(create_library_main)
    add_executable(Main main.cpp)
    auto_add_subdir()
    target_link_libraries(Main ${PROJECT_NAME})
endfunction()

