#include <iostream>
#include "HighCreditAccount.h"
using namespace std;

HighCreditAccount::HighCreditAccount(int ID, int balance, char* cname, int rate, int special)
	:SavingAccount(ID, balance+balance*rate/100, cname, rate), m_SpecialRate(special) {};
void HighCreditAccount::Deposit(int money) {
	int rate;
	rate = money * m_SpecialRate / 100;
	Account::Deposit(rate);
}