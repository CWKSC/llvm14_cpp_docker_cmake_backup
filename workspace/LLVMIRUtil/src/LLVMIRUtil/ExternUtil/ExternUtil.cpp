#include "include_std_llvm.h"

#include "../FunctionUtil/FunctionUtil.h"

using namespace llvm;

namespace LLVMIRUtil {

FunctionCallee createExtern(
    Module *module, std::string name, Type *returnType,
    ArrayRef<Type *> parameters = {}, bool isVarArg = false,
    GlobalValue::LinkageTypes linkageType = Function::ExternalLinkage) {
  auto funcType = FunctionType::get(returnType, parameters, isVarArg);
  return module->getOrInsertFunction(name, funcType);
}

FunctionCallee declarePuts(Module *module) {
  auto builder = new IRBuilder<>(module->getContext());
  return createExtern(module, "puts", builder->getInt32Ty(),
                      {builder->getInt8PtrTy()});
}

FunctionCallee declarePrintf(Module *module) {
  auto builder = new IRBuilder<>(module->getContext());
  return createExtern(module, "printf", builder->getInt32Ty(),
                      {builder->getInt8PtrTy()}, true);
}

} // namespace LLVMIRUtil
