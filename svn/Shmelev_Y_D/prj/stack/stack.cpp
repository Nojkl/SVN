#include "stack.h"

#include <stdexcept>
#include <algorithm>

Stack::Stack(size_t cap) {
    begin_ = new int[cap];
    end_ = begin_;
    capacity_ = end_ + cap;
}

Stack::Stack(const Stack &rhs) {
    begin_ = new int[rhs.capacity_ - rhs.begin_];
    end_ = begin_ + (rhs.end_ - rhs.begin_);
    capacity_ = begin_ + (rhs.capacity_ - rhs.begin_);
    for (size_t i = 0; i < end_ - begin_; ++i) {
        *(begin_ + i) = *(rhs.begin_ + i);
    }
}

Stack& Stack::operator=(Stack rhs) {
    std::swap(begin_, rhs.begin_);
    std::swap(end_, rhs.end_);
    std::swap(capacity_, rhs.capacity_);
    return *this;
}

Stack::~Stack() {
    delete[] begin_;
}
    
void Stack::Reallocate(size_t cap) {
    auto new_begin = new int[cap];
    for (size_t i = 0; i < (end_ - begin_); ++i) {
        *(new_begin + i) = *(begin_ + i);
    }
    delete[] begin_;
    end_ = new_begin + (end_ - begin_);
    begin_ = new_begin;
    capacity_ = begin_ + cap;
}

void Stack::Push(int elem) {
    if (capacity_ == end_) {
        this->Reallocate((capacity_ - begin_) * 2);
    }
    *end_ = elem;
    ++end_;
}

void Stack::Pop() {
    if (end_ != begin_) {
        --end_;
    }
}

int Stack::Top() {
    if (end_ == begin_) {
        throw std::runtime_error{"stack is empty!"};
    }
    return *(end_ - 1);
}

bool Stack::IsEmpty() {
    return end_ == begin_;
}

