
function(auto_add_subdir)
    file(GLOB childs *)
    foreach(child ${childs})
        if(IS_DIRECTORY ${child})
            add_subdirectory(${child})
        endif()
    endforeach()
endfunction()

