#pragma once

#include "include_std_llvm.h"

namespace LLVMIRUtil {

std::pair<llvm::Function *, llvm::IRBuilder<> *>
createMain(llvm::Module *module);

} // namespace LLVMIRUtil
