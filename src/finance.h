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
class Time_Deposit //定期存款
{
public：
	int time_deposit_add(double money,int time,double D_interest); //定期存款函数
	int time_deposit_sub(double sub_money,double N_time);//定期取款函数 
private： 
    double sum;  //存款数目
    double D_interest;	//定期利息 
    int Date[3]; //存款日期
    int D_time;//约定时长 

};
class Finance : public Time_Deposit //金融类
{
  public:
    int demand_deposit_add(double money,double N_time);         //活期存款函数成员, 记录
    
    int demand_deposit_sub(double sub_money);//活期取款函数 

  private:
    double balance;         //总余额活期总存款利息, 用于计算活期利息
    double demand_deposit;  //活期存款
    double demand_interest; //活期总利息
};

#endif
