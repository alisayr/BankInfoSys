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
    static int sum;                         //��̬��Ա, ��¼����ʵʱ������
    static int cardsum;                     //��̬��Ա���������ɿ���
    int name_change(string newname);        //�޸�����, ����������, �޸�˽�г�Աname
    int email_change(string newemail);      //�޸�����, ����������, �޸�˽�г�Աemail
    int report_loss();                      //��ʧ 
    int change_passwd(string newpasswd);    //�޸�����, ����������, �޸�˽�г�Աcardpasswd
    int is_email(string isemail);          //�һ�����, �������䣬����ȷ������޸����뺯��
    string showname();                      //���ص�ǰ��������
    string showemail();                     //���ص�ǰ��������
    int showcardid();
    string showpasswd();
    int showstatus();
    int transfer_money(User *target,double money);
    User(string name1, string email1, string passwd1, int status1);
    //~User
  private:
    string name;    //����
    string email;   //����
    int cardid;     //����, ���ò���
    string cardpasswd; //����
    int status;     //״̬,  1������,  2����ʧ,  3������ , 4:����Ա
};
#endif