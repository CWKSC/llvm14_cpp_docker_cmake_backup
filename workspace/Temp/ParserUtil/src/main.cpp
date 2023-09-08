
#include <include_std.h>

#include "ParserUtil/include.h"

using namespace std;
using namespace ParserUtil;
using namespace ParserUtil::AST;
using namespace ParserUtil::ParserCombinatorUtil;

int main() {

  std::list<std::string> tokenList = {"(", "(", ")", "(", "(", ")", ")", ")"};

  auto parserCombinator = Or::combine({Sequence::combine()});
  auto parser = ParserUtil::Parser();
  // parser.addRule({Sequence::parsing()});

  auto ast = parserCombinator.parsingFunc(parser, parser, tokenList);
  // std::cout << ast << std::endl;

  return 0;
}
