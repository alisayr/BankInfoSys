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
public��
	int time_deposit_add(double money,int time,double D_interest); //���ڴ���
	int time_deposit_sub(double sub_money,double N_time);//����ȡ��� 
private�� 
    double sum;  //�����Ŀ
    double D_interest;	//������Ϣ 
    int Date[3]; //�������
    int D_time;//Լ��ʱ�� 

};
class Finance : public Time_Deposit //������
{
  public:
    int demand_deposit_add(double money,double N_time);         //���ڴ�����Ա, ��¼
    
    int demand_deposit_sub(double sub_money);//����ȡ��� 

  private:
    double balance;         //���������ܴ����Ϣ, ���ڼ��������Ϣ
    double demand_deposit;  //���ڴ��
    double demand_interest; //��������Ϣ
};

#endif
