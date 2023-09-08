
#include <include_std.h>

#include "../And_/And_.h"
#include "../LexerCombinator/LexerCombinator.h"
#include "../Many/Many.h"
#include "../Token/Sequence/Sequence.h"

#include "UntilPeek.h"

using namespace std;

namespace LexerCombinatorUtil {

UntilPeek::UntilPeek(LexerCombinator *parserCombinator, LexerCombinator *until)
    : parserCombinator(parserCombinator), until(until) {}

Token::Sequence *UntilPeek::parsing(LexerCombinator &root,
                                    LexerCombinator &parent,
                                    std::string &text) {
  auto *sequence = new Token::Sequence;
  while (true) {
    auto cloneText = text;
    auto peek = until->parsing(root, *this, text);
    if (peek != nullptr) {
      sequence->add(peek);
      return sequence;
    } else {
      // Recover
      text.clear();
      text.append(cloneText);
    }
    auto ast = parserCombinator->parsing(root, *this, text);
    if (ast == nullptr) {
      return sequence;
    }
    sequence->add(ast);
  }

  return (new And({new Many(parserCombinator), until}))
      ->parsing(root, *this, text);
}

} // namespace LexerCombinatorUtil
