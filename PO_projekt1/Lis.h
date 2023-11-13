#pragma once
#include "Zwierze.h"
class Lis : public Zwierze
{
public:
	Lis(Swiat& obecnySwiat, int pozycjaX, int pozycjaY);

	Zwierze* zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) override;
	std::string getNazwa() override;

	void akcja() override;

	~Lis();
};

