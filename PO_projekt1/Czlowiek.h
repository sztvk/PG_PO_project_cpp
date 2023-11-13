#pragma once
#include <conio.h>
#include "Zwierze.h"

#define UMIEJETNOSC_SPECJALNA_CZAS_TRWANIA 5 // w rundach

enum KierunekRuchuCzlowieka
{
	GORA, DOL, PRAWO, LEWO, BRAK
};

class Czlowiek : public Zwierze
{
private:
	int ileZostaloUmiejetnosciSpecjalnej;
	bool tarczaAlzuraAktywowana;
	KierunekRuchuCzlowieka ostatniRuch;

	bool umiejetnoscSpecjalna(Organizm* organizmDoOdstraszenia) override;
	void ustalRuch(int* input);

public:
	Czlowiek(Swiat& obecnySwiat, int pozycjaX, int pozycjaY);

	Zwierze* zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) override;
	
	std::string getNazwa() override;
	int getIleZostaloUmiejetnosciSpecjalnej() const;
	
	void setIleZostaloUmiejetnosciSpecjalnej(int ileZostalo);
	void setKierunekRuchu(KierunekRuchuCzlowieka nowyKierunekRuchu);
	
	bool czyLosowyRuch() override;
	
	void uruchomUmiejetnoscSpecjalna();
	void zmienLicznikiUmiejetnosciSpecjalnej();

	void akcja() override;
	
	~Czlowiek();
};

