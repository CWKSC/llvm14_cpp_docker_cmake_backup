#pragma once

#include "include_std_llvm.h"

namespace LLVMIRUtil {

std::pair<llvm::Function *, llvm::IRBuilder<> *>
createFunction(llvm::Module *module, std::string name, llvm::Type *returnType,
               llvm::ArrayRef<llvm::Type *> parameters = {},
               llvm::GlobalValue::LinkageTypes linkageType =
                   llvm::Function::ExternalLinkage,
               bool isVarArg = false);

// std::pair<llvm::Function *, llvm::IRBuilder<> *>
// createFunction(llvm::LLVMContext *context, llvm::Module *module,
//                std::string name, llvm::Type *returnType,
//                llvm::GlobalValue::LinkageTypes linkageType =
//                    llvm::Function::ExternalLinkage,
//                bool isVarArg = false);

} // namespace LLVMIRUtil