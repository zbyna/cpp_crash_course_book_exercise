#include <iostream>
#include <windows.h>

#include "fibonaci.h"
#include "primenumbers.h"

// 8-3. Integrate PrimeNumberRangeinto Listing 8-27, adding another loop that
// generates all prime numbers less than 500.

int main() {
    SetConsoleOutputCP(1250);
    std::cout << "Fibanacci : \n";
    for(const auto i : FibonacciRange{ 5000 }) {
        std::cout << " " << i << " ";
    }
    std::cout << "\n";
    std::cout << "Prime numbers: \n";
    for(const auto i : PrimeNumbersRange{ 100 }) {
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