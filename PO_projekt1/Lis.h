#pragma once
#include "Zwierze.h"
class Lis : public Zwierze
{
public:
	Lis();
	Lis(int pozycjaX, int pozycjaY);

	std::string getNazwa() override;

	void akcja() override;

	~Lis();
};

