cmake_minimum_required(VERSION 3.24)
project(MetaCompiler)
find_package(CMakeUtil)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ParserCombinatorUtil)
create_main_and_link(
    ParserCombinatorUtil
)
