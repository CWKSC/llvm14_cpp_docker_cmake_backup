#include <iostream>
#include <string>

#include "LLVMIRUtil/include.h"

using namespace std;
using namespace llvm;
using namespace LLVMIRUtil;
using namespace LLVMIRUtil::Example;

int main() {

  InitializeNativeTarget();
  InitializeNativeTargetAsmParser();
  InitializeNativeTargetAsmPrinter();

  auto module_ = createHelloWorld();
  module_->dump();

  // std::cout << "test1" << std::endl;
  // ExecutionEngine *EE = EngineBuilder().create();
  // std::cout << "test2" << std::endl;
  // auto main = module_->getFunction("main");
  // std::cout << main << std::endl;
  // std::vector<GenericValue> noargs;
  // GenericValue gv = EE->runFunction(main, noargs);
  // llvm_shutdown();

  // createHelloWorld()->dump();

  // auto TargetTriple = llvm::sys::getDefaultTargetTriple();
  // std::string Error;
  // auto Target = llvm::TargetRegistry::lookupTarget(TargetTriple, Error);
  // if (!Target) {
  //   llvm::errs() << Error;
  //   return;
  // }
  // auto CPU = "generic";
  // auto Features = "";

  // llvm::TargetOptions opt;
  // auto RM = llvm::Optional<llvm::Reloc::Model>();
  // auto TheTargetMachine =
  //     Target->createTargetMachine(TargetTriple, CPU, Features, opt, RM);

  // TheModule->setTargetTriple(TargetTriple);
  // TheModule->setDataLayout(TheTargetMachine->createDataLayout());

  return 0;
}
