#include "include_std_llvm.h"

#include "../../ConstantUtil/ConstantUtil.h"
#include "../../ExternUtil/ExternUtil.h"
#include "../../GlobalVariableUtil/GlobalVariableUtil.h"
#include "../../MainUtil/MainUtil.h"

using namespace llvm;

namespace LLVMIRUtil::Template {

void createPutsMain(Module *module, Value *value) {
  auto func_puts = declarePuts(module);
  auto [func_main, builder_main] = createMain(module);
  builder_main->CreateCall(func_puts, value);
  builder_main->CreateRet(builder_main->getInt32(0));
}

void createPutsMain(Module *module, std::vector<Value *> values) {
  auto func_puts = declarePuts(module);
  auto [func_main, builder_main] = createMain(module);
  for (const auto &value : values) {
    builder_main->CreateCall(func_puts, value);
  }
  builder_main->CreateRet(builder_main->getInt32(0));
}

} // namespace LLVMIRUtil::Template
