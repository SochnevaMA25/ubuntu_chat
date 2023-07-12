#include "chat.h"

using namespace std;

Chat::Chat() {};
//check user

void Chat::check(string nickname, string login, string pass)
{
    if (check_nick(nickname) == true)
    {
        if (check_login(nickname, login) == true)
        {
            if (check_pass(nickname, pass) == true)
            {
                cout << "login completed! " << endl;
                
            }
            else
            {
                cout << "invalid pass! " << endl;
            }
        }
        else
        {
            cout << "invalid login! " << endl;
        }
    }
    else
    {
        reg(nickname, login, pass);
    }
}
//check nick
bool Chat::check_nick(string nick)
{
    map <string, _Users>:: iterator it = user.find(nick);
    if (it != user.end())
        return true;

    return false;
    
}
//check login
bool Chat::check_login(string nickname, string login)
{
    for (int i = 0; i < user.size(); ++i) {
        if (user[nickname].login == login)
            return true;
    }
    return false;
}
//check pass
bool Chat::check_pass(string nick, string pass)
{
   for (int i = 0; i < user.size(); ++i) {
        if (user[nick].pass == pass)
            return true;
    }
    return false;
}
//registration
void Chat::reg(string nickname, string login, string pass)
{
    _Users u(login, pass);
    user.insert({ nickname, u });
}
//print
void Chat::print()
{
    cout << user.size() << endl;
    cout << "Print: " << endl;
    for (map<string, _Users>::iterator it = user.begin(); it != user.end(); ++it)
    {
        cout << it->first << it->second.login << it->second.pass << endl;
    }

}