#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <windows.h>
// 4-1. Create a struct TimerClass. In its constructor, record the current time in a field called timestamp.
// 4-2. In the destructor of TimerClass, record the current time and subtract the time at construction. This time is
// roughly the ageof the timer. Print this value.
// 4-3. Implement a copy constructor and a copy assignment operator for TimerClass. The copies should share
// timestampvalues.
// 4-4. Implement a move constructor and a move assignment operator for  TimerClass. A moved-from
// TimerClassshouldn’t print any output to the console when it gets destructed.
// 4-6. Experiment with your TimerClass.
// Create a timer and move it into a function that performs some computationally intensive operation (for example, lots
// of math in a loop). Verify that your timer behaves as you expect.
struct TimerClass {
    std::string name;
    std::chrono::system_clock::time_point timeStamp;
    TimerClass(std::string n)
        : name{ n }
        , timeStamp{ std::chrono::system_clock::now() } {
        std::cout << "normal Consturctor \n";
    };
    ~TimerClass() {
        std::chrono::system_clock::time_point timeEnd = std::chrono::system_clock::now();
        std::chrono::duration<double> deltaTime = timeEnd - timeStamp;
        std::cout << name << " dealocated - "
                  << "Delta times: " << deltaTime.count() << " s\n";
    };
    TimerClass(TimerClass& otherTC)
        : name{ otherTC.name + "_CC_" }
        , timeStamp{ otherTC.timeStamp } {
        std::cout << "copy-Constructor \n";
    };
    TimerClass& operator=(const TimerClass& otherTC) {
        std::cout << "copy-Assignment \n";
        if(&otherTC == this)
            return *this;
        this->timeStamp = otherTC.timeStamp;
        this->name = otherTC.name + "_CA_";
        return *this;
    };
    TimerClass(TimerClass&& otherTC)
        : name{ otherTC.name + "_MC_" }
        , timeStamp{ otherTC.timeStamp } {
        std::cout << "move-Constructor \n";
        otherTC.timeStamp.min();
        otherTC.name = otherTC.name + "_moved from me_";
    };
    TimerClass& operator=(TimerClass&& otherTC) {
        std::cout << "move-Assigment\n";
        if(&otherTC == this)
            return *this;
        this->timeStamp = otherTC.timeStamp;
        this->name = otherTC.name + "_MA_";
        otherTC.timeStamp.min();
        otherTC.name = otherTC.name + "_moved from me_";
        return *this;
    }
};
void calculateLong(TimerClass& tc) { // change tc type to call by value to see local parametr dealocating
    std::cout << "calculatelong ..... with timer: " << tc.name << "\n";
    for(int i = 0; i <= 1000000000; i++) {
    };
}

int main() {
    SetConsoleOutputCP(1250);
    std::cout << "----- ----- ----- ----- -----\n";
    TimerClass tm1{ "Pro_výpoèet" };
    calculateLong(tm1);
    TimerClass tm{ "Puòa" };         // normal constructor
    TimerClass tm2{ tm };             // copy constructor
    TimerClass tm3 = tm;              // copy constructor !!!!!
    tm3 = tm2;                        // copy assignment
    TimerClass tm4{ std::move(tm1) }; // move constructor
    TimerClass tm5{ tm };
    tm5 = std::move(tm3); // move assignment
}