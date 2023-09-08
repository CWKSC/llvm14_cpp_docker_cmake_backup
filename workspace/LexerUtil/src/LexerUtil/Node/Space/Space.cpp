#include <CombinatorUtil/include.h>
#include <LexerCombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "Space.h"

using namespace std;
using namespace CombinatorUtil;
using namespace LexerCombinatorUtil;

namespace LexerUtil::Node {

Space::Space(std::string value) : value(value) {}

bool Space::equal(ListTreeUtil::Node *node) {
  auto another = dynamic_cast<Space *>(node);
  if (another == nullptr)
    return false;
  return value == another->value;
};

std::string Space::to_string() { return value; }

} // namespace LexerUtil::Node