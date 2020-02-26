#include <iostream>
#include <windows.h>
// 9-1. Implement a foldfunction template with the following prototype:
//  see template below
// For example, your implementation must support the following usage: see main()
// The value of sum should be 1,500. Use fold to calculate the following quantities:
// the maximum, the minimum, and the number of elements greater than 200.

template <typename Fn, typename In, typename Out> constexpr Out fold(Fn function, In* input, size_t length, Out initial) {
    Out pom{ initial };
    for(size_t i = 0; i < length; i++) {
        pom = function(pom, input[i]);
    }
    return pom;
}

int main() {
    SetConsoleOutputCP(1250);
    int data[]{ 100, 200, 300, 400, 500 };
    size_t data_len = 5;
    auto sum = fold([](auto x, auto y) { return x + y; }, data, data_len, 0);
    std::cout << "Sum: " << sum << "\n";
    auto maxPom = fold(
        [](auto m, auto y) {
            if(y > m)
                return y;
            else
                return m;
        },
        data, data_len, 0);
    std::cout << "Max: " << maxPom << "\n";
    auto minPom = fold(
        [](auto m, auto y) {
            if(m != 0) {
                if(y < m)
                    return y;
                else
                    return m;
            }
            return y;
        },
        data, data_len, 0);
    std::cout << "Min: " << minPom << "\n";
    auto greaterThanPom = fold(
        [](auto m, auto y) {
            if(y > 200)
                m++;
            return m;
        },
        data, data_len, 0);
    std::cout << "Greater than 200: " << greaterThanPom << "\n";
}
