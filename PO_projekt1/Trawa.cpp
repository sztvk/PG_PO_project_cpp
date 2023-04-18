#include "Trawa.h"

Trawa::Trawa()
{
}

Trawa::Trawa(int pozycjaX, int pozycjaY) : Roslina(0, 0, pozycjaX, pozycjaY, 't')
{
}

std::string Trawa::getNazwa()
{
    return "Trawa";
}

Trawa::~Trawa()
{
}
