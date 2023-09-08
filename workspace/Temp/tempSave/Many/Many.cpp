
#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Token/Sequence/Sequence.h"

#include "Many.h"

using namespace std;

namespace LexerCombinatorUtil {

Many::Many(LexerCombinator *parserCombinator)
    : parserCombinator(parserCombinator), LexerCombinator() {}

Token::Sequence *Many::parsing(LexerCombinator &root, LexerCombinator &parent,
                               std::string &text) {
  auto *sequence = new Token::Sequence;
  while (true) {
    auto ast = parserCombinator->parsing(root, *this, text);
    if (ast == nullptr) {
      return sequence;
    }
    sequence->add(ast);
  }
}

} // namespace LexerCombinatorUtil
