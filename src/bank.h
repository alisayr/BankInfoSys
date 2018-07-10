/*
    *Filename: bank.h
    *Description?: bank class declear
    *Author: matrix
    *Version: beta_0.1
    *Date: 2018.7.5 10:17
*/
#ifndef _BANK_H_
#define _BANK_H_
#include "user.h"
class Bank
{
  public:
    User *head;
    User *tail;
    User *log;
    User *ptr;                               //备用指针
    int CBank(string passwdadm);             //建立新的空银行数据库
    int Login(int cardid, string passwd); //登陆，使ptr备用指针指向
    int Logout();                            //登出
    int Logstatus();
    int Interest();
    int Listall();
    int statistics();
    int getallinterest();                                        //产生利息
    User *new_account(string name, string email, string passwd); //新建一个账号, 输入姓名，邮箱，密码
    User *Find(string name_email);                               //查询一个账户, 输入姓名或邮箱查询, 返回地址
    User *Find(int cardid);                                      //查询一个账户, 输入卡号查询, 返回地址
  private:
    double rate;
};
#endif