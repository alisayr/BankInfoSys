/*
    *Filename: finance.h
    *Description£: finance declear
    *Author: matrix
    *Version: beta_0.1
    *Date: 2018.7.5 9:45
*/
#ifndef _FINANCE_H_
#include <iostream>
#include <string>
using namespace std;
class Time_Deposit                  //????
{
    double sum;                     //????
    int Date[3];                    //????
};
class Finance:public Time_Deposit   //???
{
  public:
    int deposit_add();              //??????
    int deposit_add(int time);        //??????

  private:
    double balance;                 //??? = ????? + ??? ????????
    double demand_deposit;          //????
    double demand_interest;         //?????
};

#endif