#include "include_std_llvm.h"

using namespace llvm;

namespace LLVMIRUtil {

std::pair<Function *, IRBuilder<> *> createFunction(
    Module *module, std::string name, Type *returnType,
    ArrayRef<Type *> parameters = {},
    GlobalValue::LinkageTypes linkageType = Function::ExternalLinkage,
    bool isVarArg = false) {

  auto &context = module->getContext();
  auto functionType = FunctionType::get(returnType, parameters, isVarArg);
  auto function = Function::Create(functionType, linkageType, name, *module);
  auto entry = BasicBlock::Create(context, "entry", function);
  auto builder = new IRBuilder<>(entry);

  return std::make_pair(function, builder);
}

} // namespace LLVMIRUtil