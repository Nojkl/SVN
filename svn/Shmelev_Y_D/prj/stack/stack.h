#pragma once

#include <cstddef>

class Stack {
public:
    explicit Stack(size_t cap = 1);

    Stack(const Stack& rhs);

    Stack& operator=(Stack rhs);

    void Push(int elem);

    void Pop();

    int Top();

    bool IsEmpty();

    ~Stack();

private:
    void Reallocate(size_t cap);

    int* begin_;
    int* end_;
    int* capacity_;
};