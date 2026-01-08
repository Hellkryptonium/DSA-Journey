#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    double depsoti(double amount) {
        if(amount >= 0) {
            return balance + amount;
        } else {
            return -1;
        }  
    }

    double withdraw(double amount){
        if(amount <= balance) {
            return balance - amount;
        } else  {
            return -1;
        }
    }

    double getBalance() {
       return balance; 
    }
};


int main() {
    BankAccount A1;

    A1.depsoti(1000);
    cout << A1.getBalance() << endl;
    A1.withdraw(100);
    cout << A1.withdraw(100);
    return 0;
}