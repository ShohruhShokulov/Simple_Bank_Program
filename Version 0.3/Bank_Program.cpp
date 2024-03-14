// Lab10_Exercise1
#include <iostream>
using namespace std;
#define MAX_ACC_NUM 100
#define _CRT_SECURE_NO_WARNINGS // for not warning strcpy_s
const int LEN = 100;
class Account {
private:
	int m_accID; //class variables
	int m_balance;
	char* m_cusName;
public:
	Account(int a, int b, char* c) : m_accID(a), m_balance{ b }, m_cusName(c) { // copy constructor
		m_cusName = new char[LEN + 1];  // allocating memory and copying it
		strcpy_s(m_cusName, LEN + 1, c);
	};

	~Account() { // destructor which deletes m_cusName pointer variable
		delete[] m_cusName;
	}

	Account(const Account& cp) {
		m_accID = cp.m_accID;
		m_balance = cp.m_balance;
		m_cusName = new char[strlen(cp.m_cusName) + 1];
		strcpy_s(m_cusName, strlen(cp.m_cusName), cp.m_cusName);
	}

	int GetAccID(void) const { // returns user id
		return m_accID;
	}
	void Deposit(int money) { // pluses money to balance
		m_balance += money;

	}
	int Withdraw(int money) {
		if (m_balance >= money) {
			m_balance -= money;
			return money;
		}
	}
	void ShowAccInfo(void) const { //Showing all info
		cout << "Account ID: " << m_accID << endl;
		cout << "Name: " << m_cusName << endl;
		cout << "Balance: " << m_balance << endl;
	}
};



Account* accArr[MAX_ACC_NUM]; // Account array
int accNum = 0; // # of accounts
enum class bank { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };//enumiration for menu selection

void ShowMenu(void) {
	// Display menu options
	std::cout << "----- Bank Menu -----" << std::endl;
	std::cout << "1. Make Account" << std::endl;
	std::cout << "2. Deposit Money" << std::endl;
	std::cout << "3. Withdraw Money" << std::endl;
	std::cout << "4. Show All Account Information" << std::endl;
	std::cout << "5. Exit" << std::endl;
}
void MakeAccount(void) {
	int id, balance;
	char name[LEN];

	//getting info from user
	cout << "Account ID: ";
	cin >> id;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Initial Balance: ";
	cin >> balance;
	accArr[accNum] = new Account{ id,balance,name };
	accNum++;
}

int GetAccIdx(int id) { // the function which returns index of the account number
	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id)
			return i;
	}
	return -1;
}

void DepositMoney(void) {
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
void WithdrawMoney(void) { // Function for withdrawing money
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
void ShowAllAccInfo(void) { // showing all info
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
	}

}

int main(void) {
	int choice, i;
	while (1) {
		ShowMenu();
		cout << "Select menu: ";
		cin >> choice;
		cout << endl;
		switch (bank(choice)) {
		case bank::MAKE:
			MakeAccount();
			break;
		case bank::DEPOSIT:
			DepositMoney();
			break;
		case bank::WITHDRAW:
			WithdrawMoney();
			break;
		case bank::INQUIRE:
			ShowAllAccInfo();
			break;
		case bank::EXIT:
			for (i = 0; i < accNum; i++)
				delete accArr[i];
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}
