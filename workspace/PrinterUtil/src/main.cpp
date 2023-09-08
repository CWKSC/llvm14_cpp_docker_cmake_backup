
#include <include_std.h>

#include "PrinterUtil/include.h"

using namespace std;
using namespace PrinterUtil;

struct StringNode {
  std::string value;
  StringNode() {}
  StringNode(std::string value) : value(value) {}
};

struct List : StringNode {
  std::list<StringNode *> nodeList;
  List() : StringNode("") {}
  List(std::list<StringNode *> nodeList) : nodeList(nodeList) {}
};

struct INodePrinter {
  virtual void print(Printer *printer = new Printer) = 0;
};

template <typename List, typename Node> struct ListPrinter : INodePrinter {
  std::list<INodePrinter *> list;
  void init(std::list<Node *> _list) {
    for (auto node : _list) {
      list.push_back(toPrinter(node));
    }
  }
  virtual INodePrinter *toPrinter(Node *node) = 0;
};

struct NodePrinter_Node : INodePrinter {
  StringNode node;
  NodePrinter_Node(StringNode node) : node(node) {}
  void print(Printer *printer = new Printer) { printer->printLine(node.value); }
};

struct ListPrinter_List : ListPrinter<List, StringNode> {
  ListPrinter_List(List list) { init(list.nodeList); }
  INodePrinter *toPrinter(StringNode *node) {
    auto list = dynamic_cast<List *>(node);
    if (list == nullptr) {
      std::cout << "NodePrinter_Node" << std::endl;
      return new NodePrinter_Node(*node);
    } else {
      std::cout << "ListPrinter_List" << std::endl;
      return new ListPrinter_List(*list);
    }
  }
  void print(Printer *printer = new Printer) {
    printer->increaseIndent_exceptFirstTime();
    for (auto &node : list) {
      node->print(printer);
    }
    printer->increaseIndent();
  }
};

int main() {

  List list;
  list.nodeList.push_back(new StringNode{"1"});
  list.nodeList.push_back(new StringNode{"2"});
  list.nodeList.push_back(new List({new StringNode{"3"}, new StringNode{"4"}}));

  ListPrinter_List listPrinter(list);
  listPrinter.print();

  return 0;
}
