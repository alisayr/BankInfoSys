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
class Time_Deposit //���ڴ��
{
    double sum;  //�����Ŀ
    int Date[3]; //�������
};
class Finance : public Time_Deposit //������
{
  public:
    int deposit_add();         //���ڴ�����Ա, ��¼
    int deposit_add(int time); //���ڴ���

  private:
    double balance;         //���������ܴ����Ϣ, ���ڼ��������Ϣ
    double demand_deposit;  //���ڴ��
    double demand_interest; //��������Ϣ
};

#endif