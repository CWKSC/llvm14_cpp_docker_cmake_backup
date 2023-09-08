find_package(CMakeUtil)
create_interface_library(Derived)

link_library_root(
    Expect
    RegexExpect
    Any
)

