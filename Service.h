#pragma once
#include "RepoCSV.h"
#include "RepoCustom.h"
#include "Mancare.h"
#include "Shopping.h"
#include "User.h"

class Service
{
private:
	Repo<Comanda*>* repoComanda;
	Repo<User>* repoUser;

public:
	Service();
	Service(Repo<Comanda*>*, Repo<User>*);
	bool login(string, string);
	void logout(string, string);
	map<int, Comanda*> getAllComenzi();
	void addComanda(Comanda*);
	map<int, Comanda*> comandaDupaNumeClient(string);
	void validareMancare(Mancare);
	void validareShopping(Shopping);
	~Service();
};
