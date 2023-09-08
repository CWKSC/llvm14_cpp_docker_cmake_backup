project(ParserUtil)
find_package(CMakeUtil)
create_dummy_library(ParserUtil STATIC)

target_link_libraries_with_project_prefix(
    ParserUtil

    Parser
    AST
    ParserCombinatorUtil
)

install_library(ParserUtil)


