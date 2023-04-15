#include "Zwierze.h"

Zwierze::Zwierze()
{
}

Zwierze::Zwierze(int sila, int inicjatywa, int pozycjaX, int pozycjaY, char reprezentacjaZnakowa) : Organizm(sila, inicjatywa, pozycjaX, pozycjaY, reprezentacjaZnakowa)
{

}

void Zwierze::akcja()
{
	int pozycjaX, pozycjaY;
	pozycjaX = getPolozenie()[0];
	pozycjaY = getPolozenie()[1];

	int zmianaX = std::rand() % 3 - 1;
	int zmianaY = std::rand() % 3 - 1;

	int nowaPozycjaX = pozycjaX + zmianaX;
	int nowaPozycjaY = pozycjaY + zmianaY;

	Swiat* swiat = getSwiat();

	if (nowaPozycjaX >= 0 && nowaPozycjaX < swiat->getSzerokosc())
	{
		if (nowaPozycjaY >= 0 && nowaPozycjaY < swiat->getWysokosc())
		{
			if (swiat->polaNaPlanszy[nowaPozycjaX][nowaPozycjaY] == nullptr)
			{
				swiat->przeniesOrganizm(this, pozycjaX, pozycjaY, nowaPozycjaX, nowaPozycjaY);
			}
			else
			{
				kolizja(swiat->polaNaPlanszy[nowaPozycjaX][nowaPozycjaY]);
			}
		}
	}
}

void Zwierze::kolizja(Organizm* organizmAtakowany)
{
	Swiat* swiat = getSwiat();
	if (getSila() > organizmAtakowany->getSila() || getSila() == organizmAtakowany->getSila())
	{
		//setPolozenie(organizmAtakowany->getPolozenie()[0], organizmAtakowany->getPolozenie()[1]);
		swiat->przeniesOrganizm(this, getPolozenie()[0], getPolozenie()[1], organizmAtakowany->getPolozenie()[0], organizmAtakowany->getPolozenie()[1]);
		swiat->usunOrganizm(organizmAtakowany);
	}
	else if (getSila() < organizmAtakowany->getSila())
	{
		//organizmAtakowany->setPolozenie(getPolozenie()[0], getPolozenie()[1]);
		swiat->przeniesOrganizm(organizmAtakowany, organizmAtakowany->getPolozenie()[0], organizmAtakowany->getPolozenie()[1], getPolozenie()[0], getPolozenie()[1]);
		swiat->usunOrganizm(this);
	}
}

Zwierze::~Zwierze()
{
}
