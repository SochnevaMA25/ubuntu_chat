#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;
struct _Users 
{
	string login;
	string pass;
	_Users() {};
	_Users(string login, string pass) : login(login), pass(pass) {};
};
struct _Message
{
	string sender;
	string mes;
	_Message() {};
	_Message(string send, string m) : sender(send), mes(m) {};
};
typedef map <string, _Message> Mes; //recipient -> sender/mes
typedef map <string, _Users> m_user; //nick->login/pass

class Chat
{	
private:
	m_user user;
	
public:
	Chat();

	void check(string nickname, string login, string pass);
	bool check_nick(string nickname);
	bool check_login(string nickname, string login);
	bool check_pass(string nickname, string pass);
	void reg(string nickname, string login, string pass);
	void print();
};
