
#include <include_std.h>

#include "../../Parser/Parser.h"
#include "../../ParserCombinatorUtil/Expect/Expect.h"
#include "../../ParserCombinatorUtil/ParserCombinator/ParserCombinator.h"

#include "../Base/forward.h"

#include "Sequence.h"

using namespace std;
using namespace ParserUtil;
using namespace ParserUtil::AST;
using namespace ParserUtil::ParserCombinatorUtil;

namespace ParserUtil::AST {

void Sequence::add(Base *ast) { astList.push_back(ast); }

ParserCombinator<> Sequence::combine() {
  return ParserCombinator([](Parser &root, Parser &parser,
                             list<string> &tokenList) {
    auto *sequence = new Sequence;
    if (Expect::combine("(").parsingFunc(root, parser, tokenList) == nullptr)
      return (Sequence *)nullptr;
    while (tokenList.front() != ")") {
      auto ast = parser.parsing(tokenList);
      sequence->add(ast);
    }
    if (Expect::combine(")").parsingFunc(root, parser, tokenList) == nullptr)
      return (Sequence *)nullptr;
    return sequence;
  });
}

} // namespace ParserUtil::AST