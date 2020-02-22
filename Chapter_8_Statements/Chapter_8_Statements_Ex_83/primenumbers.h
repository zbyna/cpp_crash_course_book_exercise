#ifndef PRIME_NUMBERS
#define PRIME_NUMBERS

#include <math.h>

class PrimeNumbersIterator {

private:
    bool isPrime(int number);

public:
    int current{ 0 };

    PrimeNumbersIterator& operator++();
    bool operator!=(int x);
    int operator*();
};

class PrimeNumbersRange {

private:
    int max;

public:
    PrimeNumbersRange(int y);
    PrimeNumbersIterator begin();
    int end();
};

#endif