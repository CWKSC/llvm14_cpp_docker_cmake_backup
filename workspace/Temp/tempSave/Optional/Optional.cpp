
#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Token/Base/Base.h"
#include "../Token/Null/Null.h"

#include "Optional.h"

using namespace std;

namespace LexerCombinatorUtil {

Optional::Optional(LexerCombinator *parserCombinator)
    : parserCombinator(parserCombinator) {}

Token::Base *Optional::parsing(LexerCombinator &root, LexerCombinator &parent,
                               std::string &text) {
  auto ast = parserCombinator->parsing(root, *this, text);
  if (ast == nullptr) {
    return (Token::Base *)new Token::Null;
  }
  return (Token::Base *)ast;
}

} // namespace LexerCombinatorUtil
