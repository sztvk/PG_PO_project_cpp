#pragma once
#include "Organizm.h"
class Zwierze : public Organizm
{
public:
	Zwierze();
	Zwierze(int sila, int inicjatywa, int pozycjaX, int pozycjaY, char reprezentacjaZnakowa);

	void akcja() override;
	void kolizja(Organizm* organizmAtakowany) override;

	void wylosujPozycje(int* zmianaX, int* zmianaY);
	
	~Zwierze();
};

