/*
    *Filename: user.h
    *Description?: user class declear
    *Author: matrix
    *Version: beta_0.1
    *Date: 2018.7.5 10:02
*/
#ifndef _USER_H_
#define _USER_H_
#include "finance.h"
class User : public Finance
{
public:
  User *next;
  static int sum;                      //静态成员, 记录银行实时总人数
  static int cardsum;                  //静态成员，用于生成卡号
  int name_change(string newname);     //修改姓名, 输入新姓名, 修改私有成员name
  int email_change(string newemail);   //修改邮箱, 输入新邮箱, 修改私有成员email
  int report_loss();                   //挂失
  int change_passwd(string newpasswd); //修改密码, 输入新密码, 修改私有成员cardpasswd
  int change_status(int i);
  int is_email(string isemail); //找回密码, 输入邮箱，若正确则调用修改密码函数
  string showname();            //返回当前结点的姓名
  string showemail();           //返回当前结点的邮箱
  int showcardid();
  string showpasswd();
  int showstatus();
  int showall();
  int transfer_money(User *target, double money);
  User(string name1, string email1, string passwd1, int status1);
  //~User
private:
  string name;       //姓名
  string email;      //邮箱
  int cardid;        //卡号, 永久不变
  string cardpasswd; //密码
  int status;        //状态,  1：正常,  2：挂失,  3：销户 , 4:管理员
};
int showdate(int y, int m, int d, int passd)
{
  passd += (d - 1);
  d = 1;

  //计算当前月份天数
  int day = 0;
  switch (m)
  {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    day = 31;
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    day = 30;
    break;
  case 2:
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
    {
      day = 29;
    }
    else
    {
      day = 28;
    }
    break;
  }
  //更新日期和总天数
  if (passd - day >= 0)
  {
    if (m == 12)
    {
      y += 1;
      m = 1;
    }
    else
    {
      m += 1;
    }
    return showdate(y, m, d, passd - day); //递归
  }
  else
  {
    d += passd;
  }

  cout << y << "年" << m << "月" << d << "日" << endl;
  return 0;
}
#endif