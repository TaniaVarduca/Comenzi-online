#include "ValidareDate.h"

void ValidareDate::validareMancare(Mancare& m)
{
	if (m.getListaPreparate() == "") {
		throw std::exception("Comanda trebuie sa aiba cel putin un produs in lista!");
	}
	if (m.getPretTotal() <= 0) {
		throw std::exception("Pretul total trebuie sa fie mai mare decat 0!");
	}
}

void ValidareDate::validareShopping(Shopping& sho)
{
	if (sho.getListaCumparaturi() == "") {
		throw std::exception("Comanda trebuie sa aiba cel putin un produs in lista!");
	}
	if (sho.getPretTotal() <= 0) {
		throw std::exception("Pretul total trebuie sa fie mai mare decat 0!");
	}
}
