
#include <functional>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>

#include "../AST/AST.h"
#include "../Token/TaggedToken/TaggedToken.h"

void Parsing::exceptASTNode(std::list<TaggedToken> &taggedTokenList,
                            std::string tag) {
  std::cout << "[exceptASTNode] " << tag << std::endl;
  auto first = taggedTokenList.front();
  if (first.tag == tag) {
    taggedTokenList.pop_front();
  } else {
    throw "Unexcept AST Node";
  }
}
