#pragma once

#include <include_std.h>

#include "../ParserCombinator/ParserCombinator.h"

namespace ParserUtil::ParserCombinatorUtil {

struct And : ParserCombinator_listAsInput {

  static ParserCombinatorBottomType
  combine(std::vector<ParserCombinatorBottomType> parsingFuncList);
};

} // namespace ParserUtil::ParserCombinatorUtil
