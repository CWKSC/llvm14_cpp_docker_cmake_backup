
#include <iostream>

#include "NotMatch.h"

#include "llvm/IR/Value.h"

using namespace AST;

NotMatch::~NotMatch() {}

llvm::Value *NotMatch::codegen(CodeGenerator *codeGenerator) { return nullptr; }

void NotMatch::print(std::ostream &os, int indent) const {
  os << "ASTNode NotMatch - " << this->string;
}