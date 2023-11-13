#pragma once
#include "Roslina.h"
class WilczeJagody : public Roslina
{
public:
	WilczeJagody(Swiat& obecnySwiat, int pozycjaX, int pozycjaY);

	Roslina* zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) override;
	std::string getNazwa() override;

	void kolizja(Organizm* organizmKolidujacy) override;

	~WilczeJagody();
};

