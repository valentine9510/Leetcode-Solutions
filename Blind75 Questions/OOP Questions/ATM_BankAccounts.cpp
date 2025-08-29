// 🏦 BASIC ATM / BANKING SYSTEM
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <string>

class BankAccount {
    int accountNumber;
    std::string ownerName;
    double balance;
public:
    BankAccount(int accNum, std::string owner, double initialBalance)
        : accountNumber(accNum), ownerName(owner), balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposited $" << amount << ". New balance: $" << balance << "\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Insufficient funds.\n";
        } else {
            balance -= amount;
            std::cout << "Withdrew $" << amount << ". New balance: $" << balance << "\n";
        }
    }

    void printBalance() const {
        std::cout << "Account #" << accountNumber << " - Balance: $" << balance << "\n";
    }

    int getAccountNumber() const { return accountNumber; }
    const std::string& getOwner() const { return ownerName; }
};

class ATM {
    std::unordered_map<int, std::unique_ptr<BankAccount>> accounts;
    int nextAccountId = 1001;

public:
    BankAccount& createAccount(std::string name, double initialDeposit) {
        int accId = nextAccountId++;
        accounts[accId] = std::make_unique<BankAccount>(accId, name, initialDeposit);
        std::cout << "Created account #" << accId << " for " << name << "\n";
        return *accounts[accId];
    }

    BankAccount* getAccount(int accNumber) {
        auto it = accounts.find(accNumber);
        return (it != accounts.end()) ? it->second.get() : nullptr;
    }
};

int main() {
    ATM atm;
    auto& aliceAcc = atm.createAccount("Alice", 500);
    auto& bobAcc = atm.createAccount("Bob", 300);

    aliceAcc.deposit(200);
    aliceAcc.withdraw(100);
    aliceAcc.printBalance();

    bobAcc.withdraw(500); // Should fail
    bobAcc.printBalance();

    return 0;
}
