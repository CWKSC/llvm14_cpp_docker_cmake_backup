
#include <iostream>
#include <list>
#include <string>

#include "../../Parsing/parsing.h"
#include "../../Token/TaggedToken/TaggedToken.h"

#include "../Group/Group.h"

#include "Integer.h"

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/APInt.h"
#include "llvm/IR/Constants.h"

#include "../../../CodeGenerator/CodeGenerator.h"

using namespace AST;

Integer::~Integer() {}

Integer *Integer::parsing(Parser *parser, Group *parent,
                          std::list<TaggedToken> &taggedTokenList) {
  Integer *integer = new Integer(parser, parent);
  integer->value = std::stoi(taggedTokenList.front().baseToken.string);
  taggedTokenList.pop_front();
  return integer;
}

llvm::Value *Integer::codegen(CodeGenerator *codeGenerator) {
  return llvm::ConstantFP::get(*codeGenerator->TheContext,
                               llvm::APFloat((double)value));
  // llvm::Type *i32_type =
  //     llvm::IntegerType::getInt32Ty(*codeGenerator->TheContext);
  // llvm::Constant *i32_val = llvm::ConstantInt::get(i32_type, value, true);
  // std::cout << "Integer codegen end" << std::endl;
  // return i32_val;
}

void Integer::print(std::ostream &os, int indent) const {
  os << "const integer - " << value;
}
