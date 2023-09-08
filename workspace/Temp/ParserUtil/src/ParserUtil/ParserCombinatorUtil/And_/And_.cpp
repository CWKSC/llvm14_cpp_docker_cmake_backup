
#include <include_std.h>

#include "../../AST/Sequence/Sequence.h"

#include "../ParserCombinator/ParserCombinator.h"

#include "And_.h"

using namespace std;
using namespace ParserUtil;
using namespace ParserUtil::AST;

namespace ParserUtil::ParserCombinatorUtil {

ParserCombinatorBottomType
And::combine(vector<ParserCombinatorBottomType> parsingFuncList) {

  return ParserCombinator(
      [=](Parser &root, Parser &parser, list<string> &tokenList) {
        auto *sequence = new Sequence;
        for (const auto &func : parsingFuncList) {
          auto ast = func.parsingFunc(root, parser, tokenList);
          if (ast != nullptr) {
            sequence->add(ast);
          } else {
            return (Sequence *)nullptr;
          }
        }
        return sequence;
      });
}

} // namespace ParserUtil::ParserCombinatorUtil
