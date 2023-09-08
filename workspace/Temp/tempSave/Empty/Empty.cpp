
#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Token/Empty/Empty.h"

#include "Empty.h"

using namespace std;

namespace LexerCombinatorUtil {

Token::Empty *Empty::parsing(LexerCombinator &root, LexerCombinator &parent,
                             std::string &text) {
  return new Token::Empty;
}

} // namespace LexerCombinatorUtil
