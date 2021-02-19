#pragma once
#include "Comanda.h"
#include <map>
#include "Repo.h"
using namespace std;

template <class T> class RepoFile :public Repo<T>
{
private:
	const char* fis;
public:
	RepoFile();
	RepoFile(const char* fileName);
	void loadFromFile(const char* fileName);
	void saveToFile();
	~RepoFile();
};
