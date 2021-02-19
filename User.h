#pragma once
#include <string>
using namespace std;

class User
{
private:
	string userName;
	string password;
public:
	User();
	User(string, string);
	~User();
	string getUserName();
	string getPassword();
	void setUserName(string);
	void setPassword(string);
	bool operator==(const User& u);
	string toString();
	string toStringDelimiter(char delimiter);
	
};
