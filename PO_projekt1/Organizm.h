#pragma once
#include "Swiat.h"

class Swiat;

class Organizm
{
private:
	int sila;
	int inicjatywa;
	int polozenie[2];
	int wiek;
	char reprezentacjaZnakowa;

	Swiat* obecnySwiat;

public:
	Organizm();
	Organizm(int sila, int inicjatywa, int pozycjaX, int pozycjaY, char reprezentacjaZnakowa);
	
	Swiat* getSwiat();
	char getReprezentacjaZnakowa();
	int* getPolozenie();
	int getWiek();
	int getSila();
	virtual std::string getNazwa() = 0;

	void setSwiat(Swiat* swiat);
	void setPolozenie(int nowaPozycjaX, int nowaPozycjaY);

	void postarzOrganizm();

	bool operator<(const Organizm& drugiOrganizm) const;

	virtual void akcja() = 0;					// zachowanie organizmu w trakcie gry
	virtual void kolizja(Organizm* organizmAtakowany) = 0;				// zachowanie organizmu w trakcie kolizji
	void rysowanie();
	~Organizm();
};

