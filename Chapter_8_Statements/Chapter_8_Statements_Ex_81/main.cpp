#include "fibonaci.h"
#include <iostream>
#include <windows.h>

// 8-1. Refactor Listing 8-27 into separate translation units: one for main and
// another for FibonacciRange and FibonacciIterator. Use a header file to share
// definitions between the two translation units.

int main() {
    SetConsoleOutputCP(1250);
    for(const auto i : FibonacciRange{ 5000 }) {
        std::cout << " " << i << " ";
    }
    std::cout << "\n";
}

// from page 235:
// Every range exposes a beginand an endmethod. These functions represent the common interface that a range-based forloop uses to
// interact with  a range. Both methods return iterators. An iterator is an object that supports  operator!=, operator++, and
// operator*.  Let’s look at how all these pieces fit together. Under the hood, a rangebased forloop looks just like the loop in
// Listing 8-25.
//              const auto e = range.end();
//              for(auto b = range.begin(); b != e; ++b) {
//                  const auto& elementy = *b;
//              }
// Listing 8 - 25 : A forloop simulating a range - based forloop