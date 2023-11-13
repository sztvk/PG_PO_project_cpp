#include "Mlecz.h"

Mlecz::Mlecz(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) : Roslina(obecnySwiat, 0, 0, pozycjaX, pozycjaY, 'm')
{
}

Roslina* Mlecz::zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY)
{
    return new Mlecz(obecnySwiat, pozycjaX, pozycjaY);
}

std::string Mlecz::getNazwa()
{
    return "Mlecz";
}

void Mlecz::akcja()
{
    for (int i = 0; i < 3; i++)
    {
        Roslina::akcja();
    }
}

Mlecz::~Mlecz()
{
}
