#include <algorithm> // max()
#include <cstddef>
#include <cstdlib> // std::abs
#include <cstring>
#include <iostream>
#include <math.h> // pow()
#include <stdexcept>
#include <type_traits>
#include <windows.h>

// 7-1. Create an UnsignedBigInteger class that can handle numbers bigger than a long. You can use a byte array as the internal
// representation (for example,  uint8_t[]or char[]). Implement operator overloads for operator+and operator-.  Perform runtime
// checks for overflow. For the intrepid, also implement operator*, operator/, and operator%. Make sure that your operator
// overloads work for  both inttypes and UnsignedBigIntegertypes. Implement an operator inttype conversion. Perform a runtime check
// if narrowing would occur.

class UnsignedBigInteger {
public:
    const size_t maxCount = 200;
    size_t pomLen;
    int* value;                         // uint8_t jsou znaky Zbyòo - ten Lo... je :-)
    UnsignedBigInteger(const char* val) // constructor
        : pomLen{ strlen(val) }
        , value{ nullptr } {
        if(pomLen > 200) {
            std::cout << "max 200 digits allowed \n";
            pomLen = 0;
        } else {
            value = new int[pomLen];
            for(size_t i = 0; i < pomLen; i++) {
                value[i] = static_cast<int>(val[i]) - int('0'); // !!!!! HOrrible C++ !!!!! I need '0' to 0 ...
            }
        }
    }
    ~UnsignedBigInteger() {
        this->printMe("Unsigned Big Integer  dealocated: ");
        pomLen = 0;
        delete value;
    }
    UnsignedBigInteger(UnsignedBigInteger& other) // copy construktor
        : maxCount{ other.maxCount }
        , pomLen{ other.pomLen }
        , value{ new int[pomLen] } {
        std::cout << "Copy Constructor Used \n";
        for(size_t i = 0; i < pomLen; i++) {
            value[i] = other.value[i];
        }
    }
    UnsignedBigInteger& operator=(UnsignedBigInteger& other) { // copy assigment
        std::cout << "Copy ASSIGMENT used \n";
        if(this == &other) {
            return *this;
        }
        this->pomLen = other.pomLen;
        this->value = new int[this->pomLen];
        for(size_t i = 0; i < pomLen; i++) {
            value[i] = other.value[i];
        }
        return *this;
    }

    UnsignedBigInteger& operator=(UnsignedBigInteger&& other) { // move assigment
        std::cout << "move ASSIGMENT used \n";
        if(this == &other) {
            return *this;
        }
        this->pomLen = other.pomLen;
        this->value = new int[this->pomLen];
        for(size_t i = 0; i < pomLen; i++) {
            value[i] = other.value[i];
        }
        other.pomLen = 0;
        other.value = nullptr;
        return *this;
    }

    void printMe(const char* tag = "") {
        std::cout << tag;
        for(size_t i = 0; i < this->pomLen; i++) {
            std::cout << char(this->value[i] + int('0'));
        }
        std::cout << "\n";
    }

    char toString() {
        char* pomRet = new char[this->pomLen];
        for(size_t i = 0; i < this->pomLen; i++) {
            *(pomRet + i) = char(this->value[i] + int('0'));
            std::cout << *(pomRet + i);
        }
        return ' ';
    }

    UnsignedBigInteger operator+(UnsignedBigInteger& other) {
        UnsignedBigInteger pomValue{ *this };
        if(this->pomLen > other.pomLen) {
            this->value = mergeTwoArrays(this->value, other.value, this->pomLen, other.pomLen);
            this->pomLen++;
        } else if(this->pomLen < other.pomLen) {
            this->value = mergeTwoArrays(other.value, this->value, other.pomLen, this->pomLen);
            this->pomLen = other.pomLen + 1;
        } else {
            this->value = mergeTwoArrays(other.value, this->value, other.pomLen, this->pomLen);
            this->pomLen++;
        }
        if(pomValue > *this) {
            throw std::runtime_error{ "Overflow!" };
            *this = pomValue;
        }
        printMe("Inside operator + : ");
        return *this;
    }

    UnsignedBigInteger operator-(UnsignedBigInteger& other) {
        UnsignedBigInteger pomValue{ "000" };
        if(this->pomLen > other.pomLen) {
            pomValue = *this;
            this->value = substractTwoArrays(this->value, other.value, this->pomLen, other.pomLen);
            this->pomLen++;
        } else if(this->pomLen < other.pomLen) {
            pomValue = other;
            this->value = substractTwoArrays(other.value, this->value, other.pomLen, this->pomLen);
            this->pomLen = other.pomLen + 1;
        } else {
            pomValue = *this;
            this->value = substractTwoArrays(other.value, this->value, other.pomLen, this->pomLen);
        }
        if(*this > pomValue) {
            std::cout << "*this: " << this->toString() << " pomValue: " << pomValue.toString() << "\n";
            throw std::runtime_error{ "Overflow inside operator - !" };
            *this = pomValue;
        }
        printMe("Inside operator - : ");
        return *this;
    }

    operator int() {
        int hodn{};
        for(size_t i = 0; i < this->pomLen; i++) {
            //            std::cout << "i: " << i << " this->pomLen - i -1: " << this->pomLen - i - 1 << " this->value[i]: " <<
            //            this->value[i]
            //                      << "\n";
            hodn += this->value[i] * pow(10, this->pomLen - i - 1);
        }
        std::cout << "Inside operator int(): " << hodn << "\n";
        // for checking narrowing I would need to convert hodn back to array of int and compare it to this->value array
        // if converted hodn == this->value then no narowing appeared a podobnì u + a - test the result against one operand to
        // check over-flow error so for it I need operator ==  and operator < for class UnsignedBigInteger a to dìlat nebudu :-)
        // more: https://en.cppreference.com/w/cpp/language/operators and
        // https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading
        //        edit: operator == done :-) , operator < done :-) , checking overflow in operator + and - done,
        //        checking narrowig done :-))))) a BEWARE OF marking method by const - means no change of instance object !!!!!
        UnsignedBigInteger pomValue{ intToArrayChar(hodn) };
        if(*this == pomValue) {
            return hodn;
        } else {
            throw std::runtime_error{ "Narrowed!" };
        }
    }

    void stripZeroFromLeft() {
        int* pomValue{ nullptr };
        bool removeZero{ true };
        size_t i{}; // index in this->value
        size_t j{}; // index in pomValue
        while(removeZero) {
            if(this->value[i] != 0) {
                removeZero = false;
                pomValue = new int[this->pomLen - i];
                for(size_t k = i; k < this->pomLen; k++) {
                    pomValue[j] = this->value[i];
                    //                    std::cout << " k: " << k << " pomValue[j]: " << pomValue[j] << " j: " << j << "\n";
                    j++;
                    i++;
                }
            } else {
                i++;
            }
        }
        delete this->value;
        this->pomLen = j;
        this->value = new int[j];
        this->value = pomValue;
    }

    bool operator==(UnsignedBigInteger other) {
        this->stripZeroFromLeft();
        other.stripZeroFromLeft();
        if(this->pomLen != other.pomLen) {
            return false;
        } else {
            for(size_t i = 0; i < other.pomLen; i++) {
                if(this->value[i] != other.value[i]) {
                    return false;
                }
            }
            return true;
        }
    }

    bool operator>(UnsignedBigInteger other) {
        this->stripZeroFromLeft();
        other.stripZeroFromLeft();
        if(this->pomLen > other.pomLen) {
            return true;
        } else if(this->pomLen < other.pomLen) {
            return false;
        } else {
            for(size_t i = 0; i < other.pomLen; i++) {
                if(this->value[i] > other.value[i]) {
                    return true;
                }
            }
            return false;
        }
    }

private:
    int* mergeTwoArrays(int* a, int* b, size_t velA, size_t velB) {
        int* vysl;
        int k;
        vysl = new int[velA + 1];
        k = static_cast<int>(velA + 1 - 1);
        int carry{ 0 };
        int i{ static_cast<int>(velA - 1) };
        int j{ static_cast<int>(velB - 1) };

        while(j >= 0) {
            int pom = a[i] + b[j] + carry;
            std::cout << "pom je: " << pom << " ";
            vysl[k] = pom % 10;
            carry = pom / 10;
            i--;
            j--;
            k--;
        }
        while(i >= 0) {
            vysl[k] = a[i] + carry;
            carry = vysl[k] / 10;
            i--;
            k--;
        }
        while(k >= 0) {
            if(carry == 0) {
                vysl[k] = 0;
            } else {
                vysl[k] = carry;
            }
            k--;
        }
        return vysl;
    }

    int* substractTwoArrays(int* a, int* b, size_t velA, size_t velB) {
        int* vysl;
        int k;
        if(velA == velB) {
            vysl = new int[velA];
            k = static_cast<int>(velA - 1);
        } else {
            vysl = new int[velA + 1];
            k = static_cast<int>(velA + 1 - 1);
        }

        int carry{ 0 };
        int i{ static_cast<int>(velA - 1) };
        int j{ static_cast<int>(velB - 1) };

        while(j >= 0) {
            int pom{};
            if(a[i] < (b[j] + carry)) {
                pom = (a[i] + 10) - (b[j] + carry);
                carry = 1;
            } else {
                pom = (b[j] + carry) - a[i];
                carry = 0;
            }
            std::cout << "pom je: " << pom << " ";
            vysl[k] = std::abs(pom);
            i--;
            j--;
            k--;
        }
        while(i >= 0) {
            int pom{};
            if(a[i] < carry) {
                pom = (a[i] + 10) - (+carry);
                carry = 1;
            } else {
                pom = carry - a[i];
                carry = 0;
            }
            vysl[k] = std::abs(pom);
            i--;
            k--;
        }
        while(k >= 0) {
            if(carry == 0) {
                vysl[k] = 0;
            } else {
                vysl[k] = carry;
            }
            k--;
        }
        return vysl;
    }

    const char* intToArrayChar(int pomInt) const {
        int zaloha{ pomInt };
        char* resultArray{};
        size_t pomLenArray{ 0 };
        while(zaloha > 0) {
            std::cout << " : " << zaloha % 10;
            zaloha /= 10;
            pomLenArray++;
        }
        std::cout << "\n";
        resultArray = new char[pomLenArray];
        for(size_t i = 0; i < pomLenArray; i++) {
            resultArray[pomLenArray - i - 1] = char((pomInt % 10) + int('0'));
            std::cout << " : " << resultArray[pomLenArray - i - 1];
            pomInt /= 10;
        }
        std::cout << "\n";
        const char* properResult{ resultArray };
        return properResult;
    }
};

int main() {
    SetConsoleOutputCP(1250);
    UnsignedBigInteger prvniInt{ "55" };
    prvniInt.printMe();
    UnsignedBigInteger druheInt{ prvniInt };
    UnsignedBigInteger tretiInt{ "555" };
    try {
        //    prvniInt.operator+(tretiInt);
        tretiInt = druheInt - tretiInt; // for proper functioning of operator+ it is needed to also define
                                        // MOVE assignment tj operator=(Type&& t) :-) because  the result of
                                        // A + B is  rvalue and must be assigned to  c  (c = A + B)
        //    tretiInt = druheInt;
    } catch(const std::overflow_error& e) {
        std::cout << "Exception: " << e.what();
    }

    prvniInt.printMe("prvniInt je: ");
    std::cout << "Zkouška operátoru + pro int 2 + 3 = " << (2 + 3) << "\n";
    try {
        int pom{};
        pom = int(tretiInt);
        std::cout << "Konverze tretiInt na int je: " << pom << "\n";
    } catch(const std::runtime_error& e) {
        std::cout << "Exception: " << e.what();
    }
    tretiInt.printMe("tretiInt je: ");
    tretiInt.stripZeroFromLeft();
    tretiInt.printMe("tretiInt po stripZeroFromLeft() je: ");
    UnsignedBigInteger ctvrteInt{ "55" };
    ctvrteInt.printMe();
    UnsignedBigInteger pateInt{ "55" };
    pateInt.printMe();
    bool rovnajiSe{ ctvrteInt == pateInt };
    std::cout << "Rovnají se " << ctvrteInt.toString() << " a " << pateInt.toString() << " ? "
              << (rovnajiSe ? " true\n" : " false\n");
    ctvrteInt.printMe();
    pateInt.printMe();
    bool jeVetsi{ ctvrteInt > pateInt };
    std::cout << "Je vìtší " << ctvrteInt.toString() << " než " << pateInt.toString() << " ? " << (jeVetsi ? "true\n" : "false\n");
    return 0;
}
