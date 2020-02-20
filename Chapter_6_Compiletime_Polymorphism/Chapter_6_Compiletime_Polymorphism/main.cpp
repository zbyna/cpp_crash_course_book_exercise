#include <iostream>
#include <type_traits>
#include <windows.h>

// 6-1. The mode of a series of values is the value that appears most commonly. Implement a mode function using the following
// signature: int mode(const int* values, size_t length). If you encounter an error condition, such as input having multiple modes
// and no values, return zero.
// 6-2. Implement mode as a template function.
// 6-3. Modify mode to accept an Integer concept. Verify that mode fails to instantiate with floating types like double.

template <typename T> concept bool jeIntegerNeboFloat() {
    return std::is_integral<T>::value || std::is_floating_point<T>::value;
}

template <jeIntegerNeboFloat T> T mode(const T* values, size_t length) {
    std::cout << "ukazatel na pole: " << values << " velikost pole: " << length << "\n";
    int maxVyskyt{};
    int modus{};
    for(size_t i = 0; i < length; i++) {
        int vyskyt{};
        for(size_t j = 0; j < length; j++) {
            if(values[i] == values[j]) {
                vyskyt++;
            }
        }
        if(maxVyskyt < vyskyt) {
            maxVyskyt = vyskyt;
            modus = values[i];
        }
    }
    return modus;
}

int main() {
    SetConsoleOutputCP(1250);
    int pole[10]{ 1, 5, 3, 4, 5, 5, 7, 8, 5, 10 };
    int* ukPole{ &pole[0] };
    int modus{ mode<int>(ukPole, sizeof(pole) / sizeof(int)) };
    std::cout << "Modus pole[int] je: " << modus << "\n";
    double poleReal[5]{ 1.0, 2.0, 5.0, 4.0, 5.0 };
    double* ukPoleReal = &poleReal[0];
    double modusDouble{ mode<double>(ukPoleReal, sizeof(poleReal) / sizeof(double)) };
    std::cout << "Modus pole[double] je: " << modusDouble << "\n";

    return 0;
}
