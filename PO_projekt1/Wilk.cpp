#include "Wilk.h"

Wilk::Wilk(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) : Zwierze(obecnySwiat, 9, 5, pozycjaX, pozycjaY, 'W')
{
}

Zwierze* Wilk::zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY)
{
    return new Wilk(obecnySwiat, pozycjaX, pozycjaY);
}

std::string Wilk::getNazwa()
{
    return "Wilk";
}

Wilk::~Wilk()
{
}
