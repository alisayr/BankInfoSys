#include "src/bank.cpp"
#include "src/finance.cpp"
#include "src/user.cpp"

int start(Bank &bank)
{
    string str;
    cout << "[重要] 正在进行初始化安装..." << endl;
    cout << "请设置管理员密码：" << endl;
    str = passwordin();
    cout << "请设置初始时间：（年 月 日）" << endl;
    cin.clear();
    cin.sync();
    cin >> StartDate[0] >> StartDate[1] >> StartDate[2];
    PassDay = 0;
    NowDate[0] = StartDate[0];
    NowDate[1] = StartDate[1];
    NowDate[2] = StartDate[2];
    bank.CBank(str);
    system("cls");
    cout << "[重要] 初始化安装完毕，管理员默认卡号:101，感谢您的使用！\n[重要] 请及时修改管理员信息，以免损失！" << endl;
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
    cout << "请选择您的找回方式：\t1.找回密码\t2.找回卡号" << endl;
    cin >> cho;
    if (cho == 1)
    {
        system("cls");
        cout << "请输入您的卡号:";
        cin >> id;
        if (bank.Find(id) == NULL)
        {
            cout << "用户不存在！" << endl;
            system("pause");
            return 0;
        }
        else
        {
            cout << "请输入您的邮箱:";
            cin >> str;
            if (bank.Find(id)->showemail() == str)
            {
                cout << "验证成功！请设置新的密码：";
                cin >> str;
                bank.Find(id)->change_passwd(str);
                cout << "修改成功！" << endl;
                system("pause");
                return 1;
            }
            else
            {
                cout << "邮箱错误！找回失败！" << endl;
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
        cout << "当前时间为：" << NowDate[0] << "年" << NowDate[1] << "月" << NowDate[2] << "日" << endl;
        cout << "请输入设置后的时间（年 月 日）：" << endl;
        cin >> day[0] >> day[1] >> day[2];
        NowDate[0] = day[0];
        NowDate[1] = day[1];
        NowDate[2] = day[2];
        PassDay = day_diff(StartDate[0], StartDate[1], StartDate[2], NowDate[0], NowDate[1], NowDate[2]);
        if (PassDay < 0)
        {
            cout << "[错误] 错误！时间不能倒流！请重新输入！" << endl;
        }
        else
        {
            cout << "[提示] 修改成功！距离初始时间已流逝" << PassDay << "天。" << endl;
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
        cout << "您已进入-》登陆页面-》管理员选项" << endl;
        cout << "****************************" << endl;
        cout << "请输入您要选择的功能代码:" << endl;
        cout << "1.列出银行所有信息" << endl;
        cout << "2.统计" << endl;
        cout << "3.设置利率" << endl;
        cout << "5.操纵时间(+1s)" << endl;
        cout << "0.退出" << endl;
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
            cout << "留空" << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "请输入设定利息：" << endl;
            cout << "1.活期" << endl;
            cout << "2.三个月" << endl;
            cout << "3.六个月" << endl;
            cout << "4.一年" << endl;
            cout << "5.两年" << endl;
            cout << "6.三年" << endl;
            cout << "7.五年" << endl;
            cin >> cho;
            cout << "请输入设定后的利息：" << endl;
            cin >> setint;
            if (set_interest(cho, setint))
                cout << "[提示] 设置成功!" << endl;
            else
                cout << "[错误] 未知错误！" << endl;
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
        cout << "您已进入-》登陆页面-》交易管理" << endl;
        cout << "****************************" << endl;
        cout << "请输入您要选择的功能代码:" << endl;
        cout << "1.活期存款" << endl;
        cout << "2.活期取款" << endl;
        cout << "3.定期存款" << endl;
        cout << "4.定期取款" << endl;
        cout << "5.转账" << endl;
        cout << "0.退出" << endl;
        cin >> cho;
        switch (cho)
        {
        case 1:
            system("cls");
            cout << "请输入活期存款金额：" << endl;
            cin >> sum;
            bank.log->demand_deposit_add(sum);
            cout << "[提示] 存款成功！" << endl;
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "请输入活期取款金额：" << endl;
            cin >> sum;
            if (bank.log->demand_deposit_sub(sum))
                cout << "[提示] 取款成功！" << endl;
            else
                cout << "[错误] 余额不足！" << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "请输入定期存款金额：" << endl;
            cin >> sum;
            cout << "请输入定期存款时间：" << endl;
            cout << "1.三个月" << endl;
            cout << "2.六个月" << endl;
            cout << "3.一年" << endl;
            cout << "4.两年" << endl;
            cout << "5.三年" << endl;
            cout << "6.五年" << endl;
            cin >> tim;
            bank.log->time_deposit_add(sum, interest[tim - 1] * sum * time_deposit[tim - 1] / 360, time_deposit[tim - 1]);
            system("cls");
            cout << "[提示] 存款成功！" << endl;
            system("pause");
            break;
        case 4:
            system("cls");
            db = bank.log->time_deposit();
            if (db == 0)
                cout << "[错误] 您没有定期存款！" << endl;
            else if (db == -1)
                cout << "[错误] 还没有到取款日期！" << endl;
            else if (db == -2)
                cout << "[错误] 未知错误！" << endl;
            else
                cout << "[提示] 取款成功！本利和一共" << db << "元！" << endl;
            system("pause");
            break;
        case 5:
            system("cls");
            cout << "请选择转账方式：\t1.单一用户\t2.多个用户" << endl;
            cin >> cho;
            if (cho == 1)
            {
                cout << "请输入目标账户的卡号：";
                cin >> id;
                if (bank.Find(id) == NULL)
                {
                    cout << "[错误] 目标账户不存在！" << endl;
                    system("pause");
                    break;
                }
                else
                {
                    cout << "请输入转账金额:";
                    cin >> sum;
                    tim = bank.log->transfer_money(bank.Find(id), sum);
                    if (tim == 3)
                        cout << "[错误] 目标账户是管理员，无法接受转账！" << endl;
                    else if (tim == 2)
                        cout << "[错误] 目标账户处于销户状态，无法接受转账！" << endl;
                    else if (tim == 0)
                        cout << "[错误] 扣款失败!余额不足!" << endl;
                    else
                        cout << "转账成功！" << endl;
                    system("pause");
                    return 0;
                }
            }
            else if (cho == 2)
            {
                while (1)
                {
                    cout << "请输入目标账户的卡号(输入0退出)：";
                    cin >> id;
                    if (id == 0)
                        return 0;
                    if (bank.Find(id) == NULL)
                    {
                        cout << "[错误] 目标账户不存在！" << endl;
                        system("pause");
                    }

                    else
                    {
                        cout << "请输入转账金额:";
                        cin >> sum;
                        tim = bank.log->transfer_money(bank.Find(id), sum);
                        if (tim == 3)
                            cout << "[错误] 目标账户是管理员，无法接受转账！" << endl;
                        else if (tim == 2)
                            cout << "[错误] 目标账户处于销户状态，无法接受转账！" << endl;
                        else if (tim == 0)
                            cout << "[错误] 扣款失败!余额不足!" << endl;
                        else
                            cout << "转账成功！" << endl;
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
        cout << "您已进入-》登陆页面-》账户管理" << endl;
        cout << "****************************" << endl;
        cout << "请输入您要选择的功能代码:" << endl;
        cout << "1.修改邮箱" << endl;
        cout << "2.修改姓名" << endl;
        cout << "3.修改密码" << endl;
        cout << "4.挂失" << endl;
        cout << "0.后退" << endl;
        cin >> cho;
        switch (cho)
        {
        case 1:
            cout << "请输入新的邮箱" << endl;
            cin >> str;
            bank.log->email_change(str);
            cout << "[提示] 修改成功！" << endl;
            system("pause");
            break;
        case 2:
            cout << "请输入新的姓名" << endl;
            cin >> str;
            bank.log->name_change(str);
            cout << "[提示] 修改成功！" << endl;
            system("pause");
            break;
        case 3:
            cout << "请输入新的密码" << endl;
            cin >> str;
            bank.log->change_passwd(str);
            cout << "[提示] 修改成功！" << endl;
            system("pause");
            break;
        case 4:
            bank.log->report_loss();
            cout << "[提示] 挂失成功！" << endl;
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
            cout << "[提示] 登陆成功！" << endl;
        i = 0;
        cout << "您已进入-》登陆页面" << endl;
        cout << "****************************" << endl;
        cout << "请输入您要选择的功能代码:" << endl;
        cout << "1.账户管理" << endl;
        cout << "2.交易管理(未开放)" << endl;
        cout << "3.查询信息" << endl;
        cout << "0.退出" << endl;
        if (bank.log->showstatus() == 4)
            cout << "5.管理员功能" << endl;
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
    cout << "请输入卡号：";
    cin >> cardid;
    cout << "请输入密码: ";
    cardpswd = passwordin();
    if (bank.Login(cardid, cardpswd) == 1)
    {
        loginpage(bank);
        return 0;
    }
    else if (bank.Login(cardid, cardpswd) == 2)
    {
        cout << "[错误] 密码错误！请重新输入" << endl;
        system("pause");
    }
    else if (bank.Login(cardid, cardpswd) == 0)
    {
        cout << "[错误] 用户不存在！！请重新输入" << endl;
        system("pause");
    }
    else
    {
        cout << "[错误] 未知错误！" << endl;
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
    cout << "请输入您的邮箱：" << endl;
    cin >> email;
    cout << "请输入您的姓名：" << endl;
    cin >> name;
    while (1)
    {
        cout << "请输入您的密码：" << endl;
        passwd = passwordin();
        cout << "请再次输入您的密码：" << endl;
        repasswd = passwordin();
        if (passwd == repasswd)
        {
            break;
        }
        else
            cout << "[错误] 两次密码输入不同，请重新输入！" << endl;
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
        cout << "请选择：" << endl;
        cout << "1.登陆  2.注册  3.忘记密码  0.退出" << endl;
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
    cout << "******欢迎使用银行管理******" << endl;
    cout << "****************************" << endl;
    start(bank);
    choice(bank);
    cout << "***************************" << endl;
    bank.Listall();
    return 0;
}
