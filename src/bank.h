/*
    *Filename: bank.h
    *Description?: bank class declear
    *Author: matrix
    *Version: beta_0.1
    *Date: 2018.7.5 10:17
*/
#include "user.h"
class Bank:public User
{
    public:
      User *head;
      User *ptr;        //����ָ��
      int CBank();      //�����µĿ��������ݿ�
      int Login();      //��½��ʹptr����ָ��ָ��
      int Logout();     //�ǳ�
      User *new_account(string name, string email, string passwd);     //�½�һ���˺�, �������������䣬����
      User *Find(string name_email);     //��ѯһ���˻�, ���������������ѯ, ���ص�ַ
      User *Find(int cardid);           //��ѯһ���˻�, ���뿨�Ų�ѯ, ���ص�ַ
};