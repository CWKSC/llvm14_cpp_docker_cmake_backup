
#include <CombinatorUtil/include.h>
#include <LexerCombinatorUtil/include.h>
#include <include_std.h>

#include "Identifier.h"

using namespace CombinatorUtil;
using namespace LexerCombinatorUtil;

namespace LexerUtil {
using LexerCombinatorUtil::Expect;

ListTreeUtil::Node *Identifier::lexing(CombinatorUtil::Combinator &root,
                                       CombinatorUtil::Combinator &parent,
                                       ListTreeUtil::String &text) {
  return (new RegexExpect("\\w\\w*"))->lexing(root, *this, text);
}

} // namespace LexerUtil
