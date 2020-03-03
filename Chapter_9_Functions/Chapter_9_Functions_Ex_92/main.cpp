#include <cstring>
#include <iostream>
#include <windows.h>

// 9-2. Implement a program that accepts an arbitrary number of command line arguments, counts the length in characters of each
// argument, and prints a histogram of the argument length distribution.

struct Histogram {
    int countArg;
    int* lengthArg;
    Histogram(int cArg)
        : countArg{ cArg }
        , lengthArg{ new int[countArg] } {
    }
    ~Histogram() {
        std::cout << "Histogram deallocated ! \n";
        delete lengthArg;
    }
    //    'struct Histogram' has pointer data members but does not override
    //    'Histogram(const Histogram&)' or 'operator=(const Histogram&)' [-Werror=effc++]
    Histogram(Histogram& other) = delete;            // no copy constructor
    Histogram& operator=(Histogram& other) = delete; // no copy assignment
    void getLength(int i, const char* str) {
        this->lengthArg[i] = strlen(str);
    }
    void printHist(int n) {
        for(int i = 0; i < n; i++) {
            std::cout << "arg n:" << i << " ";
            for(int j = 0; j < lengthArg[i]; j++) {
                std::cout << "* ";
            }
            std::cout << "\n";
        }
    }
};

int main(int argc, char** argv) {
    SetConsoleOutputCP(1250);
    Histogram hist{ argc };
    for(int i = 0; i < argc; i++) {
        std::cout << "arg " << i << ": " << argv[i] << "\n";
        hist.getLength(i, argv[i]);
    }
    hist.printHist(argc);
}