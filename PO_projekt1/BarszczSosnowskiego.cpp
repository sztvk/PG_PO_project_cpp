#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) : Roslina(obecnySwiat, 10, 0, pozycjaX, pozycjaY, 'b')
{
}

Roslina* BarszczSosnowskiego::zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY)
{
    return new BarszczSosnowskiego(obecnySwiat, pozycjaX, pozycjaY);
}

std::string BarszczSosnowskiego::getNazwa()
{
    return "Barszcz sosnowskiego";
}

void BarszczSosnowskiego::akcja()
{
    zabijZwierzetaWokol();
}

void BarszczSosnowskiego::kolizja(Organizm* organizmKolidujacy)
{
    setWiek(0);
    organizmKolidujacy->setWiek(0);
    reagujNaSmierc(organizmKolidujacy);
}

void BarszczSosnowskiego::zabijZwierzetaWokol()
{
    Swiat& swiat = getSwiat();

    for (int x = -1; x <= 1; x++)
    {
        for (int y = -1; y <= 1; y++)
        {
            if (x == 0 && y == 0) continue;
            int sasiedniePolozenie[2] = { getPolozenie()[0] + x, getPolozenie()[1] + y };

            for (std::vector<Organizm*>::iterator it = swiat.getOrganizmy().begin(); it != swiat.getOrganizmy().end(); it++)
            {
                if (swiat.porownajPolozenie(sasiedniePolozenie, (*it)->getPolozenie()))
                {
                    Roslina* sprawdzenieCzyRoslina = dynamic_cast<Roslina*>(*it);
                    if (sprawdzenieCzyRoslina == nullptr)
                    {
                        reagujNaZabicie(*it);
                        delete* it;
                        it = swiat.getOrganizmy().erase(it);
                    }
                }
            }
        }
    }
}

BarszczSosnowskiego::~BarszczSosnowskiego()
{
}
