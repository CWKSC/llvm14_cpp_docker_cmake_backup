
#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Token/Sequence/Sequence.h"

#include "And_.h"

using namespace std;

namespace LexerCombinatorUtil {

And::And(std::vector<LexerCombinator *> parserCombinatorList)
    : parserCombinatorList(parserCombinatorList) {}

Token::Sequence *And::parsing(LexerCombinator &root, LexerCombinator &parent,
                              std::string &text) {
  auto *sequence = new Token::Sequence;
  for (auto parserCombinator : parserCombinatorList) {
    auto ast = parserCombinator->parsing(root, *this, text);
    if (ast != nullptr) {
      sequence->add(ast);
    } else {
      return nullptr;
    }
  }
  return sequence;
}

} // namespace LexerCombinatorUtil
