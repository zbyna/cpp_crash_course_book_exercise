#include <iostream>
#include <windows.h>

// 9-3. Implement an allfunction with the following prototype see template below
// The Fnfunction type is a predicate that supports bool operator()(In).
// Your all function must test whether function returns true for every element of
// input. If it does, return true. Otherwise, return false.

template <typename Fn, typename In> constexpr bool all(Fn function, In* input, size_t length) {
    for(size_t i = 0; i < length; i++) {
        if(!function(input[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    SetConsoleOutputCP(1250);
    int data[]{ 100, 200, 300, 400, 500 };
    size_t data_len = 5;
    auto all_gt100 = all([](auto x) { return x > 100; }, data, data_len);
    if(all_gt100)
        std::cout << "All elements greater than 100.\n";
}
