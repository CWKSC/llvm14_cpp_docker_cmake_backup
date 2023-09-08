#pragma once

#include <functional>
#include <list>
#include <set>
#include <string>
#include <vector>

#include "PureStruct/ParsingResult.h"
#include "PureStruct/ParsingRule.h"

#include "../Common/AST/AST.h"
#include "../Common/Parsing/parsing.h"
#include "../Common/Token/TaggedToken/TaggedToken.h"

struct Parser {

  AST::Group *root = nullptr;

  std::unordered_map<std::string, ParsingRule> parsingRuleTable;
  std::set<std::string> variables;
  std::unordered_map<std::string, AST::Prototype *> prototypes;

  Parser();
  Parser(Parser *parser);

  ParsingResult parsing(const std::vector<TaggedToken> &taggedTokenList);
  void init();
  ParsingResult parsing_body(const std::vector<TaggedToken> &tokenList);

  void addRule(std::string regexString,
               std::function<AST::Node *(Parser *parser, AST::Group *parent,
                                         std::list<TaggedToken> &tokenList)>
                   parsingFunc);
};
