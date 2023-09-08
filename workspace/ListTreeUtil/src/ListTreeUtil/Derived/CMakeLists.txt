find_package(CMakeUtil)
create_interface_library(Derived)

interface_library_link(
    StringList # depends on String_
)

interface_library_link(
    String_ # depends on Char
)

interface_library_link(
    Char
    List_
    Null
)

