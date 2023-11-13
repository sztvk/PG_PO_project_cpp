#pragma once
#include "Roslina.h"
class Trawa : public Roslina
{
public:
	Trawa(Swiat& obecnySwiat, int pozycjaX, int pozycjaY);

	Roslina* zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) override;
	std::string getNazwa() override;

	~Trawa();
};

