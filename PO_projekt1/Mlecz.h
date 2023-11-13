#pragma once
#include "Roslina.h"
class Mlecz : public Roslina
{
public:
	Mlecz(Swiat& obecnySwiat, int pozycjaX, int pozycjaY);

	Roslina* zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) override;
	std::string getNazwa() override;

	void akcja() override;

	~Mlecz();
};

