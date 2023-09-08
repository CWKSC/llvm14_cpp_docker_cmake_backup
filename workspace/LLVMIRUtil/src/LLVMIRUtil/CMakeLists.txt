cmake_minimum_required(VERSION 3.24)
project(LLVMIRUtil)
find_package(CMakeUtil)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

create_library_root()

link_library_root(
    Example
    Template
)

link_library_root(
    WhileUtil # depends on ConstantUtil, FunctionUtil, TypeUtil
)

link_library_root(
    ConstantUtil # depends on GlobalVariableUtil, TypeUtil
    MainUtil # depends on FunctionUtil
)

link_library_root(
    InstructionUtil
    BasicBlockUtil
    GlobalVariableUtil
    ConstantUtil
    ExternUtil
    FunctionUtil
    TypeUtil
)

install_library(LLVMIRUtil)

