#include "include_std_llvm.h"

#include "../FunctionUtil/FunctionUtil.h"

using namespace llvm;

namespace LLVMIRUtil {

Type *getInt1Ty(LLVMContext *context) {
  return IntegerType::getInt1Ty(*context);
}

Type *getInt8Ty(LLVMContext *context) {
  return IntegerType::getInt8Ty(*context);
}

Type *getInt32Ty(LLVMContext *context) {
  return IntegerType::getInt32Ty(*context);
}

} // namespace LLVMIRUtil