

#include <iostream>
#include <string>

#include "../../../Parser/Parser.h"
#include "../../Parsing/parsing.h"

#include "../NotMatch/NotMatch.h"
#include "../Variable/Variable.h"

#include "Node.h"

#include "llvm/IR/Value.h"

using namespace AST;

AST::Node *AST::Node::parsing(Parser *parser, AST::Group *parent,
                              std::list<TaggedToken> &taggedTokenList) {
  auto first = taggedTokenList.front();
  auto tag = first.tag;
  if (parser->variables.count(first.baseToken.string) != 0) {
    auto variable = Variable::parsing(parser, parent, taggedTokenList);

    std::cout << "parsing a Variable: " << first.baseToken.string << std::endl;
    variable->print(std::cout, 0);
    std::cout << std::endl;

    return variable;
  }
  if (parser->prototypes.count(first.baseToken.string) != 0) {
    auto callee = Callee::parsing(parser, parent, taggedTokenList);

    std::cout << "parsing a Callee: " << first.baseToken.string << std::endl;
    callee->print(std::cout, 0);
    std::cout << std::endl;

    return callee;
  }
  if (parser->parsingRuleTable.count(tag) != 0) {
    auto rule = parser->parsingRuleTable[tag];
    auto astNode = rule.parsingFunc(parser, parent, taggedTokenList);

    std::cout << "parsing a node: " << std::endl;
    astNode->print(std::cout, 0);
    std::cout << std::endl;

    return astNode;
  }
  taggedTokenList.pop_front();
  return new NotMatch(parser, parent, first.baseToken.string);
}

std::ostream &operator<<(std::ostream &os, const AST::Node &node) {
  node.print(os, 0);
  return os;
}
