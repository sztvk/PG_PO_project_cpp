#include "Lis.h"

Lis::Lis()
{
}

Lis::Lis(int pozycjaX, int pozycjaY) : Zwierze(3, 7, pozycjaX, pozycjaY, 'L')
{
}

std::string Lis::getNazwa()
{
	return "Lis";
}

void Lis::akcja()
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
			else if (swiat->polaNaPlanszy[nowaPozycjaX][nowaPozycjaY]->getSila() < getSila())
			{
				kolizja(swiat->polaNaPlanszy[nowaPozycjaX][nowaPozycjaY]);
			}
			else if (swiat->polaNaPlanszy[nowaPozycjaX][nowaPozycjaY]->getSila() >= getSila())
			{
				akcja();
			}
		}
	}
}

Lis::~Lis()
{
}
