#include <cstddef>
#include <iostream>
#include <type_traits>
#include <windows.h>
// 6-5. Using the example from Chapter 5, make Banka template class that accepts a template parameter. Use this type parameter as
// the type of an  account rather than long. Verify that your code still works using a Bank<long> class.
// 6-6. Implement an Account class and instantiate a Bank<Account>. Implement functions in Account to keep track of balances.
// 6-7. Make Account an interface. Implement a CheckingAccount and SavingsAccount. Create a program with several checking and
// savings accounts. Use a  Bank<Account>to make several transactions between the accounts.

struct Account {
public:
    long accountID;
    float balance; // poznámka úèetního :-) vklad klientù je pro banku závazek,
                   // úvìr pro klienta je pro banku pohledávka

    Account(long id)
        : accountID{ id }
        , balance{ 10000 } {
        std::cout << "New Account ID: " << accountID << " created \n";
    }
    virtual ~Account() = default;
    bool virtual debitAccount(float amount) = 0;
    bool virtual creditAccount(float amount) = 0;
};

struct CheckingAccount : Account {
    //    poznámka úèetního :-) vklad klientù je pro banku závazek,
    CheckingAccount(long id)
        : Account{ id } {
    }
    ~CheckingAccount() = default;
    bool debitAccount(float amount) override {
        if((balance - amount) >= 0) {
            balance -= amount;
            std::cout << "New balance of payable to Client acc: " << accountID << " is " << balance << "\n";
            return true;
        } else {
            std::cout << "Transaction cancelled - not sufficent funds \n";
            return false;
        }
    }
    bool creditAccount(float amount) override {
        balance += amount;
        std::cout << "New balance of payable to Client acc: " << accountID << " is " << balance << "\n";
        return true;
    }
};

struct LoanAccount : Account {
    // úvìr pro klienta je pro banku pohledávka
    LoanAccount(long id)
        : Account{ id } {
    }
    ~LoanAccount() = default;
    bool creditAccount(float amount) override {
        if((balance - amount) >= 0) {
            balance -= amount;
            std::cout << "New balance of receivable to Client  acc: " << accountID << " is " << balance << "\n";
            return true;
        } else {
            std::cout << "Transaction cancelled - not sufficent funds \n";
            return false;
        }
    }
    bool debitAccount(float amount) override {
        balance += amount;
        std::cout << "New balance of receivable to Client acc: " << accountID << " is " << balance << "\n";
        return true;
    }
};

template <typename T> struct Bank {
private:
public:
    void make_transfer(T& from, T& to, float amount) { // without reference to T it DOES NOT WORK - strange :-(
                                                       // do not loose hope Zbyòa - here comes explanation :-)
        // Account is abstract class means not allowed have instance means only pass pointer which will be in runtime
        // cassed to one of derived classes see project Chapter_5_5_Runtime_Polymorphism
        // an other fix could be in instantiate the template eg. Bank<Account&>
        // jojo a v Pascalu se proto defaultnì pøedává class referencí a nemusíš skoro vùbec øešit pointery (NIM ?)
        std::cout << "DEBIT  Account ID: " << from.accountID << " " << amount << "\n"
                  << "CREDIT Account ID: " << to.accountID << " " << amount << "\n";
        from.debitAccount(amount);
        to.creditAccount(amount);
    }
};

int main() {
    SetConsoleOutputCP(1250);
    CheckingAccount prvniUcet{ 1000 };
    LoanAccount druhyUcet{ 2000 };
    Bank<Account> bank{}; // other fix: Bank<Account&> bank{}; see explanation near void make_tranfer( ... )
    bank.make_transfer(prvniUcet, druhyUcet, 49.95);
    bank.make_transfer(prvniUcet, druhyUcet, 20.00);
    return 0;
}
