
#include <include_std.h>

#include "PureToken.h"

using namespace std;

namespace LexerCombinatorUtil::Token {

PureToken::PureToken(std::string token) : token(token) {}

void PureToken::print() { std::cout << token; }

} // namespace LexerCombinatorUtil::Token