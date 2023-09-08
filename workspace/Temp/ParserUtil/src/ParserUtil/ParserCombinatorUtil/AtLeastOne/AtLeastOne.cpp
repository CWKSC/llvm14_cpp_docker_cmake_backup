
#include <include_std.h>

#include "../../AST/Sequence/Sequence.h"

#include "../Many/Many.h"

#include "AtLeastOne.h"

using namespace std;
using namespace ParserUtil;
using namespace ParserUtil::AST;

namespace ParserUtil::ParserCombinatorUtil {

ParserCombinatorBottomType
AtLeastOne::combine(ParserCombinatorBottomType parserCombinator) {

  return ParserCombinator([=](Parser &root, Parser &parser,
                              list<string> &tokenList) {
    auto *sequence = new Sequence;
    auto ast = parserCombinator.parsingFunc(root, parser, tokenList);
    if (ast == nullptr) {
      return (Sequence *)nullptr;
    }
    auto astList =
        Many::combine(parserCombinator).parsingFunc(root, parser, tokenList);
    sequence->add(astList);
    return sequence;
  });
}

} // namespace ParserUtil::ParserCombinatorUtil
