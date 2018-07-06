/*
    *Filename: user.cpp
    *Description?: user class define
    *Author: matrix
    *Version: beta_0.1
    *Date: 2018.7.5 14:27
*/
#include "user.h"
int User::sum = 0;     //初始化sum=0
int User::cardsum = 100; //初始化cardsum=0
/*
User::User(string name1, string email1, string passwd1, int status1):name(name1),email(email1),cardpasswd(passwd1),status(status1)
{
    sum++;
    cardsum++;
    cardid = cardsum;
    next=NULL;
}
*/
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