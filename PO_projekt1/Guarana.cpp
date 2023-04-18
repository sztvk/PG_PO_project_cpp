#include "Guarana.h"

Guarana::Guarana()
{
}

Guarana::Guarana(int pozycjaX, int pozycjaY) : Roslina(0, 0, pozycjaX, pozycjaY, 'g')
{
}

std::string Guarana::getNazwa()
{
    return "Guarana";
}

Guarana::~Guarana()
{
}
