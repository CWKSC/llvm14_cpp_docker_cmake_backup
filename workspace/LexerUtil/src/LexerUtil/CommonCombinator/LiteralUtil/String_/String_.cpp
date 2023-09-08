#include <CombinatorUtil/include.h>
#include <LexerCombinatorUtil/include.h>
#include <include_std.h>

#include "String_.h"

using namespace CombinatorUtil;
using namespace LexerCombinatorUtil;

namespace LexerUtil {

ListTreeUtil::Node *String::lexing(CombinatorUtil::Combinator &root,
                                   CombinatorUtil::Combinator &parent,
                                   ListTreeUtil::String &text) {
  return (new RegexExpect("\\\"(\\\\.|[^\"\\\\])*\\\""))
      ->lexing(root, *this, text);
}

} // namespace LexerUtil
