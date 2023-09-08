

### LLVM https://llvm.org/docs/CMake.html#embedding-llvm-in-your-project
function(include_llvm)
    find_package(LLVM REQUIRED CONFIG)
    message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
    message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
    include_directories(${LLVM_INCLUDE_DIRS})
    separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
    add_definitions(${LLVM_DEFINITIONS_LIST})
    llvm_map_components_to_libnames(llvm_libs ${LLVM_TARGETS_TO_BUILD}
        support
        core
        irreader
        codegen
        mc
        mcjit
        mcparser
        asmparser
        option
        scalaropts
        transformutils
        objcarcopts 
        ExecutionEngine
        interpreter
        nativecodegen
    )
    set(llvm_libs ${llvm_libs} PARENT_SCOPE)
endfunction()

function(create_llvm_main_and_link)
    add_executable(Main main.cpp)
    include_llvm()
    auto_add_subdir()
    target_link_libraries(Main ${ARGN})
    target_link_libraries(Main ${llvm_libs})
endfunction()

