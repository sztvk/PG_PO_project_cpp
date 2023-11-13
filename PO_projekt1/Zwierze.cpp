#include "Zwierze.h"

Zwierze::Zwierze(Swiat& obecnySwiat, int sila, int inicjatywa, int pozycjaX, int pozycjaY, char reprezentacjaZnakowa) : Organizm(obecnySwiat, sila, inicjatywa, pozycjaX, pozycjaY, reprezentacjaZnakowa)
{

}

void Zwierze::akcja()
{
	int pozycjaX, pozycjaY;
	pozycjaX = getPolozenie()[0];
	pozycjaY = getPolozenie()[1];
	int zmianaX = 0;
	int zmianaY = 0;
	
	wylosujPozycje(&zmianaX, &zmianaY);

	int nowaPozycjaX = pozycjaX + zmianaX;
	int nowaPozycjaY = pozycjaY + zmianaY;

	Swiat& swiat = getSwiat();

	if (nowaPozycjaX >= 0 && nowaPozycjaX < swiat.getSzerokosc())
	{
		if (nowaPozycjaY >= 0 && nowaPozycjaY < swiat.getWysokosc())
		{
			setPoprzedniePolozenie(getPolozenie()[0], getPolozenie()[1]);
			setPolozenie(nowaPozycjaX, nowaPozycjaY);
		}
	}
}

void Zwierze::kolizja(Organizm* organizmAtakowany)
{
	Swiat& swiat = getSwiat();
	if (!swiat.porownajPolozenie(this->getPolozenie(), organizmAtakowany->getPolozenie())) return;

	if (dynamic_cast<Zwierze*>(organizmAtakowany))
	{
		if (getReprezentacjaZnakowa() == organizmAtakowany->getReprezentacjaZnakowa()) // to samo zwierze
		{
			rozmnozSie(dynamic_cast<Zwierze*>(organizmAtakowany));
		}
		else // pojedynek
		{
			walczZOrganizmem(organizmAtakowany);
		}
	}
}

void Zwierze::rozmnozSie(Zwierze* zwierzeKolidujace)
{
	Swiat& swiat = getSwiat();
	setPolozenie(getPoprzedniePolozenie()[0], getPoprzedniePolozenie()[1]);

	if (swiat.getOrganizmy().size() == swiat.getSzerokosc() * swiat.getWysokosc()) return;

	std::vector<std::pair<int, int>> wolnePolaWokolOrganizm1 = zwrocWolnePolaWokolOrganizmu();
	std::vector<std::pair<int, int>> wolnePolaWokolOrganizm2 = zwierzeKolidujace->zwrocWolnePolaWokolOrganizmu();
	if (wolnePolaWokolOrganizm1.empty() && wolnePolaWokolOrganizm2.empty()) return;

	if (wolnePolaWokolOrganizm1.size() >= wolnePolaWokolOrganizm2.size())dodajNowourodzoneZwierze(wolnePolaWokolOrganizm1, swiat);
	else dodajNowourodzoneZwierze(wolnePolaWokolOrganizm2, swiat);
}

void Zwierze::dodajNowourodzoneZwierze(std::vector<std::pair<int, int>> miejscaNaPorod, Swiat& swiat)
{
	int wylosowanePole = rand() % miejscaNaPorod.size();

	swiat.getOrganizmy().push_back(zwrocNowyOrganizmTegoTypu(swiat, miejscaNaPorod[wylosowanePole].first, miejscaNaPorod[wylosowanePole].second));
	reagujNaRozmnazanie();
}

void Zwierze::wylosujPozycje(int* zmianaX, int* zmianaY)
{
	do
	{
		*zmianaX = std::rand() % 3 - 1;
		*zmianaY = std::rand() % 3 - 1;
	} while (*zmianaX == 0 && *zmianaY == 0);
}

void Zwierze::reagujNaZabicie(Organizm* organizmZabity)
{
	std::string noweZdarzenie = "Zwierze gatunku: " + getNazwa() + " zabilo zwierze gatunku: " + organizmZabity->getNazwa();
	getSwiat().getZdarzenia().push_back(noweZdarzenie);
}

void Zwierze::reagujNaSmierc(Organizm* organizmKolidujacy)
{
	std::string noweZdarzenie = "Zwierze gatunku: " + getNazwa() + " zostaje zabite przez zwierze gatunku: " + organizmKolidujacy->getNazwa();
	getSwiat().getZdarzenia().push_back(noweZdarzenie);
}

void Zwierze::reagujNaRozmnazanie()
{
	std::string noweZdarzenie = "Zwierze gatunku: " + getNazwa() + " rozmnozylo sie!";
	getSwiat().getZdarzenia().push_back(noweZdarzenie);
}

Zwierze::~Zwierze()
{
}
