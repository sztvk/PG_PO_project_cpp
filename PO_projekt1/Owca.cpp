#include "Owca.h"

Owca::Owca()
{
}

Owca::Owca(int pozycjaX, int pozycjaY) : Zwierze(4, 4, pozycjaX, pozycjaY, 'O')
{
}

std::string Owca::getNazwa()
{
    return "Owca";
}

Owca::~Owca()
{
}
