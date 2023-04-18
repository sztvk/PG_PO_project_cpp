#include "Antylopa.h"

Antylopa::Antylopa()
{
}

Antylopa::Antylopa(int pozycjaX, int pozycjaY) : Zwierze(4, 4, pozycjaX, pozycjaY, 'A')
{
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

	int nowaPozycjaX = pozycjaX + 2*zmianaX;
	int nowaPozycjaY = pozycjaY + 2*zmianaY;

	Swiat* swiat = getSwiat();

	if (nowaPozycjaX >= 0 && nowaPozycjaX < swiat->getSzerokosc())
	{
		if (nowaPozycjaY >= 0 && nowaPozycjaY < swiat->getWysokosc())
		{
			if (swiat->polaNaPlanszy[nowaPozycjaX][nowaPozycjaY] == nullptr)
			{
				swiat->przeniesOrganizm(this, pozycjaX, pozycjaY, nowaPozycjaX, nowaPozycjaY);
			}
			else if (nowaPozycjaX != pozycjaX && nowaPozycjaY != pozycjaY)
			{
				kolizja(swiat->polaNaPlanszy[nowaPozycjaX][nowaPozycjaY]);
			}
		}
	}
}

Antylopa::~Antylopa()
{
}
