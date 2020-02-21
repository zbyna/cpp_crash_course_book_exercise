#include <iostream>
#include <windows.h>

#include "primenumbers.h"

// 8-2. Implement a PrimeNumberRangeclass that can be used in a range exception  to iterate over all prime numbers less than a
// given value.  Again, use a separate header and source file.

int main() {
    SetConsoleOutputCP(1250);
    for(const auto i : PrimeNumbersRange{ 55 }) {
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