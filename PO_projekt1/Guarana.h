#pragma once
#include "Roslina.h"
class Guarana : public Roslina
{
public:
	Guarana(Swiat& obecnySwiat, int pozycjaX, int pozycjaY);

	Roslina* zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) override;
	std::string getNazwa() override;

	void kolizja(Organizm* organizmKolidujacy) override;

	~Guarana();
};

