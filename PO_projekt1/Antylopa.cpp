#include "Antylopa.h"

Antylopa::Antylopa(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) : Zwierze(obecnySwiat, 4, 4, pozycjaX, pozycjaY, 'A')
{
}

Zwierze* Antylopa::zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY)
{
	return new Antylopa(obecnySwiat, pozycjaX, pozycjaY);
}

std::string Antylopa::getNazwa()
{
    return "Antylopa";
}

void Antylopa::akcja()
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

void Antylopa::wylosujPozycje(int* zmianaX, int* zmianaY)
{
	do
	{
		*zmianaX = std::rand() % 5 - 2;
		*zmianaY = std::rand() % 5 - 2;
	} while (*zmianaX == 0 && *zmianaY == 0);
}

bool Antylopa::czyUcieklPrzedWalka()
{
	Swiat& swiat = getSwiat();
	if (rand() % 2 == 0)
	{
		int zmianaX = 0, zmianaY = 0;
		int nowaPozycjaX = getPolozenie()[0], nowaPozycjaY = getPolozenie()[1];
		do
		{
			wylosujPozycje(&zmianaX, &zmianaY);
			nowaPozycjaX = getPolozenie()[0] + zmianaX;
			nowaPozycjaY = getPolozenie()[1] + zmianaY;
		} while ((czyWolnePoleDoUcieczki(nowaPozycjaX, nowaPozycjaY)) || (nowaPozycjaX<0 || nowaPozycjaX>getSwiat().getSzerokosc()) || (nowaPozycjaY < 0 || nowaPozycjaY > getSwiat().getWysokosc()));

		setPoprzedniePolozenie(getPolozenie()[0], getPolozenie()[1]);
		setPolozenie(nowaPozycjaX, nowaPozycjaY);

		return true;
	}

	return false;
}

bool Antylopa::czyWolnePoleDoUcieczki(int polozenieX, int polozenieY)
{
	int polozenieDoSprawdzenia[2];
	polozenieDoSprawdzenia[0] = polozenieX;
	polozenieDoSprawdzenia[1] = polozenieY;

	/*Swiat& swiat = getSwiat();
	for (int i = 0; i < swiat.getOrganizmy().size(); i++)
	{
		if (swiat.porownajPolozenie(polozenieDoSprawdzenia, swiat.getOrganizmy()[i]->getPolozenie()) == 0) return false;
	}*/

	Swiat& swiat = getSwiat();
	for (std::vector<Organizm*>::iterator it = swiat.getOrganizmy().begin(); it != swiat.getOrganizmy().end(); it++)
	{
		if (swiat.porownajPolozenie(polozenieDoSprawdzenia, (*it)->getPolozenie()) == 0) return false;
	}

	return true;
}

Antylopa::~Antylopa()
{
}
