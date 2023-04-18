#pragma once
#include "Zwierze.h"
class Zolw : public Zwierze
{
public:
	Zolw();
	Zolw(int pozycjaX, int pozycjaY);

	std::string getNazwa() override;
	void akcja() override;

	~Zolw();
};

