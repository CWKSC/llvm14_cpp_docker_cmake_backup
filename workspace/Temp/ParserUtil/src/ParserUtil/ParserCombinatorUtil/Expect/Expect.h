#pragma once

#include <include_std.h>

#include "../ParserCombinator/ParserCombinator.h"

namespace ParserUtil::ParserCombinatorUtil {

struct Expect : ParserCombinator_stringAsInput {

  static ParserCombinatorBottomType combine(std::string expectString);
};

} // namespace ParserUtil::ParserCombinatorUtil
