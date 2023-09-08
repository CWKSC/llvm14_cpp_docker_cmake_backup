
#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Token/Base/Base.h"

#include "Or_.h"

using namespace std;

namespace LexerCombinatorUtil {

Or::Or(vector<LexerCombinator *> parserCombinatorList)
    : parserCombinatorList(parserCombinatorList) {}

Token::Base *Or::parsing(LexerCombinator &root, LexerCombinator &parent,
                         std::string &text) {
  for (auto &parserCombinator : parserCombinatorList) {
    auto cloneTokenList = string(text);
    auto ast = parserCombinator->parsing(root, *this, cloneTokenList);
    if (ast != nullptr) {
      text.clear();
      text.insert(text.end(), cloneTokenList.begin(), cloneTokenList.end());
      return ast;
    }
  }
  return nullptr;
}

} // namespace LexerCombinatorUtil
