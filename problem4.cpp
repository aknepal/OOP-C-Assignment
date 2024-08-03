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
    protected:
        int accountNumber;
        float balance;

    public:
        virtual void depositMoney(float) = 0;
        virtual void withdrawMoney(float) = 0;
};

class SavingsAccount : public Account{
    int withdrawalLimit = 6;
    float penalty = 0.01;
    public:
        void depositMoney(float amount) override{
            balance += amount;
        }
        void withdrawMoney(float amount) override{
            if (withdrawalLimit > 0){
                if(balance > amount){
                    withdrawalLimit--;
                    balance -= amount;
                } else {
                    cout << "Insufficient Balance" << endl;
                }
            } else {
                char ch;
                cout << "You have reached your withdrawal limit. If you still wish to continue, 1%% penalty will be charged from you account. Do you wish to continue(y/n): ";
                if(ch == 'y'){
                    balance -= amount * (1 + penalty);
                } else {
                    cout << "Transaction cancelled!";
                }
            }
        }
};

class CheckingAccount : public Account{
    float withdrawalLimit = 100000;
    public:
        void depositMoney(float amount) override{
            balance += amount;
        }
        void withdrawMoney(float amount) override{
            if(amount > withdrawalLimit){
                cout << "Sorry you cannot withdraw more than " << withdrawalLimit << " at once." << endl;
            } else {
                if(balance < amount){
                    cout << "Insufficient Balance" << endl;
                } else {
                    balance -= amount;
                }
            }
        }
};

