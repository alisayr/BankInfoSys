/*
    *Filename: finance.cpp
    *Description?: finance define
    *Author: Rebecca
    *Version: beta_0.1
    *Date: 2018.7.5 11:18
*/
#ifndef _FINANCE_CPP_
#define _FINANCE_CPP_
#include "finance.h"
int StartDate[3];
int NowDate[3];
int PassDay;
double interest[7] = {0.003, 0.0135, 0.0155, 0.0175, 0.0225, 0.0275, 0.0275};
int time_deposit[6] = {90, 180, 360, 720, 1080, 1800};
int Finance::settle_interest()
{
	demand_deposit += demand_interest; //活期利息加入活期存款
	balance = demand_deposit;		   //同步
	date = PassDay;
	demand_interest = 0; //活期利息清零
	return 1;
}
int Finance::demand_deposit_add(double money) //活期存款
{
	settle_interest();
	demand_deposit += money;  //活期余额加入存款
	balance = demand_deposit; //同步
	return 1;
}
int Finance::demand_deposit_sub(double money) //活期取款
{
	if (balance >= money)
	{
		settle_interest();
		demand_deposit -= money;  //活期存款扣除取款
		balance = demand_deposit; //同步
		return 1;
	}
	if (balance < money)
		return 0;
	return 0;
}
double Finance::time_deposit()
{
	double i;
	i = time_deposit_sub();
	if (i == 0)
		return 0;
	else if (i == -1)
		return -1;
	else if (i == -2)
		return -2;
	else
	{
		demand_deposit_add(i);
		return i;
	}
}
int Time_Deposit::time_deposit_add(double money, double D_Interest, int D_Time) //定期存款
{
	if (sum > 0)
		return 0;
	if (sum == 0)
	{
		Date = PassDay;
		sum += money;
		D_time = D_Time;
		D_interest = D_Interest;
		return 1;
	}
	return 0;
}
double Time_Deposit::time_deposit_sub() //定期取款
{
	double i;
	i = sum + D_interest;
	if (sum > 0)
	{
		if (Date + D_time > PassDay)
			return -1;
		if (Date + D_time < PassDay)
		{
			sum = 0;
			D_interest = 0;
			Date = 0;
			D_time = 0;
			return i;
		}
	}
	else
		return 0;
	return -2;
}
double Time_Deposit::show_time_deposit_sum()
{
	return sum;
}
double Time_Deposit::show_time_deposit_interest()
{
	return D_interest;
}
int Time_Deposit::show_time_deposit_date()
{
	return Date;
}
int Time_Deposit::show_time_deposit_dtime()
{
	return D_time;
}
Time_Deposit::Time_Deposit()
{
	sum = 0;
	D_interest = 0;
	Date = 0;
	D_time = 0;
}
double Finance::show_balance()
{
	return balance;
}
double Finance::show_demand_deposit()
{
	return demand_deposit;
}
int Finance::show_date()
{
	return date;
}
double Finance::get_interest()
{
	demand_interest = demand_deposit*(PassDay - date) / 360 * interest[0];
	balance += demand_interest;
	demand_deposit += demand_interest;
	date = PassDay;
	return demand_interest;
}
Finance::Finance()
{
	balance = 0;
	demand_deposit = 0;
	demand_interest = 0;
	date = PassDay;
}
#endif