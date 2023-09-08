cmake_minimum_required(VERSION 3.16.3)
project(LexerUtil)

find_package(CMakeUtil)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

create_library_main()

target_link_libraries(
    ${PROJECT_NAME}Main

    LexerUtil
)






