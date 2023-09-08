
#include "../../LexerCombinator/LexerCombinator.h"
#include "../../RegexExpect/RegexExpect.h"

#include "../Token/Space/Space.h"

#include "Space.h"

namespace LexerCombinatorUtil {

Token::Space *Space::parsing(LexerCombinator &root, LexerCombinator &parent,
                             std::string &text) {
  auto pureToken = (new RegexExpect(" +"))->parsing(root, *this, text);
  if (pureToken == nullptr)
    return nullptr;
  return new Token::Space(pureToken);
}

} // namespace LexerCombinatorUtil