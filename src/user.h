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
  static int sum;                      //��̬��Ա, ��¼����ʵʱ������
  static int cardsum;                  //��̬��Ա���������ɿ���
  int name_change(string newname);     //�޸�����, ����������, �޸�˽�г�Աname
  int email_change(string newemail);   //�޸�����, ����������, �޸�˽�г�Աemail
  int report_loss();                   //��ʧ
  int change_passwd(string newpasswd); //�޸�����, ����������, �޸�˽�г�Աcardpasswd
  int change_status(int i);
  int is_email(string isemail); //�һ�����, �������䣬����ȷ������޸����뺯��
  string showname();            //���ص�ǰ��������
  string showemail();           //���ص�ǰ��������
  int showcardid();
  string showpasswd();
  int showstatus();
  int showall();
  int transfer_money(User *target, double money);
  User(string name1, string email1, string passwd1, int status1);
  //~User
private:
  string name;       //����
  string email;      //����
  int cardid;        //����, ���ò���
  string cardpasswd; //����
  int status;        //״̬,  1������,  2����ʧ,  3������ , 4:����Ա
};
int showdate(int y, int m, int d, int passd)
{
  passd += (d - 1);
  d = 1;

  //���㵱ǰ�·�����
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
  //�������ں�������
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
    return showdate(y, m, d, passd - day); //�ݹ�
  }
  else
  {
    d += passd;
  }

  cout << y << "��" << m << "��" << d << "��" << endl;
  return 0;
}
#endif