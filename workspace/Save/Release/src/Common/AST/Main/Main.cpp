
#include <iostream>
#include <list>
#include <string>

#include "../../Parsing/parsing.h"
#include "../../Token/TaggedToken/TaggedToken.h"

#include "../Group/Group.h"
#include "../Prototype/Prototype.h"

#include "Main.h"

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

using namespace AST;

Main::~Main() { delete func; }

Node *Main::parsing(Parser *parser, Group *parent,
                    std::list<TaggedToken> &taggedTokenList) {
  Parsing::exceptASTNode(taggedTokenList, "main");
  auto func = new Func(parser, parent);

  auto prototype = new Prototype(parser, parent);
  prototype->name = "llvm_main";
  func->prototype = prototype;

  auto body = Group::parsing(parser, parent, taggedTokenList);
  func->body = body;

  auto main = new Main(parser, parent);
  main->func = func;
  return main;
}

llvm::Value *Main::codegen(CodeGenerator *codeGenerator) {
  return func->codegen(codeGenerator);
}

void Main::print(std::ostream &os, int indent) const {
  os << std::string(indent, ' ') << "main (" << std::endl;
  indent += 4;
  auto nodeList = func->body->nodeList;
  for (auto &node : nodeList) {
    os << std::string(indent, ' ');
    node->print(os, indent);
    os << std::endl;
  }
  indent -= 4;
  os << std::string(indent, ' ') << ")";
}
