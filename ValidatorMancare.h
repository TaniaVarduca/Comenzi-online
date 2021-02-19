#pragma once
#include "Mancare.h"
#include <exception>
using namespace std;

class ValidatorMancare
{
protected:
	int err;
	string mesaj;
public:
	ValidatorMancare();
	int validate(Mancare);
	string toString();
	~ValidatorMancare();
};
