#pragma once
#include <string>
#include "Service.h"
using namespace std;

class UI
{
private:
	Service s;
	User u;
public:
	UI();
	UI(Service&);
	int login();
	void logout();
	void allComenzi();
	void addMancare();
	void addShopping();
	void cautareDupaNume();
	void printMenu();
	void run();
	~UI();
};
