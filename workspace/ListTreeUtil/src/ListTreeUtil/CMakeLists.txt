cmake_minimum_required(VERSION 3.24)
project(ListTreeUtil)
find_package(CMakeUtil)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

create_library_root()

# depends on all other
link_library_root(
    Derived
)

link_library_root(
    IList
)

# All other depends on this
link_library_root(
    Node
)

install_library(ListTreeUtil)


