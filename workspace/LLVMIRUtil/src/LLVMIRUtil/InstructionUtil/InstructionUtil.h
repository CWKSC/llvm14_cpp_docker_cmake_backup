#pragma once

#include "include_std_llvm.h"

namespace LLVMIRUtil {

std::pair<llvm::AllocaInst *, llvm::StoreInst *>
createAllocStore(llvm::IRBuilder<> *builder, llvm::Value *value,
                 llvm::Value *ArraySize = (llvm::Value *)nullptr,
                 const llvm::Twine &Name = "");

llvm::StoreInst *createIncrement(llvm::IRBuilder<> *builder,
                                 llvm::AllocaInst *alloca_value);

} // namespace LLVMIRUtil
