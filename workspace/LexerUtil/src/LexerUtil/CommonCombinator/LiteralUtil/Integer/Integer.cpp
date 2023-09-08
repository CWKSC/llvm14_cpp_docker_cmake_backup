#include <CombinatorUtil/include.h>
#include <LexerCombinatorUtil/include.h>
#include <include_std.h>

#include "Integer.h"

using namespace CombinatorUtil;
using namespace LexerCombinatorUtil;

namespace LexerUtil {

ListTreeUtil::Node *Integer::lexing(CombinatorUtil::Combinator &root,
                                    CombinatorUtil::Combinator &parent,
                                    ListTreeUtil::String &text) {
  return (new RegexExpect("[+-]?\\d+"))->lexing(root, *this, text);
}

} // namespace LexerUtil