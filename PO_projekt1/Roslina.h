#pragma once
#include "Organizm.h"

class Roslina : public Organizm
{
public:
	Roslina();
	Roslina(int sila, int inicjatywa, int pozycjaX, int pozycjaY, char reprezentacjaZnakowa);
	void akcja() override;
	void kolizja(Organizm* organizmAtakowany) override;
	~Roslina();
};

