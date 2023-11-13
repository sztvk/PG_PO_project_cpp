#include "Owca.h"

Owca::Owca(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) : Zwierze(obecnySwiat, 4, 4, pozycjaX, pozycjaY, 'O')
{
}

Zwierze* Owca::zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY)
{
    return new Owca(obecnySwiat, pozycjaX, pozycjaY);
}

std::string Owca::getNazwa()
{
    return "Owca";
}

Owca::~Owca()
{
}
