#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Organizm.h"

#define INPUT_STRZALEK 224
#define STRZALKA_GORA 72
#define STRZALKA_DOL 80
#define STRZALKA_LEWO 75
#define STRZALKA_PRAWO 77

#define ODSTEP_UMIEJETNOSC_SPECJALNA 5

class Organizm;

class Swiat
{
private:
	int wysokosc;
	int szerokosc;
	int numerTury;
	int licznikUmiejetnosciSpecjalnejWTurach;
	
	int liczbaZdarzen;

	std::vector<Organizm*> organizmy;
	std::vector<std::string> zdarzenia;
	std::vector< std::vector< Organizm* >> polaNaPlanszy;

	void wybierzTryb();
	void wykonajTure();
	void rysujSwiat();
	void uaktualnijPlansze();

	void obsluzInput(int input);

	void dodajPoczatkoweOrganizmy();
	void dodajOrganizmDoStruktur(Organizm* nowyOrganizm);
	
	int znajdzPozycjewWektorzeOrganizmow(Organizm* organizm);

	void postarzOrganizmy();

	static bool porownajDwaOrganizmy(const Organizm* pierwszyOrganizm, const Organizm* drugiOrganizm);
	void posortujOrganizmy();

	void przeniesOrganizm(Organizm* organizmDoPrzeniesienia, int staraPozycjaX, int staraPozycjaY, int nowaPozycjaX, int nowaPozycjaY);
	bool sprawdzCzyKolizjaDlaDwochOrganizmow(Organizm* organizm1, Organizm* organizm2);
	void wywolajKolizje(Organizm* organizm1, Organizm* organizm2);
	void sprawdzKolizje(Organizm* sprawdzanyOrganizm);

	void obsluzLicznikUmiejetnosciSpecjalnejGracza();

	void zapiszStanSwiata(std::string nazwaPliku);
	void wczytajStanSwiataZPliku(std::string nazwaPliku);
	void dodajOrganizmNaPodstawiePliku(std::string wiersz);
	std::string odczytajKolejnyElementWiersza(int& separatorIndex, int& separatorIndexNastepny, std::string wiersz);

public:
	
	Swiat();
	Swiat(int szerokosc, int wysokosc);

	int getWysokosc() const;
	int getSzerokosc() const;
	int getLicznikUmiejetnosciSpecjalnej() const;
	std::vector<Organizm*>& getOrganizmy();
	std::vector<std::string>& getZdarzenia();
	std::vector< std::vector< Organizm* >> getPolaNaPlanszy() const;

	void setLicznikUmiejetnosciSpecjalnej(int aktualnyLicznikUmiejetnosciSpecjalnej);
	bool porownajPolozenie(int* polozenie1, int* polozenie2);

	void usunOrganizm(Organizm* organizmDoUsuniecia);

	void przebiegGry();
	void wyczyscSwiat();

	~Swiat();
};