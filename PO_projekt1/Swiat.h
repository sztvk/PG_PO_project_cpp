#pragma once
#include <vector>
#include <iostream>
#include "Organizm.h"

#define INPUT_STRZALEK 224
#define STRZALKA_GORA 72
#define STRZALKA_DOL 80
#define STRZALKA_LEWO 75
#define STRZALKA_PRAWO 77

class Organizm;

class Swiat
{
private:
	int wysokosc;
	int szerokosc;
	int numerTury;

	std::vector<Organizm*> organizmy;

public:
	std::vector< std::vector< Organizm* >> polaNaPlanszy;

	Swiat();
	Swiat(int szerokosc, int wysokosc);

	int getWysokosc();
	int getSzerokosc();

	void przebiegGry();
	void wykonajTure();
	void rysujSwiat();

	void handleInput(int input);
	
	void dodajPoczatkoweOrganizmy();
	void dodajOrganizmDoStruktur(Organizm* nowyOrganizm);

	void usunOrganizm(Organizm* organizmDoUsuniecia);
	int znajdzPozycjewWektorzeOrganizmow(Organizm* organizm);

	static bool porownajDwaOrganizmy(const Organizm* pierwszyOrganizm, const Organizm* drugiOrganizm);
	void posortujOrganizmy();

	void przeniesOrganizm(Organizm* organizmDoPrzeniesienia, int staraPozycjaX, int staraPozycjaY, int nowaPozycjaX, int nowaPozycjaY);

	std::vector<Organizm*> getOrganizmy();

	~Swiat();
};