#pragma once

#include "include_std_llvm.h"

namespace LLVMIRUtil {

llvm::Type *getInt1Ty(llvm::LLVMContext *context);
llvm::Type *getInt8Ty(llvm::LLVMContext *context);
llvm::Type *getInt32Ty(llvm::LLVMContext *context);

} // namespace LLVMIRUtil
