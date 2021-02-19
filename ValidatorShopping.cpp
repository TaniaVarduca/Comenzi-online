#include "ValidatorShopping.h"
#include <string>
using namespace std;



ValidatorShopping::ValidatorShopping()
{
	err = 0;
}

int ValidatorShopping::validate(Shopping sho)
{
	err = 0;
	for (int i = 0; i < (sho.getNumeClient()).size(); i++)
		if (!isalpha(sho.getNumeClient()[i]) and sho.getNumeClient()[i] != ' ') {
			err++; mesaj += "Numele clientului trebuie sa contina numai litere sau spatiu! "; break;
		}
	if (sho.getPretTotal() <= 0) {
		err++; mesaj += "Pretul total trebuie sa fie mai mare decat 0! ";
	}
	if (sho.getListaCumparaturi() == "") {
		err++; mesaj += "Lista de cumparaturi trebuie sa contina cel putin un produs";
	}
	return err;
}

string ValidatorShopping::toString()
{
	return mesaj;
}


ValidatorShopping::~ValidatorShopping()
{
}