cmake_minimum_required(VERSION 3.16.3)
project(Compiler)

# set(CMAKE_CXX_COMPILER "clang++-14")
# set(CMAKE_CXX_FLAGS "-stdlib=libc++")
# set(CMAKE_EXE_LINKER_FLAGS "-stdlib=libc++")

# set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} main.cpp)


### LLVM https://llvm.org/docs/CMake.html#embedding-llvm-in-your-project
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
llvm_map_components_to_libnames(llvm_libs ${LLVM_TARGETS_TO_BUILD} support core irreader codegen mc mcparser option)


add_subdirectory(Common)
add_subdirectory(Lexer)
add_subdirectory(Tagger)
add_subdirectory(Parser)
add_subdirectory(CodeGenerator)
add_subdirectory(IRToObjectFileConverter)

target_link_libraries(
    ${PROJECT_NAME}
    
    IRToObjectFileConverter
    CodeGenerator
    Parser
    Tagger
    Lexer
    Common
    ${llvm_libs}
)

