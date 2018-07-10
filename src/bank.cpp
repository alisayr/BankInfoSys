/*
    *Filename: bank.cpp
    *Description?: bank define 
    *Author: matrix
    *Version: beta_0.1
    *Date: 2018.7.6 8:08
*/
#include "bank.h"
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
