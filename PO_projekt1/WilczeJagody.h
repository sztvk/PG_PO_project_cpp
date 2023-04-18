#pragma once
#include "Roslina.h"
class WilczeJagody : public Roslina
{
public:
	WilczeJagody();
	WilczeJagody(int pozycjaX, int pozycjaY);

	std::string getNazwa() override;

	~WilczeJagody();
};

