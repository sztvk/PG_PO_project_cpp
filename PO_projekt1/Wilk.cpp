#include "Wilk.h"

Wilk::Wilk()
{
}

Wilk::Wilk(int pozycjaX, int pozycjaY) : Zwierze(9, 5, pozycjaX, pozycjaY, 'W')
{
}

std::string Wilk::getNazwa()
{
    return "Wilk";
}

Wilk::~Wilk()
{
}
