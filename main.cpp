#include "src/bank.cpp"
#include "src/finance.cpp"
#include "src/user.cpp"
int start(Bank &bank)
{
    string str;
    cout << "正在进行初始化安装..." << endl;
    cout << "请设置管理员密码：" << endl;
    cin >> str;
    cout << "请设置当前时间：（年 月 日）" << endl;
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
        cout << "您已进入-》登陆页面-》账户管理" << endl;
        cout << "****************************" << endl;
        cout << "请输入您要选择的功能代码:" << endl;
        cout << "1.修改邮箱" << endl;
        cout << "2.修改姓名" << endl;
        cout << "3.修改密码" << endl;
        cout << "4.后退" << endl;
        cin >> cho;
        switch (cho)
        {
        case 1:
            cout << "请输入新的邮箱" << endl;
            cin >> str;
            bank.log->email_change(str);
            break;
        case 2:
            cout << "请输入新的姓名" << endl;
            cin >> str;
            bank.log->name_change(str);
            break;
        case 3:
            cout << "请输入新的密码" << endl;
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
            cout << "登陆成功！" << endl;
        i = 0;
        cout << "您已进入-》登陆页面" << endl;
        cout << "****************************" << endl;
        cout << "请输入您要选择的功能代码:" << endl;
        cout << "1.账户管理" << endl;
        cout << "2.交易管理(未开放)" << endl;
        cout << "3.查询信息(未开放)" << endl;
        cout << "4.退出" << endl;
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
    cout << "请输入卡号：";
    cin >> cardid;
    cout << "请输入密码: ";
    cin >> cardpswd;
    if (bank.Login(cardid, cardpswd) == 1)
    {
        loginpage(bank);
        return 0;
    }
    else if (bank.Login(cardid, cardpswd) == 2)
    {
        cout << "密码错误！请重新输入" << endl;
        system("pause");
    }
    else if (bank.Login(cardid, cardpswd) == 0)
    {
        cout << "用户不存在！！请重新输入" << endl;
        system("pause");
    }
    else
    {
        cout << "未知错误！" << endl;
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
        cin >> passwd;
        cout << "请再次输入您的密码：" << endl;
        cin >> repasswd;
        if (passwd == repasswd)
        {
            break;
        }
        else
            cout << "两次密码输入不同，请重新输入！" << endl;
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
        cout << "1.登陆  2.注册  3.退出" << endl;
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
    cout << "******欢迎使用银行管理******" << endl;
    cout << "****************************" << endl;
    start(bank);
    choice(bank);
    cout << "***************************" << endl;
    bank.Listall();
    return 0;
}