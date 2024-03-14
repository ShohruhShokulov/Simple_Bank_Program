#include <iostream>
#include "bank.h"
#define _CTR_SECURE_NO_WARNINGS
using namespace std;
Account accArr[MAX_ACC_NUM]; // Account array
int accNum = 0; // # of accounts
void ShowMenu(void) {
	cout << "-----Menu------" << endl;
	cout << "1. Make Accout" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdrawal" << endl;
	cout << "4. Display all" << endl;
	cout << "5. Delete Account" << endl;
	cout << "6.Change information" << endl;
	cout << "7. Exit program" << endl;
}
void MakeAccount(void) {
	int id;
	char name[NAME_LEN];
	int balance;
	if (accNum >= MAX_ACC_NUM) {
		cout << "Sorry! cannot make an accout anymore." << endl;
		return;
	}
	cout << "[Make Account]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Customer Name: ";
	cin >> name;
	cout << "Deposit amount: ";
	cin >> balance;
	cout << endl;
	if (GetAccIdx(id) != -1) {
		cout << "Error: Existing account ID" << endl;
		return;
	}
	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy_s(accArr[accNum].cusName,sizeof(accArr[accNum].cusName),name);
	accNum++;
}
void DepositMoney(void) {
	int money;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Deposit amount: ";
	cin >> money;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			accArr[i].balance += money;
			cout << "Deposit completed"
				<< endl << endl;
			return;
		}
	}
	cout << "This ID is not valid." << endl
		<< endl;
}
void WithdrawMoney(void) {
	int money;
	int id;
	cout << "[Withdrawal]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Withdrawal amount: ";
	cin >> money;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			if (accArr[i].balance < money) {
				cout << "Not enough balance"
					<< endl << endl;
				return;
			}
			accArr[i].balance -= money;
			cout << "Withdrawal completed"
				<< endl << endl;
			return;
		}
	}
	cout << "This ID is not valid." << endl
		<< endl;
}
void ShowAllAccInfo(void) {
	for (int i = 0; i < accNum; i++) {
		cout << "Account ID: " << accArr[i].accID << endl;
		cout << "Name: " << accArr[i].cusName << endl;
		cout << "Balance: " << accArr[i].balance << endl << endl;
	}
}
int GetAccIdx(int id) {
	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			return i;
		}
	}
	return -1;
}
void Delete_account(void) {
	int id;
	cout << "Account number to Delete: ";
	cin >> id;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			accArr[i].accID == accArr[i + 1].accID;
			cout << "Account with "<<accArr[i].accID<<" number has been deleted successfully!" << endl;
			return;
		}
	}
	cout << "Sorry! There is no account number like this!" << endl << endl;
	accNum--;
}
void Change_info(void) {
	char name[NAME_LEN];
	int Id, newId;
	cout << "----Information Change----" << endl;
	cout << "Enter your Account number: ";
	cin >> Id;
	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == Id) {
			cout << "New name: ";
			cin >> name;
			cout << "New Account Number: ";
			cin >> newId;
			accArr[i].accID = newId;
			strcpy_s(accArr[i].cusName, sizeof(accArr[accNum].cusName), name);
			cout << endl;
			return;

		}
		
	}
	cout << "Invalid Account Number!!!"<<endl;
}