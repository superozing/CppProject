#pragma once
#include <iostream>
#include <string>

enum depositType
{
	자유입출금식예금 = 1,
	정기예금 = 2
};

struct PersonalInfo
{
	std::string pi_id;
	std::string pi_password;

	std::string pi_name;
	std::string pi_gender;
	int			pi_age;
};

struct Deposit
{
	int de_depositType;
	int de_money;
	int de_firstDepositDate;
	int de_date;
};


class Account
{
private:
	static int ac_accountCount;
	static int ac_entireFund;

	PersonalInfo	ac_personalInfo;
	Deposit			ac_deposit;

public:
	Account();
};

