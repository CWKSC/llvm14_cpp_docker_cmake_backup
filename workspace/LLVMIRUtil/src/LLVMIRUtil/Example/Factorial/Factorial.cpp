#include <include_std_llvm.h>

#include "../../ConstantUtil/ConstantUtil.h"
#include "../../ExternUtil/ExternUtil.h"
#include "../../FunctionUtil/FunctionUtil.h"
#include "../../GlobalVariableUtil/GlobalVariableUtil.h"
#include "../../MainUtil/MainUtil.h"

using namespace llvm;

namespace LLVMIRUtil::Example {

Module *createFactorial() {

  auto context = new llvm::LLVMContext();
  auto module = new llvm::Module("Factorial", *context);
  auto builder = new IRBuilder<>(*context);

  auto func_factorial = createFunction(
      module, "factorial", builder->getInt32Ty(), {builder->getInt32Ty()});

  //  createPutsMain(module, constantString);

  return module;
}

} // namespace LLVMIRUtil::Example
