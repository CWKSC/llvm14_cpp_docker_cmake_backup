#pragma once

#include <include_std.h>

#include "../../../Token/Base/Base.h"
#include "../../../Token/PureToken/PureToken.h"

namespace LexerCombinatorUtil::Token {

struct Space : Base {
  std::string spaceString;
  Space(PureToken *pureToken);
  void print() override;
};

} // namespace LexerCombinatorUtil::Token
