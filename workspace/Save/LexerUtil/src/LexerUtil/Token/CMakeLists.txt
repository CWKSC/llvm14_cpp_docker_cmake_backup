find_package(CMakeUtil)
create_interface_library(Token)

interface_library_link_object_with_project_prefix(
    Token

    Base
)

