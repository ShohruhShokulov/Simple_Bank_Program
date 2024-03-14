#include <iostream>
#include "SavingAccount.h"
using namespace std;

SavingAccount::SavingAccount(int ID, int balance, char* cname, int rate) : Account(ID, balance+balance*rate/100, cname), 
                             m_InterestRate(rate) {};
void SavingAccount::Deposit(int money) {
    int interest;
    interest = (money * m_InterestRate) / 100;
    Account::Deposit(money+interest);
}