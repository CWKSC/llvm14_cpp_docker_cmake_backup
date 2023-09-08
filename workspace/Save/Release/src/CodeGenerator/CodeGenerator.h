
#pragma once

#include <map>
#include <string>

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Verifier.h"

#include "../Common/AST/AST.h"

struct CodeGenerator {

  llvm::LLVMContext *TheContext;
  llvm::IRBuilder<> *Builder;
  llvm::Module *TheModule;
  std::map<std::string, llvm::Value *> NamedValues;

  CodeGenerator();

  void init();

  void codeGenerating(AST::Group *root);

  void print();
};
