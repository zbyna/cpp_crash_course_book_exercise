#include <iostream>
#include <windows.h>

// 5-1. You didn’t implement an accounting system in your Bank. Design an interface called AccountDatabase that canretrieve and set
// amounts in bank accounts (identified by a long id).
// 5-2. Generate an InMemoryAccountDatabase that implements AccountDatabase.
// 5-3. Add an AccountDatabase reference member to Bank. Use constructor injection to add an InMemoryAccountDatabaseto the Bank.
// 5-4. Modify ConsoleLogger to accept a const char* at construction. When Consol eLogger logs, prepend this string to the logging
// output.Notice that you can modify logging behavior without having to modify Bank.

struct Logger {
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger {
    ConsoleLogger(const char* strToApp)
        : stringToAppend{ strToApp } {
    }
    ConsoleLogger(const ConsoleLogger& other) = default; // error message struct has pointer data members but does not override
    ConsoleLogger& operator=(const ConsoleLogger& other) = default; // copy constructor and copy assignment - Werror=effc++

    void log_transfer(long from, long to, double amount) override {
        std::cout << stringToAppend << " [cons] " << from << " -> " << to << ":" << amount << "\n";
    }

private:
    const char* stringToAppend;
};

struct FileLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        std::cout << "[file]" << from << " " << to << " " << amount << "\n";
    }
};

struct AccountDatabase {
    virtual ~AccountDatabase() = default;
    virtual void retrieveAndSet(long from, long to, double amount) = 0;
};

struct InMemoryAccountDatabase : AccountDatabase {
    void retrieveAndSet(long from, long to, double amount) override {
        std::cout << "DEBIT  Account ID: " << from << " " << amount << "\n"
                  << "CREDIT Account ID: " << to << " " << amount << "\n";
    }
};

struct Bank {
private:
    Logger* logger{}; // logger is abstract class means not allowed have instance means only pass pointer which will be in runtime
                      // cassed to one of derived classes
    InMemoryAccountDatabase& accDatabase; // not possible to initialise b/c reference is implicitly dereference CONSTANT pointer
public:
    Bank(InMemoryAccountDatabase& accD)
        : accDatabase{ accD } {
    }
    void set_logger(Logger* new_logger) {
        logger = new_logger;
    }
    void make_transfer(long from, long to, double amount) {
        if(logger)
            logger->log_transfer(from, to, amount);
        accDatabase.retrieveAndSet(from, to, amount);
    }
};

int main() {
    SetConsoleOutputCP(1250);
    ConsoleLogger console_logger{ "Appended string " };
    FileLogger file_logger;
    InMemoryAccountDatabase bankAccounts;
    Bank bank{ bankAccounts };
    bank.set_logger(&console_logger);
    bank.make_transfer(1000, 2000, 49.95);
    bank.set_logger(&file_logger);
    bank.make_transfer(2000, 4000, 20.00);
    return 0;
}
