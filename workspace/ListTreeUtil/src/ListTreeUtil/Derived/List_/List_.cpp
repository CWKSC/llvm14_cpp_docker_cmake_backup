
#include <include_std.h>

#include "../../Node/Node.h"

#include "List_.h"

namespace ListTreeUtil {

List::List() {}
List::List(std::list<Node *> nodeList) : nodeList(nodeList) {}

bool List::empty() { return nodeList.empty(); };
Node *List::front() { return nodeList.front(); };

void List::push_back(Node *node) { nodeList.push_back(node); }
void List::push_back(List &list) {
  nodeList.insert(end(), list.begin(), list.end());
}

void List::push_front(Node *node) { nodeList.push_front(node); }
void List::push_front(List &list) {
  nodeList.insert(begin(), list.begin(), list.end());
}

std::list<Node *>::iterator List::begin() { return nodeList.begin(); }
std::list<Node *>::iterator List::end() { return nodeList.end(); }

/// Override function

void List::pop_front() { nodeList.pop_front(); }
void List::pop_back() { nodeList.pop_back(); }

void List::clear() { nodeList.clear(); }
List *List::clone() { return new List{nodeList}; };

void List::replaceBy(IList &list) {
  auto another = dynamic_cast<List &>(list);
  nodeList = another.nodeList;
}

bool List::equal(Node *node) {
  auto list = dynamic_cast<List *>(node);
  return nodeList == list->nodeList;
}

std::string List::to_string() {
  if (nodeList.empty())
    return "";
  std::string result;
  for (auto &node : nodeList) {
    result += node->to_string();
  }
  return result;
}

void List::recuriveLoop(std::function<void(Node *)> func) {
  for (auto &node : nodeList) {
    auto list = dynamic_cast<List *>(node);
    if (list != nullptr) {
      list->recuriveLoop(func);
    } else {
      func(node);
    }
  }
}

} // namespace ListTreeUtil