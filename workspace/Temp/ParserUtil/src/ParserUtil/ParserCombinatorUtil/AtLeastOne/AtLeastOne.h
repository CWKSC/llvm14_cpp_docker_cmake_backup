#pragma once

#include <include_std.h>

#include "../ParserCombinator/ParserCombinator.h"

namespace ParserUtil::ParserCombinatorUtil {

struct AtLeastOne : ParserCombinator_parserCombinatorAsInput {

  static ParserCombinatorBottomType
  combine(ParserCombinatorBottomType parserCombinator);
};

} // namespace ParserUtil::ParserCombinatorUtil
