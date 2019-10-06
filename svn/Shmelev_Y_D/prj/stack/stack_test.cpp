#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file

#include "stack.h"
#include "stack_list.h"

#include <iostream>
#include "catch2/catch.hpp"

TEST_CASE("Stack using list") {
  SECTION("Test Push") {
    auto stack = StackList();
    stack.Push(5);
    REQUIRE(stack.Top() == 5);
    stack.Push(6);
    REQUIRE(stack.Top() == 6);
    stack.Push(7);
    REQUIRE(stack.Top() == 7);
  }

  SECTION("Test Top") {
    auto stack = StackList();
    stack.Push(500);
    REQUIRE(stack.Top() == 500);
    stack.Push(600);
    REQUIRE(stack.Top() == 600);
    stack.Push(800);
    REQUIRE(stack.Top() == 800);
    stack.Pop();
    REQUIRE(stack.Top() == 600);
    stack.Pop();
    REQUIRE(stack.Top() == 500);
    stack.Pop();
    REQUIRE_THROWS(stack.Top());
  }

  SECTION("Test Pop") {
    auto stack = StackList();
    bool all_is_ok = true;
    stack.Pop();
    stack.Push(5);
    stack.Push(6);
    stack.Pop();
    REQUIRE(stack.Top() == 5);
    stack.Pop();
    REQUIRE_THROWS(stack.Top());
  }

  SECTION("Test IsEmpty") {
    auto stack = StackList();
    REQUIRE(stack.IsEmpty());
    stack.Push(5);
    REQUIRE(!stack.IsEmpty());
    stack.Pop();
    REQUIRE(stack.IsEmpty());
  }

  SECTION("Test deep copy") {
    auto stack = StackList();
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    auto copy = StackList(stack);
    copy.Push(99);
    REQUIRE(copy.Top() == 99);
    stack.Push(88);
    REQUIRE(stack.Top() == 88);
    REQUIRE(copy.Top() == 99);
    stack.Pop();
    copy.Pop();
    REQUIRE(stack.Top() == copy.Top());
    stack.Pop();
    copy.Pop();
    REQUIRE(stack.Top() == copy.Top());
    stack.Pop();
    copy.Pop();
    REQUIRE(stack.Top() == copy.Top());
    REQUIRE_FALSE(stack.IsEmpty());
    REQUIRE_FALSE(copy.IsEmpty());
    stack.Pop();
    copy.Pop();
    stack.Pop();
    copy.Pop();
    REQUIRE(stack.IsEmpty());
    REQUIRE(copy.IsEmpty());
  }

  SECTION("Deep assignment") {
    auto stack = StackList();
    stack.Push(5);
    stack.Push(6);
    stack.Push(7);
    auto copy = stack;
    copy.Push(1);
    REQUIRE(copy.Top() == 1);
    stack.Push(0);
    REQUIRE(stack.Top() == 0);
    REQUIRE(copy.Top() == 1);
    stack.Pop();
    copy.Pop();
    REQUIRE(stack.Top() == copy.Top());
    stack.Pop();
    copy.Pop();
    REQUIRE(stack.Top() == copy.Top());
    stack.Pop();
    copy.Pop();
    REQUIRE(stack.Top() == copy.Top());
  }

  SECTION("All in All out") {
    auto stack = StackList();
    for (int i = 0; i < 1000; ++i) {
      stack.Push(i);
      REQUIRE(stack.Top() == i);
    }
    for (int i = 999; i >= 0; --i) {
      REQUIRE(stack.Top() == i);
      stack.Pop();
    }
  }
}

TEST_CASE("Stack using dynamic array") {
  SECTION("Test Push") {
    auto stack = Stack();
    stack.Push(5);
    REQUIRE(stack.Top() == 5);
    stack.Push(6);
    REQUIRE(stack.Top() == 6);
    stack.Push(7);
    REQUIRE(stack.Top() == 7);
  }

  SECTION("Test Top") {
    auto stack = Stack();
    stack.Push(500);
    REQUIRE(stack.Top() == 500);
    stack.Push(600);
    REQUIRE(stack.Top() == 600);
    stack.Push(800);
    REQUIRE(stack.Top() == 800);
    stack.Pop();
    REQUIRE(stack.Top() == 600);
    stack.Pop();
    REQUIRE(stack.Top() == 500);
    stack.Pop();
    REQUIRE_THROWS(stack.Top());
  }

  SECTION("Test Pop") {
    auto stack = Stack();
    bool all_is_ok = true;
    stack.Pop();
    stack.Push(5);
    stack.Push(6);
    stack.Pop();
    REQUIRE(stack.Top() == 5);
    stack.Pop();
    REQUIRE_THROWS(stack.Top());
  }

  SECTION("Test IsEmpty") {
    auto stack = Stack();
    REQUIRE(stack.IsEmpty());
    stack.Push(5);
    REQUIRE(!stack.IsEmpty());
    stack.Pop();
    REQUIRE(stack.IsEmpty());
  }

  SECTION("Test deep copy") {
    auto stack = Stack();
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    auto copy = Stack(stack);
    copy.Push(99);
    REQUIRE(copy.Top() == 99);
    stack.Push(88);
    REQUIRE(stack.Top() == 88);
    REQUIRE(copy.Top() == 99);
    stack.Pop();
    copy.Pop();
    REQUIRE(stack.Top() == copy.Top());
    stack.Pop();
    copy.Pop();
    REQUIRE(stack.Top() == copy.Top());
    stack.Pop();
    copy.Pop();
    REQUIRE(stack.Top() == copy.Top());
    REQUIRE_FALSE(stack.IsEmpty());
    REQUIRE_FALSE(copy.IsEmpty());
    stack.Pop();
    copy.Pop();
    stack.Pop();
    copy.Pop();
    REQUIRE(stack.IsEmpty());
    REQUIRE(copy.IsEmpty());
  }

  SECTION("Deep assignment") {
    auto stack = Stack();
    stack.Push(5);
    stack.Push(6);
    stack.Push(7);
    auto copy = stack;
    copy.Push(1);
    REQUIRE(copy.Top() == 1);
    stack.Push(0);
    REQUIRE(stack.Top() == 0);
    REQUIRE(copy.Top() == 1);
    stack.Pop();
    copy.Pop();
    REQUIRE(stack.Top() == copy.Top());
    stack.Pop();
    copy.Pop();
    REQUIRE(stack.Top() == copy.Top());
    stack.Pop();
    copy.Pop();
    REQUIRE(stack.Top() == copy.Top());
  }

  SECTION("All in All out") {
    auto stack = Stack();
    for (int i = 0; i < 1000; ++i) {
      stack.Push(i);
      REQUIRE(stack.Top() == i);
    }
    for (int i = 999; i >= 0; --i) {
      REQUIRE(stack.Top() == i);
      stack.Pop();
    }
  }
}
