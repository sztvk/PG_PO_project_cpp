#include "Zolw.h"

Zolw::Zolw()
{
}

Zolw::Zolw(int pozycjaX, int pozycjaY) : Zwierze(2, 1, pozycjaX, pozycjaY, 'Z')
{
}

std::string Zolw::getNazwa()
{
    return "Zolw";
}

void Zolw::akcja()
{
	if (rand() % 4 == 0)
	{
		Zwierze::akcja();
	}
}

Zolw::~Zolw()
{
}
