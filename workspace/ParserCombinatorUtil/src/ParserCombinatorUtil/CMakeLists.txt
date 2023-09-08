cmake_minimum_required(VERSION 3.24)
project(ParserCombinatorUtil)
find_package(CMakeUtil)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

create_library_root()

link_library_root(
    Derived
)

# all other depends on this
link_library_root(
    ParserCombinator
)

# Link other library
find_package(CombinatorUtil)
find_package(RegexUtil)
target_link_libraries(
    ParserCombinatorUtil
    
    RegexUtil
    CombinatorUtil
)

install_library(ParserCombinatorUtil)


