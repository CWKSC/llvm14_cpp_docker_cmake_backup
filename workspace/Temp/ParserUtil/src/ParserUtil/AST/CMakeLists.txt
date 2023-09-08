find_package(CMakeUtil)
create_interface_library(AST)

interface_library_link_object_with_project_prefix(
    AST

    Sequence
    Base

    Sequence
    Base
)

