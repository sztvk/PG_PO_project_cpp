#pragma once
#include "Organizm.h"

class Roslina : public Organizm
{
protected:
	int szansaNaZasianie;
	void reagujNaZabicie(Organizm* organizmZabity) override;
	void reagujNaSmierc(Organizm* organizmKolidujacy) override;
	void reagujNaRozmnazanie() override;

public:
	Roslina(Swiat& obecnySwiat, int sila, int inicjatywa, int pozycjaX, int pozycjaY, char reprezentacjaZnakowa);

	void akcja() override;
	void kolizja(Organizm* organizmKolidujacy) override;

	~Roslina();
};

