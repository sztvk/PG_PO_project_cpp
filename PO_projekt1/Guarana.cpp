#include "Guarana.h"

Guarana::Guarana(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) : Roslina(obecnySwiat, 0, 0, pozycjaX, pozycjaY, 'g')
{
}

Roslina* Guarana::zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY)
{
    return new Guarana(obecnySwiat, pozycjaX, pozycjaY);
}

std::string Guarana::getNazwa()
{
    return "Guarana";
}

void Guarana::kolizja(Organizm* organizmKolidujacy)
{
    setWiek(0);
    reagujNaSmierc(organizmKolidujacy);
    organizmKolidujacy->setSila(organizmKolidujacy->getSila() + 3);
    int i = 0;
}

Guarana::~Guarana()
{
}
