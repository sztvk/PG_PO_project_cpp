#pragma once
#include "Zwierze.h"
class Zolw : public Zwierze
{
protected:
	bool czyOdbilAtak(int silaAtakujacego) override;

public:
	Zolw(Swiat& obecnySwiat, int pozycjaX, int pozycjaY);

	Zwierze* zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) override;
	std::string getNazwa() override;
	
	void akcja() override;

	~Zolw();
};

