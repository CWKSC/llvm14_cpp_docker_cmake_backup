#pragma once
#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <include_std.h>

namespace LexerCombinatorUtil {

struct LexerCombinator : CombinatorUtil::Combinator {
  virtual ListTreeUtil::Node *lexing(CombinatorUtil::Combinator &root,
                                     CombinatorUtil::Combinator &parent,
                                     ListTreeUtil::String &text) = 0;

private:
  ListTreeUtil::Node *parsing(CombinatorUtil::Combinator &root,
                              CombinatorUtil::Combinator &parent,
                              ListTreeUtil::IList &list) override;
};

} // namespace LexerCombinatorUtil