#include "include_std_llvm.h"

#include "../FunctionUtil/FunctionUtil.h"

using namespace llvm;

namespace LLVMIRUtil {

std::pair<Function *, IRBuilder<> *> createMain(Module *module) {
  auto builder = IRBuilder<>(module->getContext());
  return createFunction(module, std::string("main"), builder.getInt32Ty());
}

} // namespace LLVMIRUtil