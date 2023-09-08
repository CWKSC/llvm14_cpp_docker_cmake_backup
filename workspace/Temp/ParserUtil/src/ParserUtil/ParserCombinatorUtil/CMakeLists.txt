find_package(CMakeUtil)
create_interface_library(ParserCombinatorUtil)

interface_library_link_object_with_project_prefix(
    ParserCombinatorUtil

    And_
    Or_
    Optional
    AtLeastOne
    Expect
    Many
    ParserCombinator

    And_
    Or_
    Optional
    AtLeastOne
    Expect
    Many
    ParserCombinator
)
