#pragma once

#include <include_std.h>

#include "../Base/Base.h"

namespace LexerCombinatorUtil::Token {

struct PureToken : Base {
  std::string token;
  PureToken(std::string token);
  void print() override;
};

} // namespace LexerCombinatorUtil::Token
