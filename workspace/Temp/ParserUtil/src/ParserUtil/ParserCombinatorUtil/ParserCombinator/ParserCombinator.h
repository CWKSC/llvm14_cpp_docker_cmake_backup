#pragma once

#include <include_std.h>

#include "../../AST/Base/forward.h"
#include "../../Parser/forward.h"

namespace ParserUtil::ParserCombinatorUtil {

using ParsingFunc = std::function<ParserUtil::AST::Base *(
    ParserUtil::Parser &root, ParserUtil::Parser &parser,
    std::list<std::string> &tokenList)>;

struct ParserCombinatorBottomType {
  ParsingFunc parsingFunc;
};

template <typename... Args>
struct ParserCombinator : ParserCombinatorBottomType {
  ParserCombinator() {}
  ParserCombinator(const char *&stringValue) {}
  ParserCombinator(const std::string &stringValue) {}
  ParserCombinator(const ParsingFunc &parsingFunc)
      : ParserCombinatorBottomType{parsingFunc} {}

  static ParserCombinatorBottomType combine(Args... arg) {
    return ParserCombinatorBottomType();
  };
};

using ParserCombinator_listAsInput =
    ParserCombinator<std::vector<ParserCombinatorBottomType>>;

using ParserCombinator_parserCombinatorAsInput =
    ParserCombinator<ParserCombinatorBottomType>;

using ParserCombinator_stringAsInput = ParserCombinator<std::string>;

} // namespace ParserUtil::ParserCombinatorUtil
