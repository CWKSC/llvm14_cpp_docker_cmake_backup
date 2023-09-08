#pragma once

#include <include_std.h>

#include "../../IList/IList.h"
#include "../../Node/Node.h"

namespace ListTreeUtil {

struct List : IList {
  std::list<Node *> nodeList;

  List();
  List(std::list<Node *> nodeList);

  void push_front(Node *node);
  void push_front(List &list);
  void push_back(Node *node);
  void push_back(List &list);
  std::list<Node *>::iterator begin();
  std::list<Node *>::iterator end();

  void recuriveLoop(std::function<void(Node *)> func);

  // Override function
  bool empty() override;
  Node *front() override;
  void pop_front() override;
  void pop_back() override;
  void clear() override;
  List *clone() override;
  void replaceBy(IList &list) override;
  bool equal(Node *node) override;
  std::string to_string() override;
};

} // namespace ListTreeUtil