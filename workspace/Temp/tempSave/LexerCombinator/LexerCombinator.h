#pragma once
#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../Token/Base/Base.h"

namespace LexerCombinatorUtil {

struct LexerCombinator : CombinatorUtil::Combinator {
  ListTreeUtil::Node *parsing(Combinator &root, Combinator &parent,
                              ListTreeUtil::List &list) override;
  virtual ListTreeUtil::Node *lexing(Combinator &root, Combinator &parent,
                                     std::string &text) = 0;
};

} // namespace LexerCombinatorUtil