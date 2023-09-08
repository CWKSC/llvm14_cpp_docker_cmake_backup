

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

#include "CodeGenerator.h"

CodeGenerator::CodeGenerator() { init(); }

void CodeGenerator::init() {
  TheContext = new llvm::LLVMContext();
  TheModule = new llvm::Module("Module", *TheContext);
  Builder = new llvm::IRBuilder<>(*TheContext);
}

void CodeGenerator::codeGenerating(AST::Group *root) {
  std::cout << "[CodeGenerator]" << std::endl;
  root->codegen(this);
  TheModule->print(llvm::errs(), nullptr);
}

void CodeGenerator::print() { TheModule->print(llvm::errs(), nullptr); }