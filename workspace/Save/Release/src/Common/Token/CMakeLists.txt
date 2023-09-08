add_library(Token dummy.cpp)

add_subdirectory(BaseToken)
add_subdirectory(TaggedToken)

target_link_libraries(
    Token 
    TaggedToken
    BaseToken
)

