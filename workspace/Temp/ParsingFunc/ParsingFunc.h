#pragma once

#include <include_std.h>

#include "../ParserCombinatorUtil/ParserCombinatorUtil.h"

namespace ParserUtil::ParsingFunc {

DeclareParserCombinator(expect, std::string expectToken);

} // namespace ParserUtil::ParsingFunc