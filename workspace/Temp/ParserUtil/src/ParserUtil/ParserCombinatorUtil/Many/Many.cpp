
#include <include_std.h>

#include "../../AST/Sequence/Sequence.h"

#include "../ParserCombinator/ParserCombinator.h"

#include "Many.h"

using namespace std;
using namespace ParserUtil;
using namespace ParserUtil::AST;

namespace ParserUtil::ParserCombinatorUtil {

ParserCombinatorBottomType
Many::combine(ParserCombinatorBottomType parserCombinator) {

  return ParserCombinator(
      [=](Parser &root, Parser &parser, list<string> &tokenList) {
        auto *sequence = new Sequence;
        while (true) {
          auto ast = parserCombinator.parsingFunc(root, parser, tokenList);
          if (ast == nullptr) {
            return sequence;
          }
          sequence->add(ast);
        }
      });
}

} // namespace ParserUtil::ParserCombinatorUtil
