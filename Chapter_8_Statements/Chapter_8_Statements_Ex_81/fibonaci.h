#ifndef FIBONACI_HEADER
#define FIBONACI_HEADER

struct FibonacciIterator {

    bool operator!=(int x) const;

    FibonacciIterator& operator++();

    int operator*() const;

private:
    int current{ 1 }, last{ 1 };
};

struct FibonacciRange {

    explicit FibonacciRange(int max);

    FibonacciIterator begin() const;

    int end() const;

private:
    const int max;
};

#endif