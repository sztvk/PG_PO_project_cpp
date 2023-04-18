#pragma once
#include "Roslina.h"
class Trawa : public Roslina
{
public:
	Trawa();
	Trawa(int pozycjaX, int pozycjaY);

	std::string getNazwa() override;

	~Trawa();
};

