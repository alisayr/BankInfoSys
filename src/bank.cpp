/*
    *Filename: bank.cpp
    *Description?: bank define 
    *Author: matrix
    *Version: beta_0.1
    *Date: 2018.7.6 8:08
*/
#include "bank.h"
/*
int Bank::CBank()
{
    head = new User;
    tail = head;
    ptr = head;
    
}
*/
User *Bank::new_account(string name, string email, string passwd)
{
    ptr = tail;
    ptr->next = new User;
    ptr = ptr->next;
    return ptr;
}
User *Bank::Find(string name_email)
{
    ptr = head;
    do
    {   
        if(name_email==ptr->showname()||name_email==ptr->showemail())
            return ptr;
        ptr = ptr->next;
    } while (ptr != NULL);
    if(ptr == NULL)
        return NULL;
}
User *Bank::Find(int cardid)
{
    ptr = head;
    do
    {   
        if(cardid==ptr->showcardid())
            return ptr;
        ptr = ptr->next;
    } while (ptr != NULL);
    if(ptr == NULL)
        return NULL;
}
