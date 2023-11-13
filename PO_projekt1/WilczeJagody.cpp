#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) : Roslina(obecnySwiat, 99, 0, pozycjaX, pozycjaY, 'j')
{
}

Roslina* WilczeJagody::zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY)
{
    return new WilczeJagody(obecnySwiat, pozycjaX, pozycjaY);
}

std::string WilczeJagody::getNazwa()
{
    return "Wilcze jagody";
}

void WilczeJagody::kolizja(Organizm* organizmKolidujacy)
{
    setWiek(0);
    organizmKolidujacy->setWiek(0);
    reagujNaSmierc(organizmKolidujacy);
}

WilczeJagody::~WilczeJagody()
{
}
