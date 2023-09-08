add_library(AST dummy.cpp)

add_subdirectory(Extern)
add_subdirectory(Func)
add_subdirectory(Group)
add_subdirectory(Main)
add_subdirectory(Node)
add_subdirectory(NotMatch)
add_subdirectory(Prototype)
add_subdirectory(Variable)
add_subdirectory(BinaryOperator)
add_subdirectory(Float)
add_subdirectory(Callee)
add_subdirectory(If)
add_subdirectory(Integer)
add_subdirectory(For)

target_link_libraries(
    AST

    For
    Integer
    If
    Float
    BinaryOperator
    Main
    Func
    Prototype
    Extern

    Group
    Node
    NotMatch
    Callee
    Variable
)
