#pragma once

#include <RegexUtil/include.h>
#include <include_std.h>

namespace LexerUtil {
struct Lexer;
namespace Token {

struct Base {

  std::string string;
  int line;
  int position;
  int length;

  Base();
  Base(std::string string, int line, int position);
  Base(Lexer &root, std::string string);
  Base(Lexer &root, RegexUtil::RegexMatchResult &matchResult);

  friend std::ostream &operator<<(std::ostream &os, const Base &token);
};

} // namespace Token
} // namespace LexerUtil
