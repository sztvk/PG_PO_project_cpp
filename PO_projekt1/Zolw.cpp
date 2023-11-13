#include "Zolw.h"

Zolw::Zolw(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) : Zwierze(obecnySwiat, 2, 1, pozycjaX, pozycjaY, 'Z')
{
}

Zwierze* Zolw::zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY)
{
	return new Zolw(obecnySwiat, pozycjaX, pozycjaY);
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

bool Zolw::czyOdbilAtak(int silaAtakujacego)
{
	if (silaAtakujacego < 5 ) return true;
	else return false;
}

Zolw::~Zolw()
{
}
