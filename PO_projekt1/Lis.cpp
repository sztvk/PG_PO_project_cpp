#include "Lis.h"

Lis::Lis()
{
}

Lis::Lis(int pozycjaX, int pozycjaY) : Zwierze(3, 7, pozycjaX, pozycjaY, 'L')
{
}

void Lis::akcja()
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
			else if (swiat->polaNaPlanszy[nowaPozycjaX][nowaPozycjaY]->getSila() > getSila())
			{
				// ponowna proba ruchu 
				akcja();
			}
		}
	}
}

Lis::~Lis()
{
}
