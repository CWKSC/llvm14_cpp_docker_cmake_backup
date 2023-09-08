
#include <include_std.h>

#include "../ParserCombinatorUtil/And_/And_.h"
#include "../ParserCombinatorUtil/Or_/Or_.h"
#include "../ParserCombinatorUtil/ParserCombinator/ParserCombinator.h"

#include "Parser.h"

using namespace std;
using namespace ParserUtil::ParserCombinatorUtil;
using namespace ParserUtil::AST;

namespace ParserUtil {

Parser::Parser() : root(this) {}

Parser::Parser(Parser &parser)
    : root(parser.root), rules(parser.rules), memory(parser.memory) {}

void Parser::addRule(vector<ParserCombinatorBottomType> parserCombinatorList) {
  rules.push_back(parserCombinatorList);
}

Base *Parser::parsing(list<string> &tokenList) {
  vector<ParserCombinatorBottomType> row;
  for (const auto &rule : rules) {
    row.push_back(And::combine(rule));
  }
  return Or::combine(row).parsingFunc(*this, *this, tokenList);
}

} // namespace ParserUtil