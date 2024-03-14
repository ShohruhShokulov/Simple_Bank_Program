#pragma once
#ifndef _Account_h
#define _Account_h
#define MAX_ACC_NUM 100

class Account {
private:
	int m_accID; //class variables
	int m_balance;
	char* m_cusName;
public:
	Account(int a, int b, char* c);
	~Account();
	Account(const Account& cp);
	int GetAccID(void) const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo(void) const;

	
};

#endif // _Account_h