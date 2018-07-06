/*
    *Filename: finance.cpp
    *Description?: finance define
    *Author: Rebecca
    *Version: beta_0.1
    *Date: 2018.7.5 11:18
*/
#include"finance.h"
int Finance::demand_deposit_add(double money,double N_time)//活期存款 
{
	balance+=demand_interest;	//活期余额 
	demand_deposit=balance;	//活期存款 
	demand_interest=0;	//活期利息 
	demand_deposit=demand_deposit+money*0.0072*N_time;//利息 
	balance+=money;
	return 1;
}
int Finance::demand_deposit_sub(double balance,double demand_deposit,double sub_money)//活期取款 
{
	if (balance>=sub_money)
	{
		balance-=sub_money;
		demand_deposit-=sub_money;
		return 1;
	}
	if (balance<sub_money)
		return 0;
}
int Finance::time_deposit_add(double money,int time,double D_interest,int D_time)//定期存款 
{
  	if (sum>0)
		return 0;
	if (sum==0)
	{
		sum+=money;
		sum=sum+D_interest*D_time*sum; 
		return 1;
	}
}
int Finance::time_deposit_sub(double time_deposit,double sub_money,double D_time,double N_time)//定期取款 
{
	if(D_time>N_time)
		return 0;
	if(D_time<N_time)
	{
		if (sum>=sub_money)
		{
			sum-=sub_money;
			time_deposit-=sub_money;
			return 1;
		}
		if (sum<sub_money)
			return 0;
	}
}
Time_Deposit::Time_Deposit()
{
        sum=0;
        D_interest=0;
        Date[3]={0,0,0};
        D_time=0;
}
Finance::finance()
{
        balance=0;
        demand_deposit=0;
        demand_interest=0;
}