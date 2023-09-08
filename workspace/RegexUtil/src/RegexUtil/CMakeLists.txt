cmake_minimum_required(VERSION 3.24)
project(RegexUtil)
find_package(CMakeUtil)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

create_library_root()

link_library_root(
    MultiSearch
    SingleSearch
)

link_library_root(
    Structure
    GlobalCache
)

install_library(RegexUtil)

