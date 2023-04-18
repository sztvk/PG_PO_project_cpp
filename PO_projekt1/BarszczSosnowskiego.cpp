#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego()
{
}

BarszczSosnowskiego::BarszczSosnowskiego(int pozycjaX, int pozycjaY) : Roslina(10, 0, pozycjaX, pozycjaY, 'b')
{
}

std::string BarszczSosnowskiego::getNazwa()
{
    return "Barszcz sosnowskiego";
}

BarszczSosnowskiego::~BarszczSosnowskiego()
{
}
