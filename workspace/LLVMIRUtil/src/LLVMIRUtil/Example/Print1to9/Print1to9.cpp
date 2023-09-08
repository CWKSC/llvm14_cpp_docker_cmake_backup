#include "include_std_llvm.h"

#include "../../ConstantUtil/ConstantUtil.h"
#include "../../ExternUtil/ExternUtil.h"
#include "../../FunctionUtil/FunctionUtil.h"
#include "../../GlobalVariableUtil/GlobalVariableUtil.h"
#include "../../InstructionUtil/InstructionUtil.h"
#include "../../MainUtil/MainUtil.h"
#include "../../TypeUtil/TypeUtil.h"
#include "../../WhileUtil/WhileUtil.h"

using namespace llvm;

namespace LLVMIRUtil::Example {

Module *createPrint1to9() {

  auto context = new llvm::LLVMContext();
  auto module = new llvm::Module("Print 1 to 9", *context);

  auto func_printf = declarePrintf(module);
  auto format = createPrivateGlobConstCharArray(module, "%d\n", "formatString");
  auto constInt32_0 = getConstInt32(context, 0);
  auto constInt32_1 = getConstInt32(context, 1);
  auto constInt32_10 = getConstInt32(context, 10);
  auto int32Ty = getInt32Ty(context);

  // Create main //
  auto [func_main, builder_entry] = createMain(module);

  // Alloca x = 1 //
  auto [alloca_x, _] =
      createAllocStore(builder_entry, constInt32_1, nullptr, "alloca_x");

  // Create while //
  auto [whileCondBlock, alloca_cond, builder_whileCond, builder_whileBody,
        builder_whileEnd] = createWhile(func_main);

  // Entry to while //
  builder_entry->CreateBr(whileCondBlock);

  // while condition //
  auto load_x = builder_whileCond->CreateLoad(int32Ty, alloca_x, "load_x");
  auto cond = builder_whileCond->CreateICmpNE(load_x, constInt32_10, "cond");
  builder_whileCond->CreateStore(cond, alloca_cond);

  // while body //
  builder_whileBody->CreateCall(func_printf, {format, load_x});
  createIncrement(builder_whileBody, alloca_x);

  // while end //
  builder_whileEnd->CreateRet(constInt32_0);

  return module;
}

} // namespace LLVMIRUtil::Example
