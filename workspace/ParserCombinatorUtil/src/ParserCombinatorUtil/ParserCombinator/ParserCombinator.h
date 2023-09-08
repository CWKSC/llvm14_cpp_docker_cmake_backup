#pragma once
#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <include_std.h>

namespace ParserCombinatorUtil {

struct ParserCombinator : CombinatorUtil::Combinator {
  virtual ListTreeUtil::Node *parsing(CombinatorUtil::Combinator &root,
                                      CombinatorUtil::Combinator &parent,
                                      ListTreeUtil::StringList &list) = 0;

private:
  ListTreeUtil::Node *parsing(CombinatorUtil::Combinator &root,
                              CombinatorUtil::Combinator &parent,
                              ListTreeUtil::IList &list) override;
};

} // namespace ParserCombinatorUtil