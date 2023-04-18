#include <conio.h>
#include <algorithm>

#include "Swiat.h"

#include "Antylopa.h"
#include "BarszczSosnowskiego.h"
#include "Guarana.h"
#include "Lis.h"
#include "Mlecz.h"
#include "Owca.h"
#include "Trawa.h"
#include "WilczeJagody.h"
#include "Wilk.h"
#include "Zolw.h"

#include "Czlowiek.h"

Swiat::Swiat() : szerokosc(20), wysokosc(20), numerTury(0), liczbaZdarzen(0)
{
}

Swiat::Swiat(int szerokosc, int wysokosc) : szerokosc(szerokosc), wysokosc(wysokosc), numerTury(0), liczbaZdarzen(0)
{
	for (int x = 0; x < szerokosc; x++)
	{
		polaNaPlanszy.push_back(std::vector<Organizm*>());
		for (int y = 0; y < wysokosc; y++) polaNaPlanszy[x].push_back(nullptr);
	}
}

int Swiat::getWysokosc()
{
	return wysokosc;
}

int Swiat::getSzerokosc()
{
	return szerokosc;
}

void Swiat::przebiegGry()
{
	int input = ' ';

	while (input != 'q')
	{
		input = _getch();
		handleInput(input);

		wykonajTure();

		system("CLS");
		rysujSwiat();
	}
}

void Swiat::wykonajTure()
{	
	posortujOrganizmy();
	for (int index = 0; index < organizmy.size(); index++)
	{
		organizmy[index]->postarzOrganizm();
		//std::cout << organizmy[index]->getReprezentacjaZnakowa() << std::endl;
		organizmy[index]->akcja();
		
	}
	numerTury++;
}

void Swiat::rysujSwiat()
{
	std::cout << "Programowanie obiektowe - projekt 1 - Anna Sztukowska 188803\n";
	std::cout << "tura: " << numerTury << std::endl;

	for (int x = 0; x < 2*szerokosc + 2; x++) std::cout << '-';
	std::cout << std::endl;

	for (int y = 0; y < wysokosc; y++)
	{
		std::cout << '|';
		for (int x = 0; x < szerokosc; x++)
		{
			std::cout << ' ';
			if (polaNaPlanszy[x][y] == NULL) std::cout << " ";
			else polaNaPlanszy[x][y]->rysowanie();
		}
		std::cout << '|';
		std::cout << std::endl;
	}

	for (int x = 0; x < 2 * szerokosc + 2; x++) std::cout << '-';
	std::cout << std::endl;

	for (int i = 0; i < zdarzenia.size(); i++) std::cout << zdarzenia[i];

	zdarzenia.erase(zdarzenia.begin(), zdarzenia.end());
}

void Swiat::handleInput(int input)
{
	if (input == INPUT_STRZALEK)
	{
		input = _getch();
		KierunekRuchuCzlowieka kierunekRuchu = BRAK;

		if (input == STRZALKA_GORA) kierunekRuchu = GORA;
		else if (input == STRZALKA_DOL) kierunekRuchu = DOL;
		else if (input == STRZALKA_LEWO) kierunekRuchu = LEWO;
		else if (input == STRZALKA_PRAWO) kierunekRuchu = PRAWO;

		for (int i = 0; i < organizmy.size(); i++)
		{
			if (dynamic_cast<Czlowiek*>(organizmy[i]))
			{
				Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(organizmy[i]);
				czlowiek->setKierunekRuchu(kierunekRuchu);
			}
		}
	}
}

void Swiat::dodajPoczatkoweOrganizmy()
{
	Antylopa* antylopa = new Antylopa(1, 1);
	dodajOrganizmDoStruktur(antylopa);
	BarszczSosnowskiego* barszczSosnowskiego = new BarszczSosnowskiego(2, 2);
	dodajOrganizmDoStruktur(barszczSosnowskiego);
	Guarana* guarana = new Guarana(3, 3);
	dodajOrganizmDoStruktur(guarana);
	Lis* lis = new Lis(4, 4);
	dodajOrganizmDoStruktur(lis);
	Mlecz* mlecz = new Mlecz(5, 5);
	dodajOrganizmDoStruktur(mlecz);
	Owca* owca = new Owca(6, 6);
	dodajOrganizmDoStruktur(owca);
	Trawa* trawa = new Trawa(7, 7);
	dodajOrganizmDoStruktur(trawa);
	WilczeJagody* wilczeJagody = new WilczeJagody(8, 8);
	dodajOrganizmDoStruktur(wilczeJagody);
	Wilk* wilk = new Wilk(9, 9);
	dodajOrganizmDoStruktur(wilk);
	Zolw* zolw = new Zolw(10, 10);
	dodajOrganizmDoStruktur(zolw);

	Czlowiek* czlowiek = new Czlowiek(0, 0);
	dodajOrganizmDoStruktur(czlowiek);
}

void Swiat::dodajOrganizmDoStruktur(Organizm* nowyOrganizm)
{
	nowyOrganizm->setSwiat(this);
	polaNaPlanszy[nowyOrganizm->getPolozenie()[0]][nowyOrganizm->getPolozenie()[1]] = nowyOrganizm;
	organizmy.push_back(nowyOrganizm);
}

void Swiat::usunOrganizm(Organizm* organizmDoUsuniecia)
{
	int pozycja = znajdzPozycjewWektorzeOrganizmow(organizmDoUsuniecia);
	int pozycjaNaPlanszyX = organizmDoUsuniecia->getPolozenie()[0];
	int pozycjaNaPlanszyY = organizmDoUsuniecia->getPolozenie()[1];
	
	if (pozycja >= 0 && pozycja < organizmy.size())
	{
		organizmy.erase(organizmy.begin() + pozycja);
		delete organizmDoUsuniecia;
		polaNaPlanszy[pozycjaNaPlanszyX][pozycjaNaPlanszyY] = nullptr;
	}

}

int Swiat::znajdzPozycjewWektorzeOrganizmow(Organizm* organizm)
{
	for (int i = 0; i < organizmy.size(); i++)
	{
		if (organizmy[i]->getPolozenie()[0] == organizm->getPolozenie()[0] && organizmy[i]->getPolozenie()[1] == organizm->getPolozenie()[1]) return i;
	}

	return -1;
}

bool Swiat::porownajDwaOrganizmy(const Organizm* pierwszyOrganizm, const Organizm* drugiOrganizm)
{
	return *pierwszyOrganizm < *drugiOrganizm;
}

void Swiat::posortujOrganizmy()
{
	std::sort(organizmy.begin(), organizmy.end(), porownajDwaOrganizmy);
}

void Swiat::przeniesOrganizm(Organizm* organizmDoPrzeniesienia, int staraPozycjaX, int staraPozycjaY, int nowaPozycjaX, int nowaPozycjaY)
{
	raportujRuch(organizmDoPrzeniesienia);
	organizmDoPrzeniesienia->setPolozenie(nowaPozycjaX, nowaPozycjaY);
	polaNaPlanszy[nowaPozycjaX][nowaPozycjaY] = organizmDoPrzeniesienia;
	polaNaPlanszy[staraPozycjaX][staraPozycjaY] = nullptr;
}


void Swiat::raportujRuch(Organizm* organizm)
{
	if (organizm != nullptr)
	{
		std::string noweZdarzenie = organizm->getNazwa() + " wykonal ruch.\n";
		zdarzenia.push_back(noweZdarzenie);
	}
}


std::vector<Organizm*> Swiat::getOrganizmy()
{
	return this->organizmy;
}

Swiat::~Swiat()
{
}
