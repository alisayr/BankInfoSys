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
class Time_Deposit //���ڴ��
{
public:    
	int time_deposit_add(double money, double D_Interest, int D_Time); //���ڴ��
	int time_deposit_sub();//����ȡ��
    Time_Deposit();
  private:    
    double sum;  //���������
    double D_interest;	//������Ϣ 
    int Date; //���ʱ��
    int D_time;//Լ��ʱ��
};
class Finance : public Time_Deposit //������
{
  public:
    int demand_deposit_add(double money);//���ڴ��
    int demand_deposit_sub(double sub_money);//����ȡ��
    int settle_interest();//������Ϣ
    Finance();

  private:
    double balance;         //�����������ڼ�����Ϣ
    double demand_deposit;  //���ڴ��
    double demand_interest; //������Ϣ
};
#endif