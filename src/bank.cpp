/*
    *Filename: bank.cpp
    *Description?: bank define 
    *Author: matrix
    *Version: beta_0.1
    *Date: 2018.7.6 8:08
*/
#include "bank.h"
#include "finance.cpp"
int Bank::CBank(string passwdadm)
{
    head = new User("Admin", "admin@host", passwdadm, 4);
    tail = head;
    ptr = head;
    return 1;
}

User *Bank::new_account(string name, string email, string passwd)
{
    ptr = tail;
    ptr->next = new User(name, email, passwd, 1);
    ptr = ptr->next;
    tail = ptr;
    cout << "注册成功，您的卡号为：";
    cout << ptr->showcardid() << endl;
    return ptr;
}
User *Bank::Find(string name_email)
{
    ptr = head;
    do
    {
        if (name_email == ptr->showname() || name_email == ptr->showemail())
            return ptr;
        ptr = ptr->next;
    } while (ptr != NULL);
    if (ptr == NULL)
        return NULL;
    return NULL;
}
User *Bank::Find(int cardid)
{
    ptr = head;
    do
    {
        if (cardid == ptr->showcardid())
            return ptr;
        ptr = ptr->next;
    } while (ptr != NULL);
    if (ptr == NULL)
        return NULL;
    return NULL;
}
int Bank::Login(int cardid, string passwd)
{
    log = Find(cardid);
    if (log->showstatus() == 2)
        return 3;
    else if (log->showstatus() == 3)
        return 4;
    else if (log != NULL)
    {
        if (log->showpasswd() == passwd)
            return 1;

        else
        {
            log = NULL;
            return 2;
        }
    }
    else
        return 0;
}
int Bank::Logout()
{
    log = NULL;
    return 1;
}
int Bank::Logstatus()
{
    if (log == NULL)
        return 0;
    else if (log->showstatus() == 1)
        return 1;
    else if (log->showstatus() == 2)
        return 2;
    else if (log->showstatus() == 3)
        return 3;
    else if (log->showstatus() == 4)
        return 4;
    else
        return 5;
}
int Bank::Listall()
{
    int i = 1;
    system("cls");
    ptr = head;
    do
    {
        cout << "***************************" << endl;
        cout << i << ":" << endl;
        ptr->showall();
        i++;
        ptr = ptr->next;
    } while (ptr != NULL);
    return 0;
}
int Bank::statistics()
{
    int n=0;
    int n1=0;
    double sum=0;
    double sumt = 0;
    ptr = head;
    do{
        if(ptr->showstatus()==1||ptr->showstatus()==2)
            n++;
        if(ptr->show_time_deposit_sum()>0)
            {
                n1++;
                sumt += ptr->show_time_deposit_sum();
            }
        sum += ptr->show_balance();
        ptr = ptr->next;
    } while (ptr != NULL);
    cout << "当前共有" << n << "名用户。" << endl;
    cout << "银行活期资产总共" << sum << "元。" << endl;
    cout << "定期存款共" << n1 << "笔，共" << sumt << "元。" << endl;
    cout << "本系统一共运行了" << PassDay << "天。" << endl;
    return 0;
}
int Bank::getallinterest()
{
    ptr = head;
    do{
        ptr->get_interest();
        ptr = ptr->next;
    } while (ptr != NULL);
    return 0;
}
