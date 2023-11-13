#pragma once
#include "Zwierze.h"
class Wilk : public Zwierze
{
public:
	Wilk(Swiat& obecnySwiat, int pozycjaX, int pozycjaY);

	Zwierze* zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) override;
	std::string getNazwa() override;

	~Wilk();
};

