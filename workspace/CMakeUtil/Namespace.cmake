
# set namespace (namespace_parent, namespace_current)
function(set_namespace)
    cmake_minimum_required(VERSION 3.20)
    set(current_path ${CMAKE_CURRENT_SOURCE_DIR})
    cmake_path(GET current_path FILENAME dir)
    set(namespace_parent ${namespace_current} PARENT_SCOPE)
    set(namespace_current ${namespace_current}${dir}_ PARENT_SCOPE)
endfunction()



