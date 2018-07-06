/*
    *Filename: user.h
    *Description?: user class declear
    *Author: matrix
    *Version: beta_0.1
    *Date: 2018.7.5 10:02
*/
#ifndef _USER_H_
#include "finance.h"
class User : public Finance
{
  public:
    User *next;
    static int sum;                         //静态成员, 记录银行实时总人数
    static int cardsum;                     //静态成员，用于生成卡号
    int name_change(string newname);        //修改姓名, 输入新姓名, 修改私有成员name
    int email_change(string newemail);      //修改邮箱, 输入新邮箱, 修改私有成员email
    int report_loss();                      //挂失 
    int change_passwd(string newpasswd);    //修改密码, 输入新密码, 修改私有成员cardpasswd
    int is_email(string isemail);          //找回密码, 输入邮箱，若正确则调用修改密码函数
    string showname();                      //返回当前结点的姓名
    string showemail();                     //返回当前结点的邮箱
    int showcardid();
    string showpasswd();
    int showstatus();
    int transfer_money(User *target,double money);
    User(string name1, string email1, string passwd1, int status1);
    //~User
  private:
    string name;    //姓名
    string email;   //邮箱
    int cardid;     //卡号, 永久不变
    string cardpasswd; //密码
    int status;     //状态,  1：正常,  2：挂失,  3：销户 , 4:管理员
};
#endif