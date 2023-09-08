
#include <include_std.h>

#include "../AST/Base/Base.h"
#include "../ParserCombinatorUtil/ParserCombinatorUtil.h"

using namespace std;
using namespace ParserUtil::AST;

namespace ParserUtil::ParsingFunc {

DefineParserCombinator(expect, std::string expectToken) {
  auto front = tokenList.front();
  if (expectToken != front) {
    std::cout << "except " << expectToken << " false" << std::endl;
    return (Base *)nullptr;
  }
  std::cout << "except " << expectToken << std::endl;
  tokenList.pop_front();
  return new Base;
}
DefineParserCombinator_end

} // namespace ParserUtil::ParsingFunc
