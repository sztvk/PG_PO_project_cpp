#pragma once
#include "Zwierze.h"
class Lis : public Zwierze
{
public:
	Lis();
	Lis(int pozycjaX, int pozycjaY);

	void akcja() override;

	~Lis();
};

