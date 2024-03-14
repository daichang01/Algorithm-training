#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance; // 私有属性，外部无法直接访问

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account(1000); // 初始余额1000
    account.deposit(500); // 存入500
    bool success = account.withdraw(200); // 尝试取出200
    cout << "Current balance: $" << account.getBalance() << endl; // 显示当前余额
    return 0;
}
