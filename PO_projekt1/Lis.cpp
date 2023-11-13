#include "Lis.h"

Lis::Lis(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) : Zwierze(obecnySwiat, 3, 7, pozycjaX, pozycjaY, 'L')
{
}

Zwierze* Lis::zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY)
{
	return new Lis(obecnySwiat, pozycjaX, pozycjaY);
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

	Swiat& swiat = getSwiat();

	if (nowaPozycjaX >= 0 && nowaPozycjaX < swiat.getSzerokosc())
	{
		if (nowaPozycjaY >= 0 && nowaPozycjaY < swiat.getWysokosc())
		{
			if (swiat.getPolaNaPlanszy()[nowaPozycjaX][nowaPozycjaY] != nullptr)
			{
				if (swiat.getPolaNaPlanszy()[nowaPozycjaX][nowaPozycjaY]->getSila() >= getSila()) return;
			}
			setPoprzedniePolozenie(getPolozenie()[0], getPolozenie()[1]);
			setPolozenie(nowaPozycjaX, nowaPozycjaY);
		}
	}
}

Lis::~Lis()
{
}
