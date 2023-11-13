#pragma once
#include "Swiat.h"

class Swiat;

class Organizm
{
private:
	int sila;
	int inicjatywa;
	int polozenie[2];
	int poprzedniePolozenie[2];
	int wiek;
	char reprezentacjaZnakowa;

	Swiat& obecnySwiat;

protected:
	virtual void walczZOrganizmem(Organizm* przeciwnik);
	virtual bool czyOdbilAtak(int silaAtakujacego);
	virtual bool czyUcieklPrzedWalka();
	virtual bool umiejetnoscSpecjalna(Organizm* organizmDoOdstraszenia);

	virtual void reagujNaZabicie(Organizm* organizmZabity) = 0;
	virtual void reagujNaSmierc(Organizm* organizmKolidujacy) = 0;
	virtual void reagujNaRozmnazanie() = 0;

public:
	Organizm(Swiat& obecnySwiat, int sila, int inicjatywa, int pozycjaX, int pozycjaY, char reprezentacjaZnakowa);
	
	Swiat& getSwiat();
	char getReprezentacjaZnakowa();
	int* getPolozenie();
	int* getPoprzedniePolozenie();
	int getWiek();
	int getSila();
	virtual std::string getNazwa() = 0;

	void setSwiat(Swiat& swiat);
	void setPolozenie(int nowaPozycjaX, int nowaPozycjaY);
	void setPoprzedniePolozenie(int pozycjaX, int pozycjaY);
	void setWiek(int wiek);
	void setSila(int sila);
	virtual Organizm* zwrocNowyOrganizmTegoTypu(Swiat& swiat, int pozycjaX, int pozycjaY) = 0;

	void postarzOrganizm();
	std::vector<std::pair<int, int>> zwrocWolnePolaWokolOrganizmu();

	bool operator<(const Organizm& drugiOrganizm) const;

	virtual void akcja() = 0;
	virtual void kolizja(Organizm* organizmAtakowany) = 0;
	void rysowanie();

	virtual bool czyLosowyRuch();

	~Organizm();
};

