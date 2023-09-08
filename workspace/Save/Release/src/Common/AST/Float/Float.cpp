
#include <iostream>
#include <list>
#include <string>

#include "../../Parsing/parsing.h"
#include "../../Token/TaggedToken/TaggedToken.h"

#include "../Group/Group.h"

#include "Float.h"

#include "llvm/ADT/APFloat.h"
#include "llvm/IR/Constants.h"

#include "../../../CodeGenerator/CodeGenerator.h"

using namespace AST;

Float::~Float() {}

Float *Float::parsing(Parser *parser, Group *parent,
                      std::list<TaggedToken> &taggedTokenList) {
  Float *float_ = new Float(parser, parent);
  float_->value = std::stof(taggedTokenList.front().baseToken.string);
  taggedTokenList.pop_front();
  return float_;
}

llvm::Value *Float::codegen(CodeGenerator *codeGenerator) {
  return llvm::ConstantFP::get(*codeGenerator->TheContext,
                               llvm::APFloat(value));
}

void Float::print(std::ostream &os, int indent) const {
  os << "const float - " << value;
}
