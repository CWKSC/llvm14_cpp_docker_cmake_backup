#pragma once

#include "include_std_llvm.h"

namespace LLVMIRUtil {

llvm::FunctionCallee createExtern(llvm::Module *module, std::string name,
                                  llvm::Type *returnType,
                                  llvm::ArrayRef<llvm::Type *> parameters = {},
                                  bool isVarArg = false,
                                  llvm::GlobalValue::LinkageTypes linkageType =
                                      llvm::Function::ExternalLinkage);

llvm::FunctionCallee declarePuts(llvm::Module *module);

llvm::FunctionCallee declarePrintf(llvm::Module *module);

} // namespace LLVMIRUtil
