#include <CombinatorUtil/include.h>
#include <LexerCombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "NextLine.h"

using namespace std;
using namespace CombinatorUtil;
using namespace LexerCombinatorUtil;

namespace LexerUtil::Node {

bool NextLine::equal(ListTreeUtil::Node *node) {
  return dynamic_cast<NextLine *>(node) != nullptr;
};

std::string NextLine::to_string() { return "\\n"; }

} // namespace LexerUtil::Node