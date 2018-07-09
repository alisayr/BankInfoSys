/*
    *Filename: user.cpp
    *Description?: user class define
    *Author: matrix
    *Version: beta_0.1
    *Date: 2018.7.5 14:27
*/
#ifndef _USER_CPP_
#include "user.h"
#include "finance.cpp"
int User::sum = 0;       //初始化sum=0
int User::cardsum = 100; //初始化cardsum=0

User::User(string name1, string email1, string passwd1, int status1) : name(name1), email(email1), cardpasswd(passwd1), status(status1)
{
    sum++;
    cardsum++;
    cardid = cardsum;
    next = NULL;
}

int User::name_change(string newname)
{
    name = newname;
    return 1;
}
int User::email_change(string newemail)
{
    email = newemail;
    return 1;
}
int User::report_loss()
{
    status = 2;
    return 1;
}
int User::change_passwd(string newpasswd)
{
    cardpasswd = newpasswd;
    return 1;
}
int User::is_email(string isemail)
{
    if (email != isemail)
        return 0;
    else
        return 1;
}
string User::showname()
{
    return name;
}
string User::showemail()
{
    return email;
}
int User::showcardid()
{
    return cardid;
}
string User::showpasswd()
{
    return cardpasswd;
}
int User::showstatus()
{
    return status;
}
int User::transfer_money(User *target, double money)
{
    if (target->showstatus() == 3) //目标账户处于销户状态
        return 2;
    else if (target->showstatus() == 4) //目标账户是管理员
        return 3;
    else if (this->demand_deposit_sub(money))
    {

        target->demand_deposit_add(money);
        return 1;
    }
    else
        return 0; //扣款失败，余额不足
}
int User::showall()
{
    cout << "卡号：";
    cout << showcardid() << "\t"
         << "姓名：";
    cout << showname() << "   "
         << "邮箱：";
    cout << showemail() << "\t"
         << "状态：";
    cout << report(showstatus()) << "\t"
         << "余额：";
    cout << show_balance() << "\t"
         << "活期存款：";
    cout << show_demand_deposit() <<"元"<< "\t"
         << "定期存款：";
    cout << show_time_deposit_sum() <<"元"<< "\t"
         << "定期利息：";
    cout << show_time_deposit_interest()<<"元" << "\t"
         << "存款时间：";
    cout << show_time_deposit_date() << "\t"
         << "存款时长：";
    cout << show_time_deposit_dtime() <<"天"<< endl;
    return 1;
}
#endif