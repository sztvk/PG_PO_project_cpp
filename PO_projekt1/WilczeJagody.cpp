#include "WilczeJagody.h"

WilczeJagody::WilczeJagody()
{
}

WilczeJagody::WilczeJagody(int pozycjaX, int pozycjaY) : Roslina(99, 0, pozycjaX, pozycjaY, 'j')
{
}

std::string WilczeJagody::getNazwa()
{
    return "Wilcze jagody";
}

WilczeJagody::~WilczeJagody()
{
}
