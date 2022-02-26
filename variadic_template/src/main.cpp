/// Copyright © 2021
/// Variadic template usage example.
#include <iostream>

void f() {}  // do nothing; recursion base case.

/// handles the first argument of the variadic template argument list.
template<typename T>
void g(T arg) {
  std::cout << arg << "  ";
}

/// Variadic template accepts an arbitrary number of argumentsof arbitrary /
///  types. [head] is the first argument; [tail] is the rest of the arguments.
template<typename T, typename... Tail>
void f(T head, Tail... tail) {
  g(head);
  f(tail...);  // recursively try again with f.
}

int main() {
  std::cout << "first: ";
  // call f(1, 2.2, "hello), which will call f(2.2, "hello"), which will call
  // f("hello"), which fill call f().
  f(1, 2.2, "hello");
  std::cout << "\nsecond: ";
  f(0.2, 'c', "yuck!", 0, 1, 2);
  return 0;
}
