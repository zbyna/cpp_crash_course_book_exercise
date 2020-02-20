#include <iostream>
#include <windows.h>
// 2-1 Create an enum class Operationthat has values Add, Subtract, Multiply, and Divide

enum class Operation {
    Add,
    Substract,
    Multiply,
    Divide,
};

// 2-2 Create a struct Calculator. It should have a single constructor that takes an Operation.

// 2-3 Create a method on Calculatorcalled int calculate(int a, int b). Upon invocation, this method should perform addition,
// subtraction, multiplication, or division based on its constructor argument and return the result.

struct Calculator {
    Operation op;
    Calculator(Operation o)
        : op{ o } {
        std::cout << "Konstruktor probìhl \n";
    };
    int calculate(int a, int b) {
        switch(this->op) {
        case Operation::Add:
            return a + b;
        case Operation::Substract:
            return a - b;
        case Operation::Multiply:
            return a * b;
        case Operation::Divide:
            return a / b;
        }
        return 0;
    }
};

int main() {
    SetConsoleOutputCP(1250);
    Operation op{ Operation::Divide };
    if(op == Operation::Divide)
        std::cout << "Operace je: Divide \n";
    Calculator calc{ Calculator(op) };
    std::cout << "Výsledek operace je: " << calc.calculate(5, 4) << "\n";
}
