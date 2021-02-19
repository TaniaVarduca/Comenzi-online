#include "tests.h"
#include "Comanda.h"
#include "Mancare.h"
#include "Shopping.h"
#include "ValidatorMancare.h"
#include "ValidatorShopping.h"
#include "Exceptie.h"
#include "User.h"
#include "RepoCSV.h"
#include "RepoCustom.h"
#include "Service.h"
#include <assert.h>
#include <iostream>


void testeEntitati() {

	//mancare
	Mancare m1; //constructor implicit
	assert((m1.getListaPreparate() == "") && (m1.getNumeClient() == "") && (m1.getAdresaClient() == "") && (m1.getPretTotal() == 0));
	Mancare m2("nume1", "str.X,nr.8", "supa,cartofi", 20); //constructor cu param
	assert((m2.getNumeClient().compare("nume1") == 0) && (m2.getAdresaClient().compare("str.X,nr.8") == 0) && m2.getPretTotal() == 20 && (m2.getListaPreparate().compare("supa,cartofi") == 0));
	Mancare m3(m2); //constructor de copiere
	assert(m3 == m2);

	//shopping
	Shopping s1; //constructor implicit
	assert((s1.getListaCumparaturi() == "") && s1.getNumeClient() == "" && (s1.getAdresaClient() == "") && (s1.getPretTotal() == 0) && s1.getNumeMagazin() == "");
	Shopping s2("nume2", "str.X,nr.8", "crema,parfum", 110, "maga"); //constructor cu param
	assert((s2.getNumeClient().compare("nume2") == 0) && (s2.getAdresaClient().compare("str.X,nr.8") == 0) && s2.getPretTotal() == 110 && (s2.getListaCumparaturi().compare("crema,parfum") == 0) && (s2.getNumeMagazin().compare("maga") == 0));
	Shopping s3(s2); //constructor de copiere
	assert(s3 == s2);

	//set, get
	m1.setNumeClient("nume"); m1.setAdresaClient("stradaNoua"); m1.setPretTotal(100); m1.setListaPreparate("abc");
	assert((m1.getNumeClient().compare("nume") == 0) && (m1.getAdresaClient().compare("stradaNoua") == 0) && m1.getPretTotal() == 100 && (m1.getListaPreparate().compare("abc") == 0));
	
	s1.setNumeClient("nume1"); s1.setAdresaClient("stradaN"); s1.setPretTotal(400); s1.setListaCumparaturi("xyz"); s1.setNumeMagazin("maga1");
	assert((s1.getNumeClient().compare("nume1") == 0) && (s1.getAdresaClient().compare("stradaN") == 0) && s1.getPretTotal() == 400 && (s1.getListaCumparaturi().compare("xyz") == 0) && (s1.getNumeMagazin().compare("maga1") == 0));
}

void testeRepoCSV() {

	Repo<Comanda*>* repo = new Repo<Comanda*>;
	SerializerComanda* s = new SerializerComanda;
	repo = new RepoCSV<Comanda*>("comenzi.csv", s);
	repo->loadFromFile(); //load from  csv file
	assert(repo->size() == 4); //repo csv size
	Mancare m1 ("mancare1", "str.X,nr.1", "pui,cartofi", 50);

	repo->add(&m1); //add mancare
	((Repo<Mancare>*)repo)->saveToFile(); //save mancare to csv file
	assert(repo->size() == 5);
	assert(repo->getAll().at(4) == &m1); //get all from repo
	assert(repo->find(&m1) == 4); //find mancare
	Shopping s1("shopping1", "str.X,nr.1", "haine,pantofi", 500, "h&m");
	repo->add(&s1); // add shopping
	((Repo<Shopping>*)repo)->saveToFile(); //save shopping to csv file
	assert(repo->size() == 6);
	assert(repo->getAll().at(5) == &s1);
	assert(repo->find(&s1) == 5); //find shopping
	Shopping s2("shopping2", "str.X,nr.2", "haine", 300, "zara");

	repo->update(&s1, &s2); //update shopping
	((RepoCSV<Shopping>*)repo)->saveToFile();
	assert(repo->find(&s1) == -1);
	assert(repo->find(&s2) == 5);
	repo->remove(&s2); //delete shopping
	assert(repo->size() == 5);
	assert(repo->find(&s1) == -1);
	((RepoCSV<Shopping>*)repo)->saveToFile();
	Mancare m2("mancare2", "str.X,nr.2", "pui,salata", 30);

	repo->update(&m1, &m2); //update mancare
	((RepoCSV<Mancare>*)repo)->saveToFile();
	assert(repo->find(&m1) == -1);
	assert(repo->find(&m2) == 4);
	repo->remove(&m2); //delete mancare
	assert(repo->size() == 4);
	assert(repo->find(&m2) == -1);
	((RepoCSV<Mancare>*)repo)->saveToFile();	
}

void testeRepoCustom() {

	Repo<Comanda*>* repo = new Repo<Comanda*>;
	SerializerComanda* s = new SerializerComanda;
	repo = new RepoCustom<Comanda*>("comenzi.txt", s);
	repo->loadFromFile(); //load from  csv file
	assert(repo->size() == 4); //repo csv size
	Mancare m1("mancare1", "str.X,nr.1", "pui,cartofi", 50);
	repo->add(&m1); //add mancare
	((Repo<Mancare>*)repo)->saveToFile(); //save mancare to csv file
	assert(repo->size() == 5);
	assert(repo->getAll().at(4) == &m1); //get all from repo
	assert(repo->find(&m1) == 4); //find mancare
	Shopping s1("shopping1", "str.X,nr.1", "haine,pantofi", 500, "h&m");
	repo->add(&s1); // add shopping
	((Repo<Shopping>*)repo)->saveToFile(); //save shopping to csv file
	assert(repo->size() == 6);
	assert(repo->getAll().at(5) == &s1);
	assert(repo->find(&s1) == 5); //find shopping
	Shopping s2("shopping2", "str.X,nr.2", "haine", 300, "zara");

	repo->update(&s1, &s2); //update shopping
	((RepoCSV<Shopping>*)repo)->saveToFile();
	assert(repo->find(&s1) == -1);
	assert(repo->find(&s2) == 5);
	repo->remove(&s2); //delete shopping
	assert(repo->size() == 5);
	assert(repo->find(&s1) == -1);
	((RepoCSV<Shopping>*)repo)->saveToFile();
	Mancare m2("mancare2", "str.X,nr.2", "pui,salata", 30);

	repo->update(&m1, &m2); //update mancare
	((RepoCSV<Mancare>*)repo)->saveToFile();
	assert(repo->find(&m1) == -1);
	assert(repo->find(&m2) == 4);
	repo->remove(&m2); //delete mancare
	assert(repo->size() == 4);
	assert(repo->find(&m1) == -1);
	((RepoCSV<Mancare>*)repo)->saveToFile();
}

void testeValidariCsv() {

	Repo<Comanda*>* repo = new Repo<Comanda*>;
	SerializerComanda* s = new SerializerComanda;
	repo = new RepoCSV<Comanda*>("comenzi.csv", s);
	repo->loadFromFile(); 

 	ValidatorMancare vm;
	Mancare m("nume", "adresa", "", -2); 
	if (vm.validate(m) == 0) { //validare mancare
		repo->add(&m);
	}
	assert(repo->size() == 4);

	ValidatorShopping vs;
	Shopping sho("nume", "adresa", "", -2, "maga");
	if (vs.validate(sho) == 0) { //validare shopping
		repo->add(&sho);
	}
	assert(repo->size() == 4);	
}

void testeValidariCustom() {

	Repo<Comanda*>* repo = new Repo<Comanda*>;
	SerializerComanda* s = new SerializerComanda;
	repo = new RepoCustom<Comanda*>("comenzi.csv", s);
	repo->loadFromFile();


	ValidatorMancare vm;
	Mancare m("nume", "adresa", "", -2);
	if (vm.validate(m) == 0) { //validare mancare
		repo->add(&m);
	}
	assert(repo->size() == 4);

	ValidatorShopping vs;
	Shopping sho("nume", "adresa", "", -2, "maga");
	if (vs.validate(sho) == 0) { //validare shopping
		repo->add(&sho);
	}
	assert(repo->size() == 4);
}

void testeService() {

	Repo<User>* repoU = new Repo<User>;
	Repo<Comanda*>* repoo = new RepoCSV<Comanda*>;
	SerializerComanda* s = new SerializerComanda;
	repoo = new RepoCustom<Comanda*>("comenzi.csv", s);
	repoo->loadFromFile();
	Service serv(repoo, repoU);

	//login
	assert(serv.login("Ana", "123") == 1);
	assert(serv.login("Ion", "1234") == 1);
	assert(serv.login("Dana", "000") == 0);
	User u("Maria", "111");
	repoU->add(u);
	assert(repoU->size() == 3);

	//logout
	serv.logout("Maria", "111");
	assert(repoU->size() == 2);

}

void tests() {
	std::cout << "first tests ..." << endl;

	testeEntitati();
	testeRepoCSV();
	testeRepoCustom();
	testeValidariCsv();
	testeValidariCustom();
	testeService();

	std::cout << "all tests are ok ... good job!" << endl << endl;
}