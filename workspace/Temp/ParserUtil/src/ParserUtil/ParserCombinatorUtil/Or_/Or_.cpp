
#include <include_std.h>

#include "../../AST/Base/Base.h"

#include "Or_.h"

using namespace std;
using namespace ParserUtil;
using namespace ParserUtil::AST;

namespace ParserUtil::ParserCombinatorUtil {

ParserCombinatorBottomType
Or::combine(vector<ParserCombinatorBottomType> parsingFuncList) {

  return ParserCombinator(
      [=](Parser &root, Parser &parser, list<string> &tokenList) {
        for (const auto &func : parsingFuncList) {
          auto cloneTokenList = list<string>(tokenList);
          auto ast = func.parsingFunc(root, parser, cloneTokenList);
          if (ast != nullptr) {
            tokenList.clear();
            tokenList.insert(tokenList.end(), cloneTokenList.begin(),
                             cloneTokenList.end());
            return ast;
          }
        }
        return (Base *)nullptr;
      });
}

} // namespace ParserUtil::ParserCombinatorUtil
