cmake_minimum_required(VERSION 3.24)
project(LexerCombinatorUtil)
find_package(CMakeUtil)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

create_library_root()

link_library_root(
    Derived
)

# All other depends on this
link_library_root(
    LexerCombinator
)

# Link other library
find_package(RegexUtil)
find_package(CombinatorUtil)
target_link_libraries(
    LexerCombinatorUtil
    
    CombinatorUtil
    RegexUtil
)

install_library(LexerCombinatorUtil)


