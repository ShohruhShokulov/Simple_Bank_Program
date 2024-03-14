#include "AccountHandler.h"
#include <iostream>
using namespace std;

enum class bank { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };//enumiration for menu selection

int main(void) {
	AccountHandler manager;
	int choice;
	bool run = true;
	while (run) {
		manager.ShowMenu();
		cout << "Select menu: ";
		cin >> choice;
		cout << endl;
		switch (bank(choice)) {
		case bank::MAKE:
			manager.MakeAccount();
			break;
		case bank::DEPOSIT:
			manager.DepositMoney();
			break;
		case bank::WITHDRAW:
			manager.WithdrawMoney();
			break;
		case bank::INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case bank::EXIT:
			run = false;
			break;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}