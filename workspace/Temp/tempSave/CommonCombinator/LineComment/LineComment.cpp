#include <include_std.h>

#include "../../And_/And_.h"
#include "../../Expect/Expect.h"
#include "../../LexerCombinator/LexerCombinator.h"
#include "../../RegexExpect/RegexExpect.h"

#include "LineComment.h"

namespace LexerCombinatorUtil {

LineComment::LineComment(std::string startString) : startString(startString) {}

Token::Base *LineComment::parsing(LexerCombinator &root,
                                  LexerCombinator &parent, std::string &text) {
  return (new And({new Expect(startString), new RegexExpect(".*\n")}))
      ->parsing(root, *this, text);
}

} // namespace LexerCombinatorUtil