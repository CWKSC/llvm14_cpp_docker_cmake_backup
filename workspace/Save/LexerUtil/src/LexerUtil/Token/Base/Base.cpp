#include <RegexUtil/include.h>
#include <include_std.h>

#include "../../Lexer/Lexer.h"

#include "Base.h"

using namespace std;

namespace LexerUtil {
namespace Token {

Base::Base() {}

Base::Base(std::string string, int line, int position)
    : string(string), line(line), position(position), length(string.length()){};

Base::Base(Lexer &root, std::string string)
    : Base(string, root.getMemory<int>(std::string("lineCounter")),
           root.getMemory<int>(std::string("positionCounter"))){};

Base::Base(Lexer &root, RegexUtil::RegexMatchResult &matchResult)
    : Base(root, matchResult.matchString) {}

std::ostream &operator<<(std::ostream &os, const Base &token) {
  os << "(string: " << token.string << ", line: " << token.line
     << ", position: " << token.position << ", length: " << token.length << ")";
  return os;
}

} // namespace Token
} // namespace LexerUtil