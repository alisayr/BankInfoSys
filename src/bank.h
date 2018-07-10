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
    User *ptr;                               //����ָ��
    int CBank(string passwdadm);             //�����µĿ��������ݿ�
    int Login(int cardid, string passwd); //��½��ʹptr����ָ��ָ��
    int Logout();                            //�ǳ�
    int Logstatus();
    int Interest();
    int Listall();
    int statistics();
    int getallinterest();                                        //������Ϣ
    User *new_account(string name, string email, string passwd); //�½�һ���˺�, �������������䣬����
    User *Find(string name_email);                               //��ѯһ���˻�, ���������������ѯ, ���ص�ַ
    User *Find(int cardid);                                      //��ѯһ���˻�, ���뿨�Ų�ѯ, ���ص�ַ
  private:
    double rate;
};
#endif