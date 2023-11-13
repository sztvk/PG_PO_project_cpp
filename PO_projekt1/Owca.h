#pragma once
#include "Zwierze.h"
class Owca : public Zwierze
{
public:
	Owca(Swiat& obecnySwiat, int pozycjaX, int pozycjaY);

	Zwierze* zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) override;
	std::string getNazwa() override;

	~Owca();
};

