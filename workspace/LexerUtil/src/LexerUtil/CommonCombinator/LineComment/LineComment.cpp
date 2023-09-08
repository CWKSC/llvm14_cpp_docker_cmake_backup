#include <CombinatorUtil/include.h>
#include <LexerCombinatorUtil/include.h>
#include <include_std.h>

#include "LineComment.h"

using namespace CombinatorUtil;
using namespace LexerCombinatorUtil;

namespace LexerUtil {
using LexerCombinatorUtil::Expect;

LineComment::LineComment(std::string startString) : startString(startString) {}

ListTreeUtil::Node *LineComment::lexing(CombinatorUtil::Combinator &root,
                                        CombinatorUtil::Combinator &parent,
                                        ListTreeUtil::String &text) {
  return (new And({new Expect(startString), new RegexExpect(".*\n")}))
      ->parsing(root, *this, text);
}

} // namespace LexerUtil