
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

#include "../Common/AST/AST.h"
#include "../Common/Parsing/parsing.h"
#include "../Common/Token/BaseToken/BaseToken.h"
#include "../Common/Token/TaggedToken/TaggedToken.h"
#include "Parser.h"
#include "PureStruct/ParsingResult.h"

Parser::Parser() { init(); }

Parser::Parser(Parser *parser) {
  this->root = parser->root;
  this->parsingRuleTable = parser->parsingRuleTable;
  this->variables = parser->variables;
  this->prototypes = parser->prototypes;
}

ParsingResult Parser::parsing(const std::vector<TaggedToken> &taggedTokenList) {
  std::cout << "[Parsing]" << std::endl;
  init();
  return parsing_body(taggedTokenList);
}

void Parser::init() {
  addRule("(", AST::Group::parsing);
  addRule("main", AST::Main::parsing);
  addRule("func", AST::Func::parsing);
  addRule("extern", AST::Extern::parsing);
  addRule("integer", AST::Integer::parsing);
  addRule("float", AST::Float::parsing);
  addRule("binary operator", AST::BinaryOperator::parsing);
  addRule("if", AST::If::parsing);
  addRule("for", AST::For::parsing);
}

ParsingResult
Parser::parsing_body(const std::vector<TaggedToken> &taggedTokenVector) {
  std::list<TaggedToken> taggedTokenList;
  for (const auto &taggedToken : taggedTokenVector) {
    taggedTokenList.push_back(taggedToken);
  }

  AST::Group *root = new AST::Group(this, nullptr);
  this->root = root;

  auto nodeList = AST::Group::parsingInside(this, root, taggedTokenList);
  for (auto &node : nodeList) {
    root->nodeList.push_back(node);
  }

  return ParsingResult(root);
}

void Parser::addRule(
    std::string regexString,
    std::function<AST::Node *(Parser *parser, AST::Group *parent,
                              std::list<TaggedToken> &tokenList)>
        parsingFunc) {
  parsingRuleTable[regexString] = ParsingRule(parsingFunc);
}