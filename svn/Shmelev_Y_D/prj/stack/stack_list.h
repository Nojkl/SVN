#ifndef STACK_STACK_LIST_H
#define STACK_STACK_LIST_H

#include <cstddef>
#include <memory>

struct Node {
  std::unique_ptr<Node> prev = nullptr;
  int val;
};

class StackList {
 public:
  explicit StackList();

  StackList(const StackList& rhs);

  StackList& operator=(StackList rhs);

  void Push(int elem);

  void Pop();

  int Top();

  bool IsEmpty();

  ~StackList() = default;

 private:
  std::unique_ptr<Node> last_;
  bool is_empty_;
};
#endif  // STACK_STACK_LIST_H
