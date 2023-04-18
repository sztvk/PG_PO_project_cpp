#pragma once
#include "Roslina.h"
class Guarana : public Roslina
{
public:
	Guarana();
	Guarana(int pozycjaX, int pozycjaY);

	std::string getNazwa() override;

	~Guarana();
};

