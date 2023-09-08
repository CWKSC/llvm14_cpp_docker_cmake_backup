project(LexerUtil)
find_package(CMakeUtil)
create_dummy_library(LexerUtil STATIC)

find_package(RegexUtil)

target_link_libraries_with_project_prefix(
    LexerUtil

    Lexer
    LexingRule
    Token
)
target_link_libraries(
    LexerUtil
    RegexUtil
)

install_library(LexerUtil)


