#include "stack.h"

#include <iostream>

void TestPush() {
    auto stack = Stack();
    bool all_is_ok = true;
    stack.Push(5);
    if (stack.Top() != 5) {
        std::cout << "error: " << stack.Top() << " != 5\n";
        all_is_ok = false;
    }
    stack.Push(6);
    if (stack.Top() != 6) {
        std::cout << "error: " << stack.Top() << " != 6\n";
        all_is_ok = false;
    }
    stack.Push(7);
    if (stack.Top() != 7) {
        std::cout << "error: " << stack.Top() << " != 7\n";
        all_is_ok = false;
    }
    if (all_is_ok) {
        std::cout << "TestPush successfully finished!\n";
    }
}

void TestPop() {
    auto stack = Stack();
    bool all_is_ok = true;
    stack.Pop();
    stack.Push(5);
    stack.Push(6);
    stack.Pop();
    if (stack.Top() != 5) {
        std::cout << "error: " << stack.Top() << " != 5\n";
        all_is_ok = false;
    }
    if (all_is_ok) {
        std::cout << "TestPop successfully finished!\n";
    }
}

void TestIsEmpty() {
    auto stack = Stack();
    bool all_is_ok = true;
    if (!stack.IsEmpty()) {
        std::cout << "error: stack isn't empty!\n";
        all_is_ok = false;
    }
    stack.Push(5);
    if (stack.IsEmpty()) {
        std::cout << "error: stack is empty!\n";
        all_is_ok = false;
    }
    stack.Pop();
    if (!stack.IsEmpty()) {
        std::cout << "error: stack isn't empty!\n";
        all_is_ok = false;
    }
    if (all_is_ok) {
        std::cout << "TestIsEmpty successfully finished!\n";
    }
}

void TestTop() {
    auto stack = Stack();
    bool all_is_ok = true;
    stack.Push(500);
    if (stack.Top() != 500) {
        std::cout << "error: " << stack.Top() << " != 500\n";
        all_is_ok = false;
    }
    stack.Push(600);
    if (stack.Top() != 600) {
        std::cout << "error: " << stack.Top() << " != 600\n";
        all_is_ok = false;
    }
    stack.Push(800);
    if (stack.Top() != 800) {
        std::cout << "error: " << stack.Top() << " != 800\n";
        all_is_ok = false;
    }
    stack.Pop();
    if (stack.Top() != 600) {
        std::cout << "error: " << stack.Top() << " != 600\n";
        all_is_ok = false;
    }
    stack.Pop();
    if (stack.Top() != 500) {
        std::cout << "error: " << stack.Top() << " != 500\n";
        all_is_ok = false;
    }
    if (all_is_ok) {
        std::cout << "TestTop successfully finished!\n";
    }
}

void TestAllInAllOut() {
    auto stack = Stack();
    bool all_is_ok = true;
    for (int i = 0; i < 1000; ++i) {
        stack.Push(i);
        if (stack.Top() != i) {
            std::cout << "error: " << stack.Top() << " != " << i << '\n';
            all_is_ok = false;
            break;
        }
    }
    for (int i = 999; i >= 0; --i) {
        if (stack.Top() != i) {
            std::cout << "error: " << stack.Top() << " != " << i << '\n';
            all_is_ok = false;
            break;
        }
        stack.Pop();
    }
    if (all_is_ok) {
        std::cout << "TestAllInAllOut successfully finished!\n";
    }
}

void RunTests() {
    TestPush();
    TestPop();
    TestIsEmpty();
    TestTop();
    TestAllInAllOut();
}

int main(int argc, char const *argv[]) {
    RunTests();
    return 0;
}