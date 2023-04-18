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
	int zmianaX = 0;
	int zmianaY = 0;
	
	wylosujPozycje(&zmianaX, &zmianaY);

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
			else if(nowaPozycjaX != pozycjaX && nowaPozycjaY != pozycjaY)
			{
				kolizja(swiat->polaNaPlanszy[nowaPozycjaX][nowaPozycjaY]);
			}
		}
	}
}

void Zwierze::kolizja(Organizm* organizmAtakowany)
{
	Swiat* swiat = getSwiat();

	int organizmAtakowanyX = organizmAtakowany->getPolozenie()[0];
	int organizmAtakowanyY = organizmAtakowany->getPolozenie()[1];
	int organizmAtakujacyX = getPolozenie()[0];
	int organizmAtakujacyY = getPolozenie()[1];

	if (getSila() >= organizmAtakowany->getSila())
	{	
		swiat->usunOrganizm(organizmAtakowany);
		if(dynamic_cast<Zwierze*>(this)) swiat->przeniesOrganizm(this, organizmAtakujacyX, organizmAtakujacyY, organizmAtakowanyX, organizmAtakowanyY);
	}
	else if (getSila() < organizmAtakowany->getSila())
	{
		swiat->usunOrganizm(this);
		if (dynamic_cast<Zwierze*>(organizmAtakowany)) swiat->przeniesOrganizm(organizmAtakowany, organizmAtakowanyX, organizmAtakowanyY, organizmAtakujacyX, organizmAtakujacyY);
	}
}

void Zwierze::wylosujPozycje(int* zmianaX, int* zmianaY)
{
	do
	{
		*zmianaX = std::rand() % 3 - 1;
		*zmianaY = std::rand() % 3 - 1;
	} while (*zmianaX == 0 && *zmianaY == 0);
}

Zwierze::~Zwierze()
{
}
