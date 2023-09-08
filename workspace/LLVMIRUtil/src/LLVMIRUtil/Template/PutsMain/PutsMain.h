#pragma once

#include "include_std_llvm.h"

namespace LLVMIRUtil::Template {

void createPutsMain(llvm::Module *module, llvm::Value *value);
void createPutsMain(llvm::Module *module, std::vector<llvm::Value *> values);

} // namespace LLVMIRUtil::Template
