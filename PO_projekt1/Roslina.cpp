#include "Roslina.h"

Roslina::Roslina(Swiat& obecnySwiat, int sila, int inicjatywa, int pozycjaX, int pozycjaY, char reprezentacjaZnakowa) : Organizm(obecnySwiat, sila, inicjatywa, pozycjaX, pozycjaY, reprezentacjaZnakowa)
{
	szansaNaZasianie = 10;
	setPoprzedniePolozenie(pozycjaX, pozycjaY);
}

void Roslina::akcja()
{
	Swiat& swiat = getSwiat();
	if (swiat.getOrganizmy().size() == swiat.getSzerokosc() * swiat.getWysokosc()) return; // brak miejsca na swiecie, wszystkie pola zajete

	std::vector<std::pair<int, int>> wolnePolaWokol = zwrocWolnePolaWokolOrganizmu();
	if (wolnePolaWokol.empty()) return;

	int los = rand() % 100 + 1;
	if (los <= szansaNaZasianie)
	{
		int wylosowanePole = rand() % wolnePolaWokol.size();
		swiat.getOrganizmy().push_back(zwrocNowyOrganizmTegoTypu(swiat, wolnePolaWokol[wylosowanePole].first, wolnePolaWokol[wylosowanePole].second));
		
		reagujNaRozmnazanie();
	}
}

void Roslina::kolizja(Organizm* organizmKolidujacy)
{
	setWiek(0);
	reagujNaSmierc(organizmKolidujacy);
}

void Roslina::reagujNaZabicie(Organizm* organizmZabity)
{
	std::string noweZdarzenie = "Roslina gatunku: " + getNazwa() + " zabija zwierze gatunku: " + organizmZabity->getNazwa();
	getSwiat().getZdarzenia().push_back(noweZdarzenie);
}

void Roslina::reagujNaSmierc(Organizm* organizmKolidujacy)
{
	std::string noweZdarzenie = "Roslina gatunku: " + getNazwa() + " zostaje zjedzona przez zwierze gatunku: " + organizmKolidujacy->getNazwa();
	getSwiat().getZdarzenia().push_back(noweZdarzenie);
}

void Roslina::reagujNaRozmnazanie()
{
	std::string noweZdarzenie = "Roslina gatunku: " + getNazwa() + " rozsiala sie!";
	getSwiat().getZdarzenia().push_back(noweZdarzenie);
}

Roslina::~Roslina()
{
}
