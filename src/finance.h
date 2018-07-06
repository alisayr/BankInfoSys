/*
    *Filename: finance.h
    *Description?: finance declear
    *Author: matrix
    *Version: beta_0.1
    *Date: 2018.7.5 9:45
*/
#ifndef _FINANCE_H_
#include <iostream>
#include <string>
using namespace std;
extern int StartDate[3];
extern int PassDay;
class Time_Deposit //定期存款
{
public:    
	int time_deposit_add(double money, double D_Interest, int D_Time); //定期存款
	int time_deposit_sub();//定期取款
    Time_Deposit();
  private:    
    double sum;  //定期总余额
    double D_interest;	//定期利息 
    int Date; //存款时间
    int D_time;//约定时长
};
class Finance : public Time_Deposit //金融类
{
  public:
    int demand_deposit_add(double money);//活期存款
    int demand_deposit_sub(double sub_money);//活期取款
    int settle_interest();//结算利息
    Finance();

  private:
    double balance;         //活期总余额，用于计算利息
    double demand_deposit;  //活期存款
    double demand_interest; //活期利息
};
#endif