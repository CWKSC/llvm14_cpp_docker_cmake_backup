
macro(create_library libraryName libraryType)
    set_namespace()
    add_library(${namespace_parent}${libraryName} ${libraryType} ${libraryName}.cpp)
    set_current_target(${namespace_parent}${libraryName})
    auto_add_subdir()
    create_gtest_with_argn(${namespace_parent}${libraryName} ${ARGN})
endmacro()

macro(create_interface_library libraryName)
    set_namespace()
    add_library(${namespace_parent}${libraryName} INTERFACE)
    set_current_target(${namespace_parent}${libraryName})
    auto_add_subdir()
    create_gtest_with_argn(${namespace_parent}${libraryName} ${ARGN})
endmacro()

# need dummy.cpp
macro(create_dummy_library libraryName libraryType)
    set_namespace()
    add_library(${namespace_parent}${libraryName} ${libraryType} dummy.cpp)
    set_current_target(${namespace_parent}${libraryName})
    auto_add_subdir()
    create_gtest_with_argn(${namespace_parent}${libraryName} ${ARGN})
endmacro()

# need dummy.cpp
macro(create_library_root)
    set(namespace_current "")
    set_namespace()
    add_library(${PROJECT_NAME} STATIC dummy.cpp)
    set_current_target(${PROJECT_NAME})
    auto_add_subdir()
    create_gtest_with_argn(${PROJECT_NAME} ${ARGN})
endmacro(create_library_root)



