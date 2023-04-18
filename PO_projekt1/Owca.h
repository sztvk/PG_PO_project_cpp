#pragma once
#include "Zwierze.h"
class Owca : public Zwierze
{
public:
	Owca();
	Owca(int pozycjaX, int pozycjaY);

	std::string getNazwa() override;

	~Owca();
};

