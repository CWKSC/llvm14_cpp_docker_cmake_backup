find_package(CMakeUtil)
create_interface_library(Token)

interface_library_link(
    PureToken
    Null
    Sequence
)

interface_library_link(
    Base
)

