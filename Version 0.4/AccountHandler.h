#pragma once
#include "Account.h"
#include "HighCreditAccount.h"
#include "SavingAccount.h"

class AccountHandler {
private:
	Account* accArr[MAX_ACC_NUM];
	int accNum;
	int GetAccIdx(int id) const;

public:
	AccountHandler();
	~AccountHandler();
	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;
	void MakeSavingAccount(void);
	void MakeHighCreditAccount(void);

};




