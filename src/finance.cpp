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
int PassDay;
int Finance::settle_interest()
{
	demand_deposit += demand_interest; 	//������Ϣ������ڴ��
	balance = demand_deposit;			//ͬ��
	demand_interest = 0;				//������Ϣ����
	return 1;
}
int Finance::demand_deposit_add(double money) //���ڴ��
{
	settle_interest();
	demand_deposit += money;			//������������
	balance = demand_deposit;			//ͬ��
	return 1;
}
int Finance::demand_deposit_sub(double money) //����ȡ��
{
	if (balance >= money)
	{
		settle_interest();
		demand_deposit -= money;		//���ڴ��۳�ȡ��
		balance = demand_deposit;		//ͬ��
		return 1;
	}
	if (balance < money)
		return 0;
	return 0;
}
int Time_Deposit::time_deposit_add(double money, double D_Interest, int D_Time)//���ڴ��
{
	if (sum > 0)
		return 0;
	if (sum == 0)
	{
		sum += money;
		D_time = D_Time;
		D_interest = D_Interest;
		return 1;
	}
	return 0;
}
int Time_Deposit::time_deposit_sub()//����ȡ��
{
	if (Date+D_time > PassDay)
		return 0;
	if (Date+D_time < PassDay)
	{
		sum = 0;
		D_interest = 0;
		Date = 0;
		D_time = 0;
		return 1;
	}
	return 0;
}
Time_Deposit::Time_Deposit()
{
	sum = 0;
	D_interest = 0;
	Date= 0;
	D_time = 0;
}
Finance::Finance()
{
	balance = 0;
	demand_deposit = 0;
	demand_interest = 0;
}
#endif