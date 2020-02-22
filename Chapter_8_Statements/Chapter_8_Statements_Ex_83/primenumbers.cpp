#include "primenumbers.h"

// class PrimeNumbersIterator {

bool PrimeNumbersIterator::isPrime(int number) {
    if(number < 2)
        return false;
    if(number == 2)
        return true;
    if(number % 2 == 0)
        return false;
    int max = (int)sqrt(number);
    for(int i = 3; i <= max; i += 2) {
        if(number % i == 0) {
            return false;
        }
    }
    return true;
}

PrimeNumbersIterator& PrimeNumbersIterator::operator++() {
    this->current++;
    //        std::cout << "operator ++ reached ! \n";
    while(!isPrime(this->current)) {
        this->current++;
    }
    return *this;
}

bool PrimeNumbersIterator::operator!=(int x) {
    //        std::cout << "operator != reached !" << (this->current) << " : " << x << "\n";
    return (x >= this->current);
}

int PrimeNumbersIterator::operator*() {
    //        std::cout << "operator * reached !" << (this->current) << "\n";
    return this->current;
}

// class PrimeNumbersRange {

PrimeNumbersRange::PrimeNumbersRange(int y)
    : max{ y } {
}

PrimeNumbersIterator PrimeNumbersRange::begin() {
    PrimeNumbersIterator p{};
    //        std::cout << "begin() reached !" << p.current << " \n ";
    return p;
}

int PrimeNumbersRange::end() {
    //        std::cout << "end() reached ! " << this->max << " \n ";
    return this->max;
}
