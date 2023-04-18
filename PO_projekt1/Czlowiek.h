#pragma once
#include "Zwierze.h"

enum KierunekRuchuCzlowieka
{
	GORA, DOL, PRAWO, LEWO, BRAK
};

class Czlowiek : public Zwierze
{
private:
	KierunekRuchuCzlowieka ostatniRuch;
public:
	Czlowiek();
	Czlowiek(int pozycjaX, int pozycjaY);

	std::string getNazwa() override;

	void akcja() override;
	void setKierunekRuchu(KierunekRuchuCzlowieka nowyKierunekRuchu);

	~Czlowiek();
};

