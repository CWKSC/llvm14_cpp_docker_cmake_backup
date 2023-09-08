
#include <iostream>
#include <list>
#include <string>

#include "../../Parsing/parsing.h"
#include "../../Token/TaggedToken/TaggedToken.h"

#include "../Group/Group.h"

#include "BinaryOperator.h"

#include "llvm/ADT/APFloat.h"
#include "llvm/IR/Constants.h"

#include "../../../CodeGenerator/CodeGenerator.h"

using namespace AST;

BinaryOperator::~BinaryOperator() {}

BinaryOperator *
BinaryOperator::parsing(Parser *parser, Group *parent,
                        std::list<TaggedToken> &taggedTokenList) {
  BinaryOperator *binaryOperator = new BinaryOperator(parser, parent);
  binaryOperator->operatorString = taggedTokenList.front().baseToken.string;
  taggedTokenList.pop_front();

  binaryOperator->node1 = AST::Node::parsing(parser, parent, taggedTokenList);
  binaryOperator->node2 = AST::Node::parsing(parser, parent, taggedTokenList);
  return binaryOperator;
}

llvm::Value *BinaryOperator::codegen(CodeGenerator *codeGenerator) {
  llvm::Value *L = node1->codegen(codeGenerator);
  llvm::Value *R = node2->codegen(codeGenerator);

  if (!L || !R)
    return nullptr;

  switch (operatorString[0]) {
  case '+':
    return codeGenerator->Builder->CreateFAdd(L, R, "addtmp");
  case '-':
    return codeGenerator->Builder->CreateFSub(L, R, "subtmp");
  case '*':
    return codeGenerator->Builder->CreateFMul(L, R, "multmp");
  case '<':
    L = codeGenerator->Builder->CreateFCmpULT(L, R, "cmptmp");
    // Convert bool 0/1 to double 0.0 or 1.0
    return codeGenerator->Builder->CreateUIToFP(
        L, llvm::Type::getDoubleTy(*codeGenerator->TheContext), "booltmp");
  default:
    return nullptr;
  }
}

void BinaryOperator::print(std::ostream &os, int indent) const {
  os << "BinaryOperator " << operatorString << " (" << std::endl;
  indent += 4;

  os << std::string(indent, ' ');
  node1->print(os, indent);
  os << std::endl;

  os << std::string(indent, ' ');
  node2->print(os, indent);
  os << std::endl;

  indent -= 4;
  os << std::string(indent, ' ') << ")";
}
