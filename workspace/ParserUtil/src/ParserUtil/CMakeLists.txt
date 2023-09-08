cmake_minimum_required(VERSION 3.24)
project(ParserUtil)
find_package(CMakeUtil)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

create_library_root()

link_library_root(
    CommonCombinator # depends on Node
)

# link_library_root(
#     Node
# )

# link other library
find_package(ParserCombinatorUtil)
target_link_libraries(
    ParserUtil

    ParserCombinatorUtil
)

install_library(ParserUtil)


