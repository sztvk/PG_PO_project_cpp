#include "Mlecz.h"

Mlecz::Mlecz()
{
}

Mlecz::Mlecz(int pozycjaX, int pozycjaY) : Roslina(0, 0, pozycjaX, pozycjaY, 'm')
{
}

std::string Mlecz::getNazwa()
{
    return "Mlecz";
}

Mlecz::~Mlecz()
{
}
