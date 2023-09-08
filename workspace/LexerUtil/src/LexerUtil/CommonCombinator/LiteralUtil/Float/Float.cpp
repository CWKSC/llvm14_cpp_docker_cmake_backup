#include <CombinatorUtil/include.h>
#include <LexerCombinatorUtil/include.h>
#include <include_std.h>

#include "Float.h"

using namespace CombinatorUtil;
using namespace LexerCombinatorUtil;

namespace LexerUtil {

ListTreeUtil::Node *Float::lexing(CombinatorUtil::Combinator &root,
                                  CombinatorUtil::Combinator &parent,
                                  ListTreeUtil::String &text) {
  return (new RegexExpect("[+-]?\\d*\\.\\d*"))->lexing(root, *this, text);
}

} // namespace LexerUtil