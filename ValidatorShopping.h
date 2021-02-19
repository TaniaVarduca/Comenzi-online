#pragma once
#include "Shopping.h"
#include <exception>
using namespace std;

class ValidatorShopping
{
protected:
	int err;
	string mesaj;
public:
	ValidatorShopping();
	int validate(Shopping);
	string toString();
	~ValidatorShopping();
};
