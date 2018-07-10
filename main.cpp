#include "src/bank.cpp"
#include "src/finance.cpp"
#include "src/user.cpp"

int start(Bank &bank)
{
    string str;
    cout << "[��Ҫ] ���ڽ��г�ʼ����װ..." << endl;
    cout << "�����ù���Ա���룺" << endl;
    str = passwordin();
    cout << "�����ó�ʼʱ�䣺���� �� �գ�" << endl;
    cin.clear();
    cin.sync();
    cin >> StartDate[0] >> StartDate[1] >> StartDate[2];
    PassDay = 0;
    NowDate[0] = StartDate[0];
    NowDate[1] = StartDate[1];
    NowDate[2] = StartDate[2];
    bank.CBank(str);
    system("cls");
    cout << "[��Ҫ] ��ʼ����װ��ϣ�����ԱĬ�Ͽ���:101����л����ʹ�ã�\n[��Ҫ] �뼰ʱ�޸Ĺ���Ա��Ϣ��������ʧ��" << endl;
    system("pause");
    system("cls");
    return 1;
}

int forgetpasswd(Bank &bank)
{
    string str;
    int cho;
    int id;
    system("cls");
    cout << "��ѡ�������һط�ʽ��\t1.�һ�����\t2.�һؿ���" << endl;
    cin >> cho;
    if (cho == 1)
    {
        system("cls");
        cout << "���������Ŀ���:";
        cin >> id;
        if (bank.Find(id) == NULL)
        {
            cout << "�û������ڣ�" << endl;
            system("pause");
            return 0;
        }
        else
        {
            cout << "��������������:";
            cin >> str;
            if (bank.Find(id)->showemail() == str)
            {
                cout << "��֤�ɹ����������µ����룺";
                cin >> str;
                bank.Find(id)->change_passwd(str);
                cout << "�޸ĳɹ���" << endl;
                system("pause");
                return 1;
            }
            else
            {
                cout << "��������һ�ʧ�ܣ�" << endl;
                system("pause");
                return 0;
            }
        }
    }
    return 0;
}
int set_time()
{
    int day[3];
    while (1)
    {
        system("cls");
        cout << "��ǰʱ��Ϊ��" << NowDate[0] << "��" << NowDate[1] << "��" << NowDate[2] << "��" << endl;
        cout << "���������ú��ʱ�䣨�� �� �գ���" << endl;
        cin >> day[0] >> day[1] >> day[2];
        NowDate[0] = day[0];
        NowDate[1] = day[1];
        NowDate[2] = day[2];
        PassDay = day_diff(StartDate[0], StartDate[1], StartDate[2], NowDate[0], NowDate[1], NowDate[2]);
        if (PassDay < 0)
        {
            cout << "[����] ����ʱ�䲻�ܵ��������������룡" << endl;
        }
        else
        {
            cout << "[��ʾ] �޸ĳɹ��������ʼʱ��������" << PassDay << "�졣" << endl;
            break;
        }
    }
    return 1;
}
int set_interest(int cho, double setint)
{
    interest[cho - 1] = setint;
    return 1;
}
int managepage(Bank &bank)
{
    int cho;
    double setint;
    string str;
    while (1)
    {
        system("cls");
        cout << "���ѽ���-����½ҳ��-������Աѡ��" << endl;
        cout << "****************************" << endl;
        cout << "��������Ҫѡ��Ĺ��ܴ���:" << endl;
        cout << "1.�г�����������Ϣ" << endl;
        cout << "2.ͳ��" << endl;
        cout << "3.��������" << endl;
        cout << "5.����ʱ��(+1s)" << endl;
        cout << "0.�˳�" << endl;
        cin >> cho;
        switch (cho)
        {
        case 1:
            system("cls");
            bank.Listall();
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "����" << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "�������趨��Ϣ��" << endl;
            cout << "1.����" << endl;
            cout << "2.������" << endl;
            cout << "3.������" << endl;
            cout << "4.һ��" << endl;
            cout << "5.����" << endl;
            cout << "6.����" << endl;
            cout << "7.����" << endl;
            cin >> cho;
            cout << "�������趨�����Ϣ��" << endl;
            cin >> setint;
            if (set_interest(cho, setint))
                cout << "[��ʾ] ���óɹ�!" << endl;
            else
                cout << "[����] δ֪����" << endl;
            system("pause");
            break;
        case 5:
            system("cls");
            set_time();
            system("pause");
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
    return 0;
}
int finance(Bank &bank)
{
    int id;
    int cho;
    int sum;
    int tim;
    double db;
    string str;
    while (1)
    {
        system("cls");
        cout << "���ѽ���-����½ҳ��-�����׹���" << endl;
        cout << "****************************" << endl;
        cout << "��������Ҫѡ��Ĺ��ܴ���:" << endl;
        cout << "1.���ڴ��" << endl;
        cout << "2.����ȡ��" << endl;
        cout << "3.���ڴ��" << endl;
        cout << "4.����ȡ��" << endl;
        cout << "5.ת��" << endl;
        cout << "0.�˳�" << endl;
        cin >> cho;
        switch (cho)
        {
        case 1:
            system("cls");
            cout << "��������ڴ���" << endl;
            cin >> sum;
            bank.log->demand_deposit_add(sum);
            cout << "[��ʾ] ���ɹ���" << endl;
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "���������ȡ���" << endl;
            cin >> sum;
            if (bank.log->demand_deposit_sub(sum))
                cout << "[��ʾ] ȡ��ɹ���" << endl;
            else
                cout << "[����] ���㣡" << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "�����붨�ڴ���" << endl;
            cin >> sum;
            cout << "�����붨�ڴ��ʱ�䣺" << endl;
            cout << "1.������" << endl;
            cout << "2.������" << endl;
            cout << "3.һ��" << endl;
            cout << "4.����" << endl;
            cout << "5.����" << endl;
            cout << "6.����" << endl;
            cin >> tim;
            bank.log->time_deposit_add(sum, interest[tim - 1] * sum * time_deposit[tim - 1] / 360, time_deposit[tim - 1]);
            system("cls");
            cout << "[��ʾ] ���ɹ���" << endl;
            system("pause");
            break;
        case 4:
            system("cls");
            db = bank.log->time_deposit();
            if (db == 0)
                cout << "[����] ��û�ж��ڴ�" << endl;
            else if (db == -1)
                cout << "[����] ��û�е�ȡ�����ڣ�" << endl;
            else if (db == -2)
                cout << "[����] δ֪����" << endl;
            else
                cout << "[��ʾ] ȡ��ɹ���������һ��" << db << "Ԫ��" << endl;
            system("pause");
            break;
        case 5:
            system("cls");
            cout << "��ѡ��ת�˷�ʽ��\t1.��һ�û�\t2.����û�" << endl;
            cin >> cho;
            if (cho == 1)
            {
                cout << "������Ŀ���˻��Ŀ��ţ�";
                cin >> id;
                if (bank.Find(id) == NULL)
                {
                    cout << "[����] Ŀ���˻������ڣ�" << endl;
                    system("pause");
                    break;
                }
                else
                {
                    cout << "������ת�˽��:";
                    cin >> sum;
                    tim = bank.log->transfer_money(bank.Find(id), sum);
                    if (tim == 3)
                        cout << "[����] Ŀ���˻��ǹ���Ա���޷�����ת�ˣ�" << endl;
                    else if (tim == 2)
                        cout << "[����] Ŀ���˻���������״̬���޷�����ת�ˣ�" << endl;
                    else if (tim == 0)
                        cout << "[����] �ۿ�ʧ��!����!" << endl;
                    else
                        cout << "ת�˳ɹ���" << endl;
                    system("pause");
                    return 0;
                }
            }
            else if (cho == 2)
            {
                while (1)
                {
                    cout << "������Ŀ���˻��Ŀ���(����0�˳�)��";
                    cin >> id;
                    if (id == 0)
                        return 0;
                    if (bank.Find(id) == NULL)
                    {
                        cout << "[����] Ŀ���˻������ڣ�" << endl;
                        system("pause");
                    }

                    else
                    {
                        cout << "������ת�˽��:";
                        cin >> sum;
                        tim = bank.log->transfer_money(bank.Find(id), sum);
                        if (tim == 3)
                            cout << "[����] Ŀ���˻��ǹ���Ա���޷�����ת�ˣ�" << endl;
                        else if (tim == 2)
                            cout << "[����] Ŀ���˻���������״̬���޷�����ת�ˣ�" << endl;
                        else if (tim == 0)
                            cout << "[����] �ۿ�ʧ��!����!" << endl;
                        else
                            cout << "ת�˳ɹ���" << endl;
                        system("pause");
                    }
                }
            }
            system("pause");
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
    return 0;
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
        cout << "4.��ʧ" << endl;
        cout << "0.����" << endl;
        cin >> cho;
        switch (cho)
        {
        case 1:
            cout << "�������µ�����" << endl;
            cin >> str;
            bank.log->email_change(str);
            cout << "[��ʾ] �޸ĳɹ���" << endl;
            system("pause");
            break;
        case 2:
            cout << "�������µ�����" << endl;
            cin >> str;
            bank.log->name_change(str);
            cout << "[��ʾ] �޸ĳɹ���" << endl;
            system("pause");
            break;
        case 3:
            cout << "�������µ�����" << endl;
            cin >> str;
            bank.log->change_passwd(str);
            cout << "[��ʾ] �޸ĳɹ���" << endl;
            system("pause");
            break;
        case 4:
            bank.log->report_loss();
            cout << "[��ʾ] ��ʧ�ɹ���" << endl;
            system("pause");
            break;
        case 0:
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
            cout << "[��ʾ] ��½�ɹ���" << endl;
        i = 0;
        cout << "���ѽ���-����½ҳ��" << endl;
        cout << "****************************" << endl;
        cout << "��������Ҫѡ��Ĺ��ܴ���:" << endl;
        cout << "1.�˻�����" << endl;
        cout << "2.���׹���(δ����)" << endl;
        cout << "3.��ѯ��Ϣ" << endl;
        cout << "0.�˳�" << endl;
        if (bank.log->showstatus() == 4)
            cout << "5.����Ա����" << endl;
        cin >> cho;
        switch (cho)
        {
        case 1:
            usermanage(bank);
            break;
        case 2:
            finance(bank);
            break;
        case 3:
            system("cls");
            bank.log->showall();
            system("pause");
            break;
        case 0:
            return 0;
        case 5:
            if (bank.log->showstatus() == 4)
                managepage(bank);
            break;
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
    cardpswd = passwordin();
    if (bank.Login(cardid, cardpswd) == 1)
    {
        loginpage(bank);
        return 0;
    }
    else if (bank.Login(cardid, cardpswd) == 2)
    {
        cout << "[����] �����������������" << endl;
        system("pause");
    }
    else if (bank.Login(cardid, cardpswd) == 0)
    {
        cout << "[����] �û������ڣ�������������" << endl;
        system("pause");
    }
    else
    {
        cout << "[����] δ֪����" << endl;
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
        passwd = passwordin();
        cout << "���ٴ������������룺" << endl;
        repasswd = passwordin();
        if (passwd == repasswd)
        {
            break;
        }
        else
            cout << "[����] �����������벻ͬ�����������룡" << endl;
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
        cout << "1.��½  2.ע��  3.��������  0.�˳�" << endl;
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
            forgetpasswd(bank);
            break;
        case 0:
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
