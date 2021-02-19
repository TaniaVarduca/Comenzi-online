#include "Service.h"
#include "User.h"
#include "ValidatorMancare.h"
#include "ValidatorShopping.h"
#include "Exceptie.h"
#include<iostream>
using namespace std;


Service::Service()
{
}

Service::Service(Repo<Comanda*>* repoComanda,  Repo<User>* repoUseri)
{
	this->repoComanda = repoComanda;
	this->repoUser = repoUseri;
	User u1("Ana", "123");
	User u2("Ion", "1234");
	repoUser->add(u1);
	repoUser->add(u2);
}

bool Service::login(string u, string p)
{
	User usr(u, p);
	return repoUser->find(usr) != -1;
}

void Service::logout(string name, string pass)
{
	User u(name, pass);
	repoUser->remove(u);
}

map<int, Comanda*> Service::getAllComenzi()
{
	return repoComanda->getAll();
}

void Service::addComanda(Comanda* m)
{
	repoComanda->add(m);
	((Repo<Comanda*>*)repoComanda)->saveToFile();
}

map<int, Comanda*> Service::comandaDupaNumeClient(string nume)
{
	int contor = 0;
	map<int, Comanda*> rez;
	map<int, Comanda*> cm = repoComanda->getAll();
	map<int, Comanda*>::iterator itr;
	for (itr = cm.begin(); itr != cm.end(); ++itr) {
		if (itr->second->getNumeClient().compare(nume) == 0) {
			rez.insert(pair<int, Comanda*>(contor++, itr->second));
		}
	}
	return rez;
}

void Service::validareMancare(Mancare m)
{
	ValidatorMancare vm;
	int rez = vm.validate(m);
	if (rez != 0) {
		throw ValidationException(vm.toString().c_str());
	}
}

void Service::validareShopping(Shopping sho)
{
	ValidatorShopping vs;
	int rez = vs.validate(sho);
	if (rez != 0) {
		throw ValidationException(vs.toString().c_str());
	}
}

Service::~Service()
{
}