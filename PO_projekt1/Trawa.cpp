#include "Trawa.h"

Trawa::Trawa(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) : Roslina(obecnySwiat, 0, 0, pozycjaX, pozycjaY, 't')
{
}

Roslina* Trawa::zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY)
{
    return new Trawa(obecnySwiat, pozycjaX, pozycjaY);
}

std::string Trawa::getNazwa()
{
    return "Trawa";
}

Trawa::~Trawa()
{
}
