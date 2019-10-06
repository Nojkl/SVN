#include "stack_list.h"

#include <stdexcept>

StackList::StackList() {
  last_ = std::make_unique<Node>();
  is_empty_ = true;
}

StackList::StackList(const StackList& rhs) {
  last_ = std::make_unique<Node>();
  last_->val = rhs.last_->val;
  auto next = rhs.last_->prev.get();
  auto our = last_.get();
  while (next != nullptr) {
    our->prev = std::make_unique<Node>();
    our = our->prev.get();
    our->val = next->val;
    next = next->prev.get();
  }
  is_empty_ = rhs.is_empty_;
}

StackList& StackList::operator=(StackList rhs) { last_.swap(rhs.last_); }

bool StackList::IsEmpty() { return is_empty_; }

void StackList::Pop() {
  if (last_->prev) {
    last_ = std::move(last_->prev);
  } else {
    is_empty_ = true;
  }
}

void StackList::Push(int elem) {
  if (is_empty_) {
    last_->val = elem;
    is_empty_ = false;
  } else {
    auto prev = std::move(last_);
    last_ = std::make_unique<Node>();
    last_->prev = std::move(prev);
    last_->val = elem;
  }
}

int StackList::Top() {
  if (is_empty_) {
    throw std::runtime_error{"stack is empty!"};
  }
  return last_->val;
}
