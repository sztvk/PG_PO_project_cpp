#pragma once
#include "Roslina.h"
class BarszczSosnowskiego : public Roslina
{
public:
	BarszczSosnowskiego();
	BarszczSosnowskiego(int pozycjaX, int pozycjaY);

	std::string getNazwa() override;

	~BarszczSosnowskiego();
};

