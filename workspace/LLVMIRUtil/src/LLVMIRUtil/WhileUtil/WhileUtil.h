#pragma once

#include "include_std_llvm.h"

namespace LLVMIRUtil {

std::tuple<llvm::BasicBlock *, llvm::AllocaInst *, llvm::IRBuilder<> *,
           llvm::IRBuilder<> *, llvm::IRBuilder<> *>
createWhile(llvm::Function *function);

} // namespace LLVMIRUtil
