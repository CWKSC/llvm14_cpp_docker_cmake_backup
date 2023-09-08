
#include <include_std.h>

#include "../And_/And_.h"
#include "../LexerCombinator/LexerCombinator.h"
#include "../Many/Many.h"
#include "../Token/Sequence/Sequence.h"

#include "Until.h"

using namespace std;

namespace LexerCombinatorUtil {

Until::Until(LexerCombinator *parserCombinator, LexerCombinator *until)
    : parserCombinator(parserCombinator), until(until) {}

Token::Sequence *Until::parsing(LexerCombinator &root, LexerCombinator &parent,
                                std::string &text) {
  return (new And({new Many(parserCombinator), until}))
      ->parsing(root, *this, text);
}

} // namespace LexerCombinatorUtil
