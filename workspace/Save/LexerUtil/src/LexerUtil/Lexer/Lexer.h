#pragma once

#include <include_std.h>

#include "../LexingRule/LexingRule.h"
#include "../Token/include.h"

namespace LexerUtil {

struct Lexer {

  Lexer *root;

  std::unordered_map<std::string, std::any> memory;
  std::unordered_map<std::string, LexingRule> lexingRules;

  Lexer();
  Lexer(Lexer &lexer);

  void setRules(std::unordered_map<std::string, LexingRule> lexingRules);
  void addRule(std::string regexString, LexingRule lexingRule);
  void addRules(std::unordered_map<std::string, LexingRule> lexingRules);

  std::list<Token::Base> lexing(std::string &text);

  template <typename T> T getMemory(std::string key) {
    return std::any_cast<T>(memory[key]);
  }
  template <typename T> void setMemory(std::string key, T value) {
    memory[key] = value;
  }
};

} // namespace LexerUtil
