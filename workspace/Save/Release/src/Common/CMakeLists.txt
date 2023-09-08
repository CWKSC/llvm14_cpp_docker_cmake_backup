add_library(Common dummy.cpp)

add_subdirectory(AST)
add_subdirectory(Parsing)
add_subdirectory(Token)
add_subdirectory(RegexMatching)

target_link_libraries(
    Common 
    Token
    RegexMatching

    AST # before Parsing
    Parsing
)

