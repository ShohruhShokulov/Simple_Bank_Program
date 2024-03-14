#include "AccountHandler.h"
#include <iostream>
using namespace std;
const int LEN = 100;

int AccountHandler:: GetAccIdx(int id) const {
	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id)
			return i;
	}
	return -1;
}

AccountHandler::AccountHandler() : accNum(0) {
}
AccountHandler:: ~AccountHandler() {
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}
void AccountHandler::ShowMenu(void) const {
	// Display menu options
	std::cout << "----- Bank Menu -----" << std::endl;
	std::cout << "1. Make Account" << std::endl;
	std::cout << "2. Deposit Money" << std::endl;
	std::cout << "3. Withdraw Money" << std::endl;
	std::cout << "4. Show All Account Information" << std::endl;
	std::cout << "5. Exit" << std::endl;
}
void AccountHandler::MakeAccount(void) {
	int type;

	cout << "[Select Account type]" << endl;
	cout << "Saving Acoount \nHigh Credit Account" << endl;
	cout << "Select: ";
	cin >> type;

	switch (type) {
	case 1:
		MakeSavingAccount();
		break;
	case 2:
		MakeHighCreditAccount();
		break;
	default: 
		cout << "Invalid Account type!!" << endl;
		break;
	}
}

void AccountHandler::MakeSavingAccount(void) {
	int id, balance, rate;
	char name[LEN];
	cout << "[Make Saving Account]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Customer Name: ";
	cin >> name;
	cout << "Depeosit amount: ";
	cin >> balance;
	cout << "Interest Rate: ";
	cin >> rate;

	accArr[accNum] = new SavingAccount(id, balance, name, rate);
	accNum++;
}

void AccountHandler::MakeHighCreditAccount(void) {
	int id, balance, rate, special, specialRate;
	char name[LEN];
	cout << "[Make High Credit Account]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Customer Name: ";
	cin >> name;
	cout << "Deposit amount: ";
	cin >> balance;
	cout << "Interest Rate: ";
	cin >> rate;
	cout << "Credit Rating(A:1, B : 2, C : 3): ";
	cin >> special;
	switch (special) {
	case 1:
		specialRate = 7;
		break;
	case 2:
		specialRate = 4;
		break;
	case 3:
		specialRate = 2;
		break;
	default:
		cout << "Invalid credit rating." << endl;
		return;
	}

	accArr[accNum] = new HighCreditAccount(id, balance, name, rate, specialRate);
	accNum++;
}

void AccountHandler::DepositMoney(void) {
	cout << "Deposit" << endl;
	int id, money;
	int idx; // variable for the index of the account inputed by user
	cout << "Enter Account ID: ";
	cin >> id;
	idx = GetAccIdx(id);
	if (idx == -1)
		cout << "Account Not Found!" << endl;
	else {
		cout << "Enter the amount to deposit: ";
		cin >> money;
		accArr[idx]->Deposit(money);
		cout << "Transaction Completed!" << endl;
	}
}
void AccountHandler::WithdrawMoney(void) { // Function for withdrawing money
	cout << "Withdraw" << endl;
	int id, balance;
	int idx;
	cout << "Enter Account ID: ";
	cin >> id;
	idx = GetAccIdx(id); // get the index of the account
	if (idx == -1) {
		cout << "Account Not Found!" << endl;
	}
	else {
		cout << "Enter the amount to withdraw: ";
		cin >> balance;
		accArr[idx]->Withdraw(balance);
		cout << "Transaction completed!" << endl;
	}
}
void AccountHandler::ShowAllAccInfo(void) const {
	cout << "Showing All Info" << endl;
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
	}
}