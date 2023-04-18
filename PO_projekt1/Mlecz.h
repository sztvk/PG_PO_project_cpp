#pragma once
#include "Roslina.h"
class Mlecz : public Roslina
{
public:
	Mlecz();
	Mlecz(int pozycjaX, int pozycjaY);

	std::string getNazwa() override;

	~Mlecz();
};

