cmake_minimum_required(VERSION 3.24)
project(LexerUtil)
find_package(CMakeUtil)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

create_library_root()

link_library_root(
    Lexer
)

library_link(
    
)

# link other library
find_package(LexerCombinatorUtil)
target_link_libraries(
    LexerUtil

    LexerCombinatorUtil
)

install_library(LexerUtil)


