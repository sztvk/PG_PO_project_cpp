#pragma once
#include "Zwierze.h"
class Antylopa : public Zwierze
{
public:
	Antylopa();
	Antylopa(int pozycjaX, int pozycjaY);

	std::string getNazwa() override;

	void akcja() override;

	~Antylopa();
};

