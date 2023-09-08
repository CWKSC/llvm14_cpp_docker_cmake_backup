#pragma once

#include <include_std.h>

#include "../../ParserCombinatorUtil/ParserCombinator/ParserCombinator.h"

#include "../Base/Base.h"

namespace ParserUtil::AST {

struct Sequence : Base, ParserUtil::ParserCombinatorUtil::ParserCombinator<> {
  std::vector<Base *> astList;

  void add(Base *ast);

  static ParserUtil::ParserCombinatorUtil::ParserCombinator<> combine();
};

} // namespace ParserUtil::AST
