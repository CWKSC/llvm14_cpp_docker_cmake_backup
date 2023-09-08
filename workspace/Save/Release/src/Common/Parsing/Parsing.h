
#pragma once

#include <functional>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>

// #include "../AST/AST.h"
#include "../Token/TaggedToken/TaggedToken.h"

namespace Parsing {

void exceptASTNode(std::list<TaggedToken> &taggedTokenList, std::string tag);

}