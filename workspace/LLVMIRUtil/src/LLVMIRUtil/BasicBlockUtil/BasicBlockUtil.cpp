#include "include_std_llvm.h"

#include "../FunctionUtil/FunctionUtil.h"

using namespace llvm;

namespace LLVMIRUtil {

BasicBlock *createBB(LLVMContext *context, const Twine &Name = "",
                     Function *Parent = (Function *)nullptr,
                     BasicBlock *InsertBefore = (BasicBlock *)nullptr) {
  return BasicBlock::Create(*context, Name, Parent, InsertBefore);
}

} // namespace LLVMIRUtil