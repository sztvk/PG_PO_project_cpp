#pragma once
#include "Zwierze.h"
class Antylopa : public Zwierze
{
private:
	void wylosujPozycje(int* zmianaX, int* zmianaY);
	bool czyWolnePoleDoUcieczki(int polozenieX, int polozenieY);

protected:
	bool czyUcieklPrzedWalka() override;

public:
	Antylopa(Swiat& obecnySwiat, int pozycjaX, int pozycjaY);

	Zwierze* zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) override;
	std::string getNazwa() override;

	void akcja() override;

	~Antylopa();
};

