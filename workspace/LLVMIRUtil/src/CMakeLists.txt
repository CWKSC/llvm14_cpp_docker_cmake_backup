cmake_minimum_required(VERSION 3.24)
project(LLVMUtil)
find_package(CMakeUtil)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

create_llvm_main_and_link(
    LLVMIRUtil
)





