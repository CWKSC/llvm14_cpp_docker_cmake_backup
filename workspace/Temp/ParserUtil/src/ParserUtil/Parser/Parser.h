#pragma once

#include <include_std.h>

#include "../ParserCombinatorUtil/ParserCombinator/ParserCombinator.h"

namespace ParserUtil {

struct Parser {

  Parser *root;
  std::unordered_map<std::string, std::any> memory;
  std::vector<std::vector<ParserCombinatorUtil::ParserCombinatorBottomType>>
      rules;

  Parser();
  Parser(Parser &parser);

  void addRule(std::vector<ParserCombinatorUtil::ParserCombinatorBottomType>
                   parserFuncList);
  AST::Base *parsing(std::list<std::string> &tokenList);

  template <typename T> T getMemory(std::string key) {
    return std::any_cast<T>(memory[key]);
  }
  template <typename T> void setMemory(std::string key, T value) {
    memory[key] = value;
  }
};

} // namespace ParserUtil
