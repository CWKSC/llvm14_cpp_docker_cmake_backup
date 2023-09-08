#include <include_std_llvm.h>

#include "../../ConstantUtil/ConstantUtil.h"
#include "../../ExternUtil/ExternUtil.h"
#include "../../GlobalVariableUtil/GlobalVariableUtil.h"
#include "../../MainUtil/MainUtil.h"

using namespace llvm;

namespace LLVMIRUtil::Example {

Module *createHelloWorld() {

  auto context = new llvm::LLVMContext();
  auto module = new llvm::Module("Hello World", *context);

  auto func_puts = declarePuts(module);
  auto constStr = createPrivateAnonGlobConstCharArray(module, "Hello World!");

  auto [func_main, builder_main] = createMain(module);

  auto gep = builder_main->CreateGEP(
      constStr->getValueType(), constStr,
      {builder_main->getInt32(0), builder_main->getInt32(0)});

  builder_main->CreateCall(func_puts, gep);
  builder_main->CreateRet(builder_main->getInt32(0));

  return module;
}

} // namespace LLVMIRUtil::Example
