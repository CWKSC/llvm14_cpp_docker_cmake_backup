
#include <include_std.h>

#include "../../AST/Base/Base.h"

#include "Expect.h"

using namespace std;
using namespace ParserUtil;
using namespace ParserUtil::AST;

namespace ParserUtil::ParserCombinatorUtil {

ParserCombinatorBottomType Expect::combine(std::string expectToken) {
  return ParserCombinator(
      [=](Parser &root, Parser &parser, list<string> &tokenList) {
        auto front = tokenList.front();
        if (expectToken != front) {
          std::cout << "except " << expectToken << " false" << std::endl;
          return (Base *)nullptr;
        }
        std::cout << "except " << expectToken << std::endl;
        tokenList.pop_front();
        return new Base;
      });
}

} // namespace ParserUtil::ParserCombinatorUtil
