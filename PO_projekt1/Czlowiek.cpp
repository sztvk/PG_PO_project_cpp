#include "Czlowiek.h"

Czlowiek::Czlowiek()
{
}

Czlowiek::Czlowiek(int pozycjaX, int pozycjaY) : Zwierze(5, 4, pozycjaX, pozycjaY, 'C')
{
}

void Czlowiek::akcja()
{
	Swiat* obecnySwiat = getSwiat();
	
	int staraPozycjaX, staraPozycjaY;
	staraPozycjaX = getPolozenie()[0];
	staraPozycjaY = getPolozenie()[1];
	int nowaPozycjaX = staraPozycjaX;
	int nowaPozycjaY = staraPozycjaY;

	if (ostatniRuch == GORA) nowaPozycjaY = staraPozycjaY - 1;
	else if (ostatniRuch == DOL) nowaPozycjaY = staraPozycjaY + 1;
	else if (ostatniRuch == LEWO) nowaPozycjaX = staraPozycjaX - 1;
	else if (ostatniRuch == PRAWO) nowaPozycjaX = staraPozycjaX + 1;

	if (nowaPozycjaX >= 0 && nowaPozycjaX < obecnySwiat->getSzerokosc())
	{
		if (nowaPozycjaY >= 0 && nowaPozycjaY < obecnySwiat->getWysokosc())
		{
			if (obecnySwiat->polaNaPlanszy[nowaPozycjaX][nowaPozycjaY] == nullptr)
			{
				obecnySwiat->przeniesOrganizm(this, staraPozycjaX, staraPozycjaY, nowaPozycjaX, nowaPozycjaY);
			}
			else
			{
				kolizja(obecnySwiat->polaNaPlanszy[nowaPozycjaX][nowaPozycjaY]);
			}
		}
	}
}

void Czlowiek::setKierunekRuchu(KierunekRuchuCzlowieka nowyKierunekRuchu)
{
	this->ostatniRuch = nowyKierunekRuchu;
}

Czlowiek::~Czlowiek()
{
}
