/*
    *Filename: finance.h
    *Description?: finance declear
    *Author: matrix
    *Version: beta_0.1
    *Date: 2018.7.5 9:45
*/
#ifndef _FINANCE_H_
#define _FINANCE_H_
#include <conio.h>
#include <iostream>
#include <string>
using namespace std;
class Time_Deposit //���ڴ��
{
public:
  int time_deposit_add(double money, double D_Interest, int D_Time); //���ڴ��
  int time_deposit_sub();                                            //����ȡ��
  double show_time_deposit_sum();
  double show_time_deposit_interest();
  int show_time_deposit_date();
  int show_time_deposit_dtime();
  Time_Deposit();

private:
  double sum;        //���������
  double D_interest; //������Ϣ
  int Date;          //���ʱ��
  int D_time;        //Լ��ʱ��
};
class Finance : public Time_Deposit //������
{
public:
  int demand_deposit_add(double money);     //���ڴ��
  int demand_deposit_sub(double sub_money); //����ȡ��
  int settle_interest();                    //������Ϣ
  double show_balance();
  double show_demand_deposit();
  Finance();

private:
  double balance;         //�����������ڼ�����Ϣ
  double demand_deposit;  //���ڴ��
  double demand_interest; //������Ϣ
};

string report(int i)
{
  if (i == 1)
    return "����";
  else if (i == 2)
    return "��ʧ";
  else if (i == 3)
    return "����";
  else if (i == 4)
    return "����Ա";
  return "����";
}
string passwordin()
{
  while (1)
  {
    char password[100];
    int index = 0;
    while (1)
    {
      char ch;
      ch = getch();
      if (ch == 8) //�˸��
      {
        if (index != 0)
        {
          cout << char(8) << " " << char(8);
          index--;
        }
      }
      else if (ch == '\r') //�س���
      {
        password[index] = '\0';
        cout << endl;
        break;
      }
      else
      {
        cout << "*";
        password[index++] = ch;
      }
    }
    return password;
  }
}
int day_diff(int year_start, int month_start, int day_start, int year_end, int month_end, int day_end)
{
  int y2, m2, d2;
  int y1, m1, d1;

  m1 = (month_start + 9) % 12;
  y1 = year_start - m1 / 10;
  d1 = 365 * y1 + y1 / 4 - y1 / 100 + y1 / 400 + (m1 * 306 + 5) / 10 + (day_start - 1);

  m2 = (month_end + 9) % 12;
  y2 = year_end - m2 / 10;
  d2 = 365 * y2 + y2 / 4 - y2 / 100 + y2 / 400 + (m2 * 306 + 5) / 10 + (day_end - 1);
  return (d2 - d1);
}
#endif