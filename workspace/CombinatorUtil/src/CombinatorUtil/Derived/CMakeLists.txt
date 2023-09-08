find_package(CMakeUtil)
create_interface_library(Derived)


link_library_root(
    AroundMany # depends on And, Many, Until
)

link_library_root(
    Until # depends on And, Many
    OneOrMore # depends on Many
)

link_library_root(
    UntilPeek
    Or_
    And_
    Optional
    Many
    Empty
    Any
    Expect
    Ref
)

