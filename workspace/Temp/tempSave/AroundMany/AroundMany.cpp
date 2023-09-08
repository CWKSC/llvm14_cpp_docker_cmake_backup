
#include <include_std.h>

#include "../And_/And_.h"
#include "../LexerCombinator/LexerCombinator.h"
#include "../Many/Many.h"
#include "../Token/Sequence/Sequence.h"
#include "../Until/Until.h"

#include "AroundMany.h"

using namespace std;

namespace LexerCombinatorUtil {

AroundMany::AroundMany(LexerCombinator *before,
                       LexerCombinator *parserCombinator,
                       LexerCombinator *after)
    : before(before), parserCombinator(parserCombinator), after(after) {}

Token::Sequence *AroundMany::parsing(LexerCombinator &root,
                                     LexerCombinator &parent,
                                     std::string &text) {
  return (new And({before, new Until(parserCombinator, after)}))
      ->parsing(root, *this, text);
}

} // namespace LexerCombinatorUtil
