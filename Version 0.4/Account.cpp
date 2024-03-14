#include "Account.h"
#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS // for not warning strcpy_s
const int LEN = 100;

Account::Account(int a, int b, char* c) : m_accID(a), m_balance{ b }, m_cusName(c) { // copy constructor
	m_cusName = new char[LEN + 1];  // allocating memory and copying it
	strcpy_s(m_cusName, LEN + 1, c);
};

Account::~Account() { // destructor which deletes m_cusName pointer variable
	delete[] m_cusName;
}

Account::Account(const Account& cp) {
	m_accID = cp.m_accID;
	m_balance = cp.m_balance;
	m_cusName = new char[strlen(cp.m_cusName) + 1];
	strcpy_s(m_cusName, strlen(cp.m_cusName), cp.m_cusName);
}

int Account::GetAccID(void) const { // returns user id
	return m_accID;
}
void Account::Deposit(int money) { // pluses money to balance
	m_balance += money;

}
int Account::Withdraw(int money) {
	if (m_balance >= money) {
		m_balance -= money;
		return money;
	}
	return -1;
}
void Account::ShowAccInfo(void) const { //Showing all info
	cout << "Account ID: " << m_accID << endl;
	cout << "Name: " << m_cusName << endl;
	cout << "Balance: " << m_balance << endl;
	cout << endl;
}
