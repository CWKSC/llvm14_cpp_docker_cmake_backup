#pragma once

#include <include_std.h>

#include "../AST/Base/forward.h"
#include "../Parser/forward.h"

/// ParsingFunc ///
using ParsingFuncReturn = ParserUtil::AST::Base *;
#define ParsingFuncArguments                                                   \
  ParserUtil::Parser &root, ParserUtil::Parser &parser,                        \
      std::list<std::string> &tokenList
#define DeclareParsingFunc(name) ParsingFuncReturn name(ParsingFuncArguments)
#define DefineParsingFunc(name) DeclareParsingFunc(name)

/// Declare Parser Combinator ///
#define ParserCombinatorListArgument                                           \
  std::vector<ParserUtil::ParserCombinatorUtil::ParserCombinator>              \
      parsingFuncList
#define ParserCombinatorFuncArgument                                           \
  std::function<DefineParsingFunc()> parsingFunc

#define DeclareParserCombinator(name, ...)                                     \
  ParserUtil::ParserCombinatorUtil::ParserCombinator name(__VA_ARGS__)
#define DeclareParserCombinator_listAsInput(name)                              \
  DeclareParserCombinator(name, ParserCombinatorListArgument)
#define DeclareParserCombinator_funcAsInput(name)                              \
  DeclareParserCombinator(name, ParserCombinatorFuncArgument)

/// Define Parser Combinator ///
#define ReturnParsingFuncLambda [=](ParsingFuncArguments)
#define DefineParserCombinator(name, ...)                                      \
  DeclareParserCombinator(name, __VA_ARGS__) {                                 \
    return ReturnParsingFuncLambda
#define DefineParserCombinator_end                                             \
  ;                                                                            \
  }
#define DefineParserCombinator_listAsInput(name, ...)                          \
  DefineParserCombinator(name, ParserCombinatorListArgument)
#define DefineParserCombinator_funcAsInput(name, ...)                          \
  DefineParserCombinator(name, ParserCombinatorFuncArgument)

namespace ParserUtil::ParserCombinatorUtil {

using ParserCombinator = std::function<DefineParsingFunc()>;

DeclareParserCombinator_listAsInput(and_);
DeclareParserCombinator_listAsInput(or_);

DeclareParserCombinator_funcAsInput(option);
DeclareParserCombinator_funcAsInput(many);
DeclareParserCombinator_funcAsInput(atLeastOne);

} // namespace ParserUtil::ParserCombinatorUtil
