/*
Create a base class Account with data members accountNumber and balance.
Derive two classes SavingsAccount and CheckingAccount from Account.
Implement polymorphic behavior where the base class pointer can point to objects of
derived classes, and call their respective member functions to deposit and withdraw
money, applying specific rules for each account type.
*/

#include<iostream>

using namespace std;

class Account{
    int accountNumber;
    float balance;

    public:
        virtual void depositMoney() = 0;
        virtual void withdrawMoney() = 0;
};

class SavingsAccount : public Account{
    public:
        void depositMoney() override{
            cout << "deposit function called from within savings account";
        }
        void withdrawMoney() override{
            cout << "withdraw function called from within savings account";
        }
};

class CheckingAccount : public Account{
    public:
        void depositMoney() override{
            cout << "deposity function called from within checking account";
        }
        void withdrawMoney() override{
            cout << "withdraw function called from within checking account";
        }
};

int main(){
    
}