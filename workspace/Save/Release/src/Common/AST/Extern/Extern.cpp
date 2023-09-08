
#include <iostream>
#include <list>
#include <string>

#include "../../../Parser/Parser.h"

#include "../../Parsing/parsing.h"
#include "../../Token/TaggedToken/TaggedToken.h"

#include "../Group/Group.h"
#include "../Prototype/Prototype.h"

#include "Extern.h"

using namespace AST;

Extern::~Extern() {}

Extern *Extern::parsing(Parser *parser, Group *parent,
                        std::list<TaggedToken> &taggedTokenList) {
  Parsing::exceptASTNode(taggedTokenList, "extern");
  Prototype *prototype = Prototype::parsing(parser, parent, taggedTokenList);
  Extern *extern_ = new Extern(parser, parent);
  extern_->prototype = prototype;

  std::cout << "register " << prototype->name << std::endl;
  parser->prototypes[prototype->name] = prototype;
  return extern_;
}

llvm::Value *Extern::codegen(CodeGenerator *codeGenerator) {
  return prototype->codegen(codeGenerator);
}

void Extern::print(std::ostream &os, int indent) const {
  os << "extern ";
  prototype->print(os, indent);
}
