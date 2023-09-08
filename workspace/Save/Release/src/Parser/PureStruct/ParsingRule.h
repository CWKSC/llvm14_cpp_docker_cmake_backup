#pragma once

#include <functional>
#include <list>
#include <string>
#include <vector>

#include "../../Common/AST/AST.h"
#include "../../Common/Parsing/parsing.h"
#include "../../Common/Token/TaggedToken/TaggedToken.h"

struct ParsingRule {

  std::function<AST::Node *(Parser *parser, AST::Group *parent,
                            std::list<TaggedToken> &tokenList)>
      parsingFunc;

  ParsingRule() {}
  ParsingRule(std::function<AST::Node *(Parser *parser, AST::Group *parent,
                                        std::list<TaggedToken> &tokenList)>
                  parsingFunc)
      : parsingFunc(parsingFunc) {}
};
