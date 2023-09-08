
#include <include_std.h>

#include "../../../Token/PureToken/PureToken.h"

#include "Space.h"

using namespace std;

namespace LexerCombinatorUtil::Token {

Space::Space(PureToken *pureToken) { spaceString = pureToken->token; }

void Space::print() { std::cout << spaceString; }

} // namespace LexerCombinatorUtil::Token