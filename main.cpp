#include "src/bank.cpp"
#include "src/finance.cpp"
#include "src/user.cpp"
int start(Bank &bank)
{
    string str;
    cout << "���ڽ��г�ʼ����װ..." << endl;
    cout << "�����ù���Ա���룺" << endl;
    cin >> str;
    cout << "�����õ�ǰʱ�䣺���� �� �գ�" << endl;
    cin.clear();
    cin.sync();
    cin >> StartDate[0] >> StartDate[1] >> StartDate[2];
    PassDay = 0;
    bank.CBank(str);
    system("cls");
    return 1;
}
int usermanage(Bank &bank)
{
    int cho;
    string str;
    while (1)
    {
        system("cls");
        cout << "���ѽ���-����½ҳ��-���˻�����" << endl;
        cout << "****************************" << endl;
        cout << "��������Ҫѡ��Ĺ��ܴ���:" << endl;
        cout << "1.�޸�����" << endl;
        cout << "2.�޸�����" << endl;
        cout << "3.�޸�����" << endl;
        cout << "4.����" << endl;
        cin >> cho;
        switch (cho)
        {
        case 1:
            cout << "�������µ�����" << endl;
            cin >> str;
            bank.log->email_change(str);
            break;
        case 2:
            cout << "�������µ�����" << endl;
            cin >> str;
            bank.log->name_change(str);
            break;
        case 3:
            cout << "�������µ�����" << endl;
            cin >> str;
            bank.log->change_passwd(str);
        case 4:
            return 0;
        default:
            break;
        }
    }
    return 0;
}
int loginpage(Bank &bank)
{
    int i = 1;
    int cho;
    while (1)
    {
        system("cls");
        if (i)
            cout << "��½�ɹ���" << endl;
        i = 0;
        cout << "���ѽ���-����½ҳ��" << endl;
        cout << "****************************" << endl;
        cout << "��������Ҫѡ��Ĺ��ܴ���:" << endl;
        cout << "1.�˻�����" << endl;
        cout << "2.���׹���(δ����)" << endl;
        cout << "3.��ѯ��Ϣ(δ����)" << endl;
        cout << "4.�˳�" << endl;
        cin >> cho;
        switch (cho)
        {
        case 1:
            usermanage(bank);
            break;
        case 2:
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }

    return 0;
}
int userlogin(Bank &bank)
{
    int cardid;
    string cardpswd;
    system("cls");
    cout << "�����뿨�ţ�";
    cin >> cardid;
    cout << "����������: ";
    cin >> cardpswd;
    if (bank.Login(cardid, cardpswd) == 1)
    {
        loginpage(bank);
        return 0;
    }
    else if (bank.Login(cardid, cardpswd) == 2)
    {
        cout << "�����������������" << endl;
        system("pause");
    }
    else if (bank.Login(cardid, cardpswd) == 0)
    {
        cout << "�û������ڣ�������������" << endl;
        system("pause");
    }
    else
    {
        cout << "δ֪����" << endl;
        system("pause");
    }

    return 0;
}

int userregister(Bank &bank)
{
    string email;
    string name;
    string passwd;
    string repasswd;
    system("cls");
    cout << "�������������䣺" << endl;
    cin >> email;
    cout << "����������������" << endl;
    cin >> name;
    while (1)
    {
        cout << "�������������룺" << endl;
        cin >> passwd;
        cout << "���ٴ������������룺" << endl;
        cin >> repasswd;
        if (passwd == repasswd)
        {
            break;
        }
        else
            cout << "�����������벻ͬ�����������룡" << endl;
    }
    bank.new_account(name, email, passwd);
    system("pause");
    return 0;
}
int choice(Bank &bank)
{
    int cho;
    while (1)
    {
        system("cls");
        cout << "��ѡ��" << endl;
        cout << "1.��½  2.ע��  3.�˳�" << endl;
        cin.clear();
        cin.sync();
        cin >> cho;
        switch (cho)
        {
        case 1:
            userlogin(bank);
            break;
        case 2:
            userregister(bank);
            break;
        case 3:
            return 0;
        default:
            return 0;
        }
    }
    return 0;
}
int main()
{
    Bank bank;
    system("cls");
    cout << "****************************" << endl;
    cout << "******��ӭʹ�����й���******" << endl;
    cout << "****************************" << endl;
    start(bank);
    choice(bank);
    cout << "***************************" << endl;
    bank.Listall();
    return 0;
}