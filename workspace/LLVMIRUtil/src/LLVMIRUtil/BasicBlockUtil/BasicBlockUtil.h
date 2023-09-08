#pragma once

#include "include_std_llvm.h"

namespace LLVMIRUtil {

llvm::BasicBlock *
createBB(llvm::LLVMContext *context, const llvm::Twine &Name = "",
         llvm::Function *Parent = (llvm::Function *)nullptr,
         llvm::BasicBlock *InsertBefore = (llvm::BasicBlock *)nullptr);

} // namespace LLVMIRUtil
