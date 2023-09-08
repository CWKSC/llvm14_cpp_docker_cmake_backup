
function(library_link)
    set(args ${ARGN})
    list(TRANSFORM args PREPEND "${namespace_current}")

    target_link_libraries(${target_current} ${args})
endfunction()

function(interface_library_link)
    set(args ${ARGN})
    list(TRANSFORM args PREPEND "$<TARGET_OBJECTS:${namespace_current}")
    list(TRANSFORM args APPEND ">")

    target_sources(${target_current} INTERFACE ${args})
endfunction()

function(interface_library_link_interface)
    set(args ${ARGN})
    list(TRANSFORM args PREPEND "${namespace_current}")

    target_link_libraries(${target_current} INTERFACE ${args})
endfunction()

function(link_library_root)
    set(args ${ARGN})
    list(TRANSFORM args PREPEND "${namespace_current}")

    target_link_libraries(${PROJECT_NAME} ${args})
endfunction()


