#include "include_std_llvm.h"

#include "../ConstantUtil/ConstantUtil.h"
#include "../FunctionUtil/FunctionUtil.h"

using namespace llvm;

namespace LLVMIRUtil {

std::pair<AllocaInst *, StoreInst *>
createAllocStore(IRBuilder<> *builder, Value *value,
                 Value *ArraySize = (Value *)nullptr, const Twine &Name = "") {
  auto type = value->getType();
  auto alloca_value = builder->CreateAlloca(type, ArraySize, Name);
  auto store_value = builder->CreateStore(value, alloca_value);
  return std::make_pair(alloca_value, store_value);
}

StoreInst *createIncrement(IRBuilder<> *builder, AllocaInst *alloca_value) {
  auto context = &builder->getContext();
  auto constInt32_1 = getConstInt32(context, 1);
  auto type = alloca_value->getAllocatedType();
  auto load_value = builder->CreateLoad(type, alloca_value, "load_value");
  auto value_increment =
      builder->CreateAdd(load_value, constInt32_1, "value_increment");
  return builder->CreateStore(value_increment, alloca_value);
}

} // namespace LLVMIRUtil