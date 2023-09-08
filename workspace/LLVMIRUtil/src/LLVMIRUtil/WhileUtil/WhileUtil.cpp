#include "include_std_llvm.h"

#include "../BasicBlockUtil/BasicBlockUtil.h"
#include "../ConstantUtil/ConstantUtil.h"
#include "../FunctionUtil/FunctionUtil.h"
#include "../TypeUtil/TypeUtil.h"

using namespace llvm;

namespace LLVMIRUtil {

std::tuple<BasicBlock *, AllocaInst *, IRBuilder<> *, IRBuilder<> *,
           IRBuilder<> *>
createWhile(Function *func) {
  auto context = &func->getContext();

  auto whileCondBlock = createBB(context, "whileCond", func);
  auto whileBodyBlock = createBB(context, "whileBody", func);
  auto whileEndBlock = createBB(context, "whileEnd", func);

  // while //
  auto builder = IRBuilder<>(whileCondBlock);
  auto type = getInt1Ty(context);
  auto alloca_cond = builder.CreateAlloca(type, nullptr, "alloca_cond");
  auto load_condition = builder.CreateLoad(type, alloca_cond);
  builder.CreateCondBr(load_condition, whileBodyBlock, whileEndBlock);

  // while Body //
  builder.SetInsertPoint(whileBodyBlock);
  builder.CreateBr(whileCondBlock);

  auto whileCondInst_afterAlloca =
      whileCondBlock->getInstList().front().getNextNode();
  auto whileBodyInst_front = &whileBodyBlock->getInstList().front();

  auto builder_whileCond = new IRBuilder<>(whileCondInst_afterAlloca);
  auto builder_whileBody = new IRBuilder<>(whileBodyInst_front);
  auto builder_whileEnd = new IRBuilder<>(whileEndBlock);

  return std::make_tuple(whileCondBlock, alloca_cond, builder_whileCond,
                         builder_whileBody, builder_whileEnd);
}

} // namespace LLVMIRUtil