#pragma once

#include "include_std_llvm.h"

namespace LLVMIRUtil {

/// GlobVar ///
llvm::GlobalVariable *createGlobVar(llvm::Module *module, llvm::Type *type,
                                    std::string name);

llvm::GlobalVariable *createConstGlobVar(llvm::Module *module, llvm::Type *type,
                                         std::string name);

llvm::GlobalVariable *createPrivateConstGlobVar(llvm::Module *module,
                                                llvm::Type *type,
                                                std::string name);

/// AnonGlobVar ///
llvm::GlobalVariable *createAnonGlobVar(llvm::Module *module, llvm::Type *type,
                                        llvm::Constant *initializer);

llvm::GlobalVariable *createConstAnonGlobVar(llvm::Module *module,
                                             llvm::Type *type,
                                             llvm::Constant *initializer);

llvm::GlobalVariable *
createPrivateConstAnonGlobVar(llvm::Module *module, llvm::Type *type,
                              llvm::Constant *initializer);

} // namespace LLVMIRUtil