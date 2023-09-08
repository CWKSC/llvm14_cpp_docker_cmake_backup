
#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Many/Many.h"
#include "../Token/Sequence/Sequence.h"

#include "AtLeastOne.h"

using namespace std;

namespace LexerCombinatorUtil {

AtLeastOne::AtLeastOne(LexerCombinator *parserCombinator)
    : parserCombinator(parserCombinator), LexerCombinator() {}

Token::Sequence *AtLeastOne::parsing(LexerCombinator &root,
                                     LexerCombinator &parent,
                                     std::string &text) {
  auto *sequence = new Token::Sequence;
  auto ast = parserCombinator->parsing(root, *this, text);
  if (ast == nullptr) {
    return nullptr;
  }
  sequence->add(ast);
  auto astList = Many(parserCombinator).parsing(root, *this, text);
  sequence->add(astList);
  return sequence;
}

} // namespace LexerCombinatorUtil
