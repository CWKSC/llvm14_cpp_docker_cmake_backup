#include "include_std_llvm.h"

using namespace llvm;

namespace LLVMIRUtil {

GlobalVariable *createGlobVar(Module *module, Type *type, std::string name) {
  module->getOrInsertGlobal(name, type);
  return module->getNamedGlobal(name);
}

GlobalVariable *createConstGlobVar(Module *module, Type *type,
                                   std::string name) {
  auto globalVariable = createGlobVar(module, type, name);
  globalVariable->setConstant(true);
  return globalVariable;
}

GlobalVariable *createPrivateConstGlobVar(Module *module, Type *type,
                                          std::string name) {
  auto globalVariable = createConstGlobVar(module, type, name);
  globalVariable->setLinkage(GlobalValue::PrivateLinkage);
  return globalVariable;
}

GlobalVariable *createAnonGlobVar(Module *module, Type *type,
                                  Constant *initializer) {
  return new GlobalVariable(*module, type, false, GlobalValue::CommonLinkage,
                            initializer, "");
}

GlobalVariable *createConstAnonGlobVar(Module *module, Type *type,
                                       Constant *initializer) {
  auto anonGlobVar = createAnonGlobVar(module, type, initializer);
  anonGlobVar->setConstant(true);
  return anonGlobVar;
}

GlobalVariable *createPrivateConstAnonGlobVar(Module *module, Type *type,
                                              Constant *initializer) {
  auto anonGlobVar = createConstAnonGlobVar(module, type, initializer);
  anonGlobVar->setLinkage(GlobalValue::PrivateLinkage);
  return anonGlobVar;
}

} // namespace LLVMIRUtil