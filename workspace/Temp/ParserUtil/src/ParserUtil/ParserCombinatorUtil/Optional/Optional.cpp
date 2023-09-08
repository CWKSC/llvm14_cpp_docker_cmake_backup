
#include <include_std.h>

#include "../../AST/Base/Base.h"

#include "Optional.h"

using namespace std;
using namespace ParserUtil;
using namespace ParserUtil::AST;

namespace ParserUtil::ParserCombinatorUtil {

ParserCombinatorBottomType
Optional::combine(ParserCombinatorBottomType parserCombinator) {

  return ParserCombinator(
      [=](Parser &root, Parser &parser, list<string> &tokenList) {
        auto ast = parserCombinator.parsingFunc(root, parser, tokenList);
        if (ast == nullptr) {
          return (Base *)nullptr;
        }
        return ast;
      });
}

} // namespace ParserUtil::ParserCombinatorUtil
