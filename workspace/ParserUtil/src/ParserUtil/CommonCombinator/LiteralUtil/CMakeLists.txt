find_package(CMakeUtil)
create_interface_library(LiteralUtil)

interface_library_link(
    Literal
)

interface_library_link(
    Integer
    Float
    String_
)

