
#include <iostream>
#include <list>
#include <string>

#include "../../Parsing/parsing.h"
#include "../../Token/TaggedToken/TaggedToken.h"

#include "../Node/Node.h"

#include "Group.h"

using namespace AST;

AST::Group::~Group() {
  for (auto &node : nodeList) {
    delete node;
  }
}

std::list<AST::Node *>
AST::Group::parsingInside(Parser *parser, AST::Group *parent,
                          std::list<TaggedToken> &taggedTokenList) {
  std::list<Node *> astNodeList;
  while (!taggedTokenList.empty()) {
    auto front = taggedTokenList.front();
    if (front.tag == ")") {
      taggedTokenList.pop_front();
      break;
    }
    auto astNode = AST::Node::parsing(parser, parent, taggedTokenList);
    astNodeList.push_back(astNode);
  }
  return astNodeList;
}

AST::Group *AST::Group::parsing(Parser *parser, AST::Group *parent,
                                std::list<TaggedToken> &taggedTokenList) {
  Group *astGroup = new Group(parser, parent);
  Parsing::exceptASTNode(taggedTokenList, "(");
  auto nodeList = Group::parsingInside(parser, parent, taggedTokenList);
  for (auto &node : nodeList) {
    astGroup->nodeList.push_back(node);
  }
  return astGroup;
}

llvm::Value *AST::Group::codegen(CodeGenerator *codeGenerator) {
  for (int i = 0; i < nodeList.size() - 1; i++) {
    nodeList[i]->codegen(codeGenerator);
  }
  return nodeList[nodeList.size() - 1]->codegen(codeGenerator);
}

void AST::Group::print(std::ostream &os, int indent) const {
  os << "ASTNode_Group (" << std::endl;
  printInside(os, indent + 4);
  os << std::string(indent, ' ') << ")";
}

void AST::Group::printInside(std::ostream &os, int indent) const {
  for (auto &node : nodeList) {
    os << std::string(indent, ' ');
    node->print(os, indent);
    os << std::endl;
  }
}
