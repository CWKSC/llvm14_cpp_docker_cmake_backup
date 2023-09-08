#include "include_std_llvm.h"

#include "../GlobalVariableUtil/GlobalVariableUtil.h"
#include "../TypeUtil/TypeUtil.h"

using namespace llvm;

namespace LLVMIRUtil {

Constant *getConstInt8(LLVMContext *context, char value) {
  return ConstantInt::getIntegerValue(getInt8Ty(context), APInt(8, value));
}

Constant *getConstInt32(LLVMContext *context, int value) {
  return ConstantInt::getIntegerValue(getInt32Ty(context), APInt(32, value));
}

Constant *getConstCharArray(LLVMContext *context, std::string value) {
  auto length = value.length() + 1;
  auto arrayTy = ArrayType::get(getInt8Ty(context), length);
  std::vector<Constant *> values;
  for (char c : value) {
    values.push_back(getConstInt8(context, c));
  }
  values.push_back(getConstInt8(context, 0));
  return llvm::ConstantArray::get(arrayTy, values);
}

GlobalVariable *createPrivateGlobConstCharArray(Module *module,
                                                std::string value,
                                                std::string name) {
  auto context = &module->getContext();
  auto length = value.length() + 1;
  auto arrayTy = ArrayType::get(getInt8Ty(context), length);
  auto globVar = createPrivateConstGlobVar(module, arrayTy, name);
  auto *constCharArray = getConstCharArray(context, value);
  globVar->setInitializer(constCharArray);

  return globVar;
}

GlobalVariable *createPrivateAnonGlobConstCharArray(Module *module,
                                                    std::string value) {
  auto context = &module->getContext();
  auto length = value.length() + 1;
  auto arrayTy = ArrayType::get(getInt8Ty(context), length);
  auto *constCharArray = getConstCharArray(context, value);
  auto globVar = createPrivateConstAnonGlobVar(module, arrayTy, constCharArray);

  return globVar;
}

} // namespace LLVMIRUtil