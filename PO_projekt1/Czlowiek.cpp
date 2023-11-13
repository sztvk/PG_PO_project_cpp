#include "Czlowiek.h"

Czlowiek::Czlowiek(Swiat& obecnySwiat, int pozycjaX, int pozycjaY) : Zwierze(obecnySwiat, 5, 5, pozycjaX, pozycjaY, 'C')
{
	ileZostaloUmiejetnosciSpecjalnej = 0;
	tarczaAlzuraAktywowana = false;
}

Zwierze* Czlowiek::zwrocNowyOrganizmTegoTypu(Swiat& obecnySwiat, int pozycjaX, int pozycjaY)
{
	return new Czlowiek(obecnySwiat, pozycjaX, pozycjaY);
}

std::string Czlowiek::getNazwa()
{
	return "Czlowiek";
}

int Czlowiek::getIleZostaloUmiejetnosciSpecjalnej() const
{
	return ileZostaloUmiejetnosciSpecjalnej;
}

void Czlowiek::setIleZostaloUmiejetnosciSpecjalnej(int ileZostalo)
{
	ileZostaloUmiejetnosciSpecjalnej = ileZostalo;
}

bool Czlowiek::umiejetnoscSpecjalna(Organizm* organizmDoOdstraszenia)
{
	Swiat& swiat = getSwiat();

	if (ileZostaloUmiejetnosciSpecjalnej > 0)
	{
		std::vector<std::pair<int, int>> wolnePolaWokol = zwrocWolnePolaWokolOrganizmu();
		if (wolnePolaWokol.empty()) return false;

		int wylosowanePole = rand() % wolnePolaWokol.size();
		organizmDoOdstraszenia->setPolozenie(wolnePolaWokol[wylosowanePole].first, wolnePolaWokol[wylosowanePole].second);
		setPolozenie(getPolozenie()[0], getPolozenie()[1]);
		return true;
	}

	return false;
}

bool Czlowiek::czyLosowyRuch()
{
	return false;
}

void Czlowiek::ustalRuch(int* input)
{
	*input = _getch();
	KierunekRuchuCzlowieka kierunekRuchu = BRAK;

	if (*input == STRZALKA_GORA) kierunekRuchu = GORA;
	else if (*input == STRZALKA_DOL) kierunekRuchu = DOL;
	else if (*input == STRZALKA_LEWO) kierunekRuchu = LEWO;
	else if (*input == STRZALKA_PRAWO) kierunekRuchu = PRAWO;
	else kierunekRuchu = BRAK;

	setKierunekRuchu(kierunekRuchu);
}

void Czlowiek::uruchomUmiejetnoscSpecjalna()
{
	Swiat& obecnySwiat = getSwiat();

	if (tarczaAlzuraAktywowana == false && obecnySwiat.getLicznikUmiejetnosciSpecjalnej() >= ODSTEP_UMIEJETNOSC_SPECJALNA)
	{
		tarczaAlzuraAktywowana = true;
		ileZostaloUmiejetnosciSpecjalnej = UMIEJETNOSC_SPECJALNA_CZAS_TRWANIA;
		obecnySwiat.setLicznikUmiejetnosciSpecjalnej(0);
	}
}

void Czlowiek::zmienLicznikiUmiejetnosciSpecjalnej()
{
	Swiat& obecnySwiat = getSwiat();

	if (tarczaAlzuraAktywowana == false) obecnySwiat.setLicznikUmiejetnosciSpecjalnej(obecnySwiat.getLicznikUmiejetnosciSpecjalnej() + 1);

	if (ileZostaloUmiejetnosciSpecjalnej > 0 && tarczaAlzuraAktywowana == true) ileZostaloUmiejetnosciSpecjalnej--;
	if (ileZostaloUmiejetnosciSpecjalnej == 0 && tarczaAlzuraAktywowana == true)
	{
		tarczaAlzuraAktywowana = false;
		obecnySwiat.setLicznikUmiejetnosciSpecjalnej(0);
	}
}

void Czlowiek::akcja()
{
	Swiat& obecnySwiat = getSwiat();
	
	int staraPozycjaX = getPolozenie()[0], staraPozycjaY = getPolozenie()[1];
	int nowaPozycjaX = staraPozycjaX;
	int nowaPozycjaY = staraPozycjaY;

	if (ostatniRuch == GORA) nowaPozycjaY--;
	else if (ostatniRuch == DOL) nowaPozycjaY++;
	else if (ostatniRuch == LEWO) nowaPozycjaX--;
	else if (ostatniRuch == PRAWO) nowaPozycjaX++;

	if (nowaPozycjaX >= 0 && nowaPozycjaX < obecnySwiat.getSzerokosc())
	{
		if (nowaPozycjaY >= 0 && nowaPozycjaY < obecnySwiat.getWysokosc())
		{
			setPoprzedniePolozenie(getPolozenie()[0], getPolozenie()[1]);
			obecnySwiat.getPolaNaPlanszy()[getPolozenie()[0]][getPolozenie()[1]] = nullptr;
			setPolozenie(nowaPozycjaX, nowaPozycjaY);
		}
	}
}

void Czlowiek::setKierunekRuchu(KierunekRuchuCzlowieka nowyKierunekRuchu)
{
	this->ostatniRuch = nowyKierunekRuchu;
}

Czlowiek::~Czlowiek()
{
}
