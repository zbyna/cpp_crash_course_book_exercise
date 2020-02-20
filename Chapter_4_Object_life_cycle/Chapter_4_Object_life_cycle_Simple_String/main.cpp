#include <chrono>
#include <cstring>
#include <ctime>
#include <iostream>
#include <windows.h>
// 4 - 7. Identify each method in the SimpleStringclass (Listing 4-38). Try reimplementing it  from scratch without
// referring to the book.

struct SimpleString {

private:
    size_t maxSize; // max chars in SimpleString
    size_t length;  // actal count of chars
    char* buffer;   // pointer to the begin of chars buffer

public:
    SimpleString(size_t maxS, const char* buf)
        : maxSize{ maxS }
        , length{}
        , buffer{ new char[maxSize] } {
        if((strlen(buf) + 2) > maxSize) {
            buffer[0] = 0;
        } else {
            length = strlen(buf);
            std::strncpy(buffer, buf, length);
            buffer[length++] = '\n';
            buffer[length] = 0; // null terminated string
        }
    }
    ~SimpleString() {
        std::cout << "Dealocating object with buffer adress: " << static_cast<const void*>(buffer) << "\n";
        delete[] buffer; // dealocate buffer
    }
    bool addLine(const char* line) {
        const auto pomLen = strlen(line);
        if((pomLen + length + 2) > maxSize) {
            return false;
        } else {
            std::strncpy(buffer + length, line, pomLen);
            length = length + pomLen;
            buffer[length++] = '\n';
            buffer[length] = 0; // null terminated string
            return true;
        }
    }
    SimpleString(SimpleString& other) // copy constructor - returns brand new object :-) obviously :-)
        : maxSize{ other.maxSize }
        , length{ other.length }
        , buffer{ new char[maxSize] } {
        std::strncpy(buffer, other.buffer, length);
    }
    SimpleString(SimpleString&&
            other) // move constructor - other is mark for exctintion :-) and will be automatically
                   // dealocated (it is Rvalue = temporary until expresion on the right side is needed), and that is
                   // why is needed to assign zeros and null to its fields
        : maxSize{ other.maxSize }
        , length{ other.length }
        , buffer{ other.buffer } {
        other.maxSize = 0;
        other.length = 0;
        other.buffer = nullptr;
    }
    SimpleString& operator=(SimpleString& other) {
        if(&other == this) {
            return *this;
        }
        length = other.length;
        delete[] buffer;            // dealloc old buffer pointer
        buffer = new char[maxSize]; // create new buffer pointer
        std::strncpy(buffer, other.buffer, other.length);
        return *this;
    }
    SimpleString& operator=(SimpleString&& other) {
        if(&other == this) {
            return *this;
        }
        length = other.length;
        maxSize = other.maxSize;
        buffer = other.buffer;
        // clean RValue fields for automatic deallocation without issues
        other.length = 0;
        other.maxSize = 0;
        other.buffer = nullptr;
        return *this;
    }

    void printToConsole(const char* p) {
        std::cout << p << buffer << "\n";
    }
};

int main() {
    SetConsoleOutputCP(1250);
    std::cout << "----- ----- ----- ----- -----\n";
    const char* s = "Nazdar";
    SimpleString pomS{ 255, s };
    pomS.printToConsole("PomS je: ");
    pomS.addLine("Nová øádka");
    pomS.printToConsole("PomS je: ");
    SimpleString pomS2{ 255, "BBBBB" };
    pomS2.printToConsole("pomS2 je: ");
    pomS2 = pomS; // copy assignment
    pomS2.printToConsole("pomS2 je: ");
    SimpleString pomS3{ pomS };
    pomS3.printToConsole("pomS3 je: ");
    pomS.printToConsole("PomS po copy construktor je: ");
    SimpleString pomS4{ std::move(pomS) };
    pomS4.printToConsole("PomS4 je: ");
    // semms like pomS is dealocated by automatically and not possible to print it
    //    pomS.printToConsole("PomS po move constr je: ");
    SimpleString pomS5{ 255, "CCCCC" };
    pomS5.printToConsole("PomS5 je: ");
    pomS5 = std::move(pomS4);
    pomS5.printToConsole("PomS5 je: ");
}