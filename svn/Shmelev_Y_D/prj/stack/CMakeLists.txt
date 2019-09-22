cmake_minimum_required(VERSION 3.12)
project(stack)

set(CMAKE_CXX_STANDARD 17)

add_executable(stack stack_test.cpp stack.cpp)