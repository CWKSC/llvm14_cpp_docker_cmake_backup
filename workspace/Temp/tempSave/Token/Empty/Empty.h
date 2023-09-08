#pragma once

#include <include_std.h>

#include "../Base/Base.h"

namespace LexerCombinatorUtil::Token {

struct Empty : Base {
  void print() override;
};

} // namespace LexerCombinatorUtil::Token
