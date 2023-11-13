#pragma once
#include "Roslina.h"
class BarszczSosnowskiego : public Roslina
{
private:
	void zabijZwierzetaWokol();

public:
	BarszczSosnowskiego(Swiat& obecnySwiat, int pozycjaX, int pozycjaY);

	Roslina* zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) override;
	std::string getNazwa() override;

	void akcja() override;
	void kolizja(Organizm* organizmKolidujacy) override;

	~BarszczSosnowskiego();
};

