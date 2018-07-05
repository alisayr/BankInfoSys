/*
    *Filename: user.h
    *Description?: user class declear
    *Author: matrix
    *Version: beta_0.1
    *Date: 2018.7.5 10:02
*/
#include "finance.h"
class User : public Finance
{
  public:
    User *next;
    static int sum;                         //��̬��Ա, ��¼����ʵʱ������
    int name_change(string newname);        //�޸�����, ����������, �޸�˽�г�Աname
    int email_change(string newemail);      //�޸�����, ����������, �޸�˽�г�Աemail
    int report_loss();                      //��ʧ 
    int change_passwd(string newpasswd);    //�޸�����, ����������, �޸�˽�г�Աcardpasswd
    int forget_passwd(string email);        //�һ�����, �������䣬����ȷ������޸����뺯��

  private:
    string name;    //����
    string email;   //����
    int cardid;     //����, ���ò���
    string cardpasswd; //����
    int status;     //״̬,  1������,  2����ʧ,  3������ , 4:����Ա
};