#include "ValidatorMancare.h"
#include <string>
using namespace std;



ValidatorMancare::ValidatorMancare()
{
	err = 0;
}

int ValidatorMancare::validate(Mancare sho)
{
	err = 0;
	for (int i = 0; i < (sho.getNumeClient()).size(); i++)
		if (!isalpha(sho.getNumeClient()[i]) and sho.getNumeClient()[i] != ' ') {
			err++; mesaj += "Numele clientului trebuie sa contina numai litere sau spatiu! "; break;
		}
	if (sho.getPretTotal() <= 0) {
		err++; mesaj += "Pretul total trebuie sa fie mai mare decat 0! ";
	}
	if (sho.getListaPreparate() == "") {
		err++; mesaj += "Lista de cumparaturi trebuie sa contina cel putin un produs";
	}
	return err;
}

string ValidatorMancare::toString()
{
	return mesaj;
}


ValidatorMancare::~ValidatorMancare()
{
}