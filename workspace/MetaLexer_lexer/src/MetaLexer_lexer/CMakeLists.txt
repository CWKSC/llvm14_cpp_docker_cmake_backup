cmake_minimum_required(VERSION 3.24)
project(MetaLexer_lexer)
find_package(CMakeUtil)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

create_library_root()

link_library_root(

)

# link other library
find_package(LexerUtil)
target_link_libraries(
    MetaLexer_lexer

    LexerUtil
)

install_library(MetaLexer_lexer)

