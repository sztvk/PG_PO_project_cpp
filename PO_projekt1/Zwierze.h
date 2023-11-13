#pragma once
#include "Organizm.h"
class Zwierze : public Organizm
{
private:
	void rozmnozSie(Zwierze* zwierzeKolidujace);
	void dodajNowourodzoneZwierze(std::vector<std::pair<int, int>> miejscaNaPorod, Swiat& swiat);

protected:
	void reagujNaZabicie(Organizm* organizmZabity) override;
	void reagujNaSmierc(Organizm* organizmKolidujacy) override;
	void reagujNaRozmnazanie() override;
	virtual void wylosujPozycje(int* zmianaX, int* zmianaY);

public:
	Zwierze(Swiat& obecnySwiat, int sila, int inicjatywa, int pozycjaX, int pozycjaY, char reprezentacjaZnakowa);

	void akcja() override;
	void kolizja(Organizm* organizmAtakowany) override;

	~Zwierze();
};

