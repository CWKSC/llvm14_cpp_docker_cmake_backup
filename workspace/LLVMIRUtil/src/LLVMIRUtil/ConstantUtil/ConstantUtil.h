#pragma once

#include "include_std_llvm.h"

namespace LLVMIRUtil {

llvm::Constant *getConstInt8(llvm::LLVMContext *context, char value);

llvm::Constant *getConstInt32(llvm::LLVMContext *context, int value);

llvm::GlobalVariable *createPrivateGlobConstCharArray(llvm::Module *module,
                                                      std::string value,
                                                      std::string name);

llvm::GlobalVariable *createPrivateAnonGlobConstCharArray(llvm::Module *module,
                                                          std::string value);

} // namespace LLVMIRUtil