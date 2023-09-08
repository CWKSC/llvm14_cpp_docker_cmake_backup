find_package(CMakeUtil)
create_interface_library(CommonCombinator)

interface_library_link(
    Bracket
    Comma
    Space
    NextLine
    LineComment
    Identifier
)

interface_library_link_interface(
    LiteralUtil
)

interface_library_link_interface(
    Token
)
