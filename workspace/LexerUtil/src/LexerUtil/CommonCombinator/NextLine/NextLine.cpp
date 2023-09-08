#include <CombinatorUtil/include.h>
#include <LexerCombinatorUtil/include.h>
#include <include_std.h>

#include "NextLine.h"

using namespace CombinatorUtil;
using namespace LexerCombinatorUtil;

namespace LexerUtil {
using LexerCombinatorUtil::Expect;

ListTreeUtil::Node *NextLine::lexing(CombinatorUtil::Combinator &root,
                                     CombinatorUtil::Combinator &parent,
                                     ListTreeUtil::String &text) {
  return (new Expect("\n"))->lexing(root, *this, text);
}

} // namespace LexerUtil
