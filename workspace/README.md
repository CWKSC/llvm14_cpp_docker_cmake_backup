# README 

Run `install.sh` when first time to start the container

```
Library:
  - RegexUtil
  - InputterUtil
  - ListTreeUtil
  - CombinatorUtil
  - SemanticUtil
  - TransformerUtil
  - LexerUtil
  - LexerCombinatorUtil
  - LexerSemanticUtil
  - ParserUtil
  - ParserCombinatorUtil
  - ParserSemanticUtil
  - LLVMIRUtil
  - TypeCheckerUtil
  - CodeGeneratorUtil

Implementation:
  - MetaLexer
  - MetaParser
  - Lexer
  - Parser
  - TypeChecker
  - CodeGenerator 
  - MetaCompiler

Flow:
Input               -> Syntax Definition Text
MetaLexer           -> Tree
MetaLexer_Semantic  -> Text List
MetaParser          -> Tree
MetaParser_Semantic -> AST

Input               -> Language Text
Lexer               -> Tree
Lexer_Semantic      -> Text List
Parser              -> Tree
Parser_Semantic     -> AST

TypeChecker         -> AST
CodeGen             -> IR / Object / Executable
```

# Convention

Use reference `&` in function parameter

Use pointer `*` in return value and constructor

No need to free memory

## CMake 

### For install confid cmake file template 

```cmake
add_subdirectory($ENV{/* LibraryName */_Path} EXCLUDE_FROM_ALL /* LibraryName */_binary_dir)
```
