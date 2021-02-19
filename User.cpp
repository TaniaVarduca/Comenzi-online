#include "User.h"

User::User()
{
}

User::User(string u, string p) :userName(u), password(p)
{
}

string User::getUserName()
{
	return userName;
}

string User::getPassword()
{
	return password;
}

void User::setUserName(string u)
{
	userName = u;
}

void User::setPassword(string p)
{
	password = p;
}

bool User::operator==(const User& u)
{
	return (userName == u.userName) and (password == u.password);
}

string User::toString()
{
	return userName + " " + password;
}

string User::toStringDelimiter(char delimiter)
{
	return userName + delimiter + password;
}

User::~User()
{
}