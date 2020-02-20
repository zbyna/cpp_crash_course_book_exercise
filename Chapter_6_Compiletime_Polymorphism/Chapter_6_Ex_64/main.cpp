#include <cstddef>
#include <iostream>
#include <type_traits>
#include <windows.h>

// 6-4. Refactor meanin Listing 6-13 to accept an array rather than pointer and length arguments. Use Listing 6-33 as a guide.

template <typename T, size_t length> T mean(const T (&values)[length]) {
    T result{};
    for(size_t i{}; i < length; i++) {
        result += values[i];
    }
    return result / length;
}

int main() {
    SetConsoleOutputCP(1250);
    const double nums_d[]{ 1.0, 2.0, 3.0, 4.0 };
    const auto result1 = mean(nums_d); // mean<double, 4>(nums_d);
    std::cout << "double: " << result1 << "\n";
    const float nums_f[]{ 1.0f, 2.0f, 3.0f, 4.0f };
    const auto result2 = mean(nums_f); // mean<float, 4>(nums_f);
    std::cout << "float: " << result2 << "\n";
    const size_t nums_c[]{ 1, 2, 3, 4 };
    const auto result3 = mean(nums_c); // mean<size_t, 4>(nums_c);
    std::cout << "size_t: " << result3 << "\n";
}
