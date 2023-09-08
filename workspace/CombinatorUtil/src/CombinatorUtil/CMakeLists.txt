cmake_minimum_required(VERSION 3.24)
project(CombinatorUtil)
find_package(CMakeUtil)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

create_library_root()

link_library_root(
    Derived
)

# All other depends on this
link_library_root(
    Combinator 
    Node
)

# Link other library
find_package(ListTreeUtil)
target_link_libraries(
    CombinatorUtil
    
    ListTreeUtil
)

install_library(CombinatorUtil)


