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

using namespace std;

Swiat::Swiat() : szerokosc(20), wysokosc(20), numerTury(0), liczbaZdarzen(0), licznikUmiejetnosciSpecjalnejWTurach(0)
{
}

Swiat::Swiat(int szerokosc, int wysokosc) : szerokosc(szerokosc), wysokosc(wysokosc), numerTury(0), liczbaZdarzen(0)
{
	for (int x = 0; x < szerokosc; x++)
	{
		polaNaPlanszy.push_back(std::vector<Organizm*>());
		for (int y = 0; y < wysokosc; y++) polaNaPlanszy[x].push_back(nullptr);
	}

	licznikUmiejetnosciSpecjalnejWTurach = 0;
}

int Swiat::getWysokosc() const
{
	return wysokosc;
}

int Swiat::getSzerokosc() const
{
	return szerokosc;
}

int Swiat::getLicznikUmiejetnosciSpecjalnej() const
{
	return licznikUmiejetnosciSpecjalnejWTurach;
}

std::vector<Organizm*>& Swiat::getOrganizmy()
{
	return organizmy;
}

std::vector<std::string>& Swiat::getZdarzenia()
{
	return zdarzenia;
}

std::vector<std::vector<Organizm*>> Swiat::getPolaNaPlanszy() const
{
	return polaNaPlanszy;
}

void Swiat::setLicznikUmiejetnosciSpecjalnej(int aktualnyLicznikUmiejetnosciSpecjalnej)
{
	this->licznikUmiejetnosciSpecjalnejWTurach = aktualnyLicznikUmiejetnosciSpecjalnej;
}


void Swiat::wybierzTryb()
{
	int input = _getch();

	if (input == 'w') // wczytanie stanu gry z pliku
	{
		std::string nazwaPliku;
		cout << "nazwa pliku: ";
		cin >> nazwaPliku;
		wczytajStanSwiataZPliku(nazwaPliku);
		uaktualnijPlansze();
		rysujSwiat();
	}
	else // przykladowy zestaw startowy organizmow
	{
		dodajPoczatkoweOrganizmy();
		rysujSwiat();
	}
}

void Swiat::przebiegGry()
{
	int input = ' ';
	wybierzTryb();

	while (input != 'q')
	{
		input = _getch();
		obsluzInput(input);

		wykonajTure();
		uaktualnijPlansze();

		system("CLS");
		rysujSwiat();

		numerTury++;
	}
}

void Swiat::wykonajTure()
{	
	posortujOrganizmy();

	for (int index = 0; index < organizmy.size(); index++)
	{
		if (organizmy[index] != nullptr)
		{
			organizmy[index]->akcja();
			if (index < organizmy.size()) sprawdzKolizje(organizmy[index]);
		}
	}

	obsluzLicznikUmiejetnosciSpecjalnejGracza();
	postarzOrganizmy();
	
}

void Swiat::rysujSwiat()
{
	std::cout << "Programowanie obiektowe - projekt 1 - Anna Sztukowska 188803\n";
	std::cout << "tura: " << numerTury << std::endl;

	if (licznikUmiejetnosciSpecjalnejWTurach >= ODSTEP_UMIEJETNOSC_SPECJALNA) std::cout << "mozna uzyc umiejetnosci specjalnej czlowieka!" << std::endl;

	for (int x = 0; x < 2*szerokosc + 2; x++) std::cout << '-';
	std::cout << std::endl;

	for (int y = 0; y < wysokosc; y++)
	{
		std::cout << '|';
		for (int x = 0; x < szerokosc; x++)
		{
			std::cout << ' ';
			if (dynamic_cast<Organizm*>(polaNaPlanszy[x][y])) polaNaPlanszy[x][y]->rysowanie();
			else std::cout << " ";

		}
		std::cout << '|';
		std::cout << std::endl;
	}

	for (int x = 0; x < 2 * szerokosc + 2; x++) std::cout << '-';
	std::cout << std::endl;

	for (int i = 0; i < zdarzenia.size(); i++) std::cout << zdarzenia[i]<<std::endl;

	zdarzenia.erase(zdarzenia.begin(), zdarzenia.end());
}

void Swiat::uaktualnijPlansze()
{
	for (int i = 0; i < wysokosc; i++)
	{
		for (int j = 0; j < szerokosc; j++)
		{
			polaNaPlanszy[i][j] = nullptr;
		}
	}
	
	for (int i = 0; i < organizmy.size(); i++)
	{
		polaNaPlanszy[organizmy[i]->getPolozenie()[0]][organizmy[i]->getPolozenie()[1]] = organizmy[i];
	}
}


void Swiat::obsluzInput(int input)
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
				return;
			}
		}
	}
	else if (input == 'u')
	{
		for (int i = 0; i < organizmy.size(); i++)
		{
			Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(organizmy[i]);
			if (organizmy[i]->czyLosowyRuch() == false)
			{
				czlowiek->uruchomUmiejetnoscSpecjalna();
				czlowiek->setKierunekRuchu(BRAK);
			}
			return;
		}
	}
	else if (input == 'z')
	{
		std::string nazwa;
		std::cout << "Podaj nazwe pliku pod jaka zapisac: ";
		std::cin >> nazwa;

		zapiszStanSwiata(nazwa);
	}
}

void Swiat::dodajPoczatkoweOrganizmy()
{
	Czlowiek* czlowiek = new Czlowiek(*this, 5, 5);
	dodajOrganizmDoStruktur(czlowiek);

	Antylopa* antylopa = new Antylopa(*this, 1, 1);
	dodajOrganizmDoStruktur(antylopa);
	BarszczSosnowskiego* barszczSosnowskiego = new BarszczSosnowskiego(*this, 2, 2);
	dodajOrganizmDoStruktur(barszczSosnowskiego);
	Guarana* guarana = new Guarana(*this, 3, 3);
	dodajOrganizmDoStruktur(guarana);
	Lis* lis = new Lis(*this, 4, 4);
	dodajOrganizmDoStruktur(lis);
	Owca* owca2 = new Owca(*this, 4, 5);
	dodajOrganizmDoStruktur(owca2);
	Owca* owca3 = new Owca(*this, 4, 3);
	dodajOrganizmDoStruktur(owca3);
	Mlecz* mlecz = new Mlecz(*this, 12, 14);
	dodajOrganizmDoStruktur(mlecz);
	Owca* owca = new Owca(*this, 6, 6);
	dodajOrganizmDoStruktur(owca);
	Trawa* trawa = new Trawa(*this, 7, 7);
	dodajOrganizmDoStruktur(trawa);
	WilczeJagody* wilczeJagody = new WilczeJagody(*this, 8, 8);
	dodajOrganizmDoStruktur(wilczeJagody);
	Wilk* wilk = new Wilk(*this, 7, 6);
	dodajOrganizmDoStruktur(wilk);
	Zolw* zolw = new Zolw(*this, 5, 3);
	dodajOrganizmDoStruktur(zolw);

	Zolw* zolw2 = new Zolw(*this, 1, 4);
	dodajOrganizmDoStruktur(zolw2);
	Zolw* zolw3 = new Zolw(*this, 6, 4);
	dodajOrganizmDoStruktur(zolw3);
	Zolw* zolw4 = new Zolw(*this, 5, 7);
	dodajOrganizmDoStruktur(zolw4);
	Zolw* zolw5 = new Zolw(*this, 2, 3);
	dodajOrganizmDoStruktur(zolw5);
	Zolw* zolw6 = new Zolw(*this, 4, 1);
	dodajOrganizmDoStruktur(zolw6);
	Zolw* zolw7 = new Zolw(*this, 1, 8);
	dodajOrganizmDoStruktur(zolw7);

	/*Wilk* wilk1 = new Wilk(*this, 2, 4);
	dodajOrganizmDoStruktur(wilk1);
	Wilk* wilk2 = new Wilk(*this, 5, 3);
	dodajOrganizmDoStruktur(wilk2);
	Wilk* wilk3 = new Wilk(*this, 4, 2);
	dodajOrganizmDoStruktur(wilk3);
	Wilk* wilk4 = new Wilk(*this, 5, 6);
	dodajOrganizmDoStruktur(wilk4);
	Wilk* wilk5 = new Wilk(*this, 7, 6);
	dodajOrganizmDoStruktur(wilk5);*/
}

void Swiat::dodajOrganizmDoStruktur(Organizm* nowyOrganizm)
{
	nowyOrganizm->setSwiat(*this);
	polaNaPlanszy[nowyOrganizm->getPolozenie()[0]][nowyOrganizm->getPolozenie()[1]] = nowyOrganizm;
	organizmy.push_back(nowyOrganizm);
}

void Swiat::usunOrganizm(Organizm* organizmDoUsuniecia)
{
	int pozycja = znajdzPozycjewWektorzeOrganizmow(organizmDoUsuniecia);
	
	if (pozycja >= 0 && pozycja < organizmy.size())
	{
		if (organizmDoUsuniecia->getWiek() == 0)
		{
			delete organizmy[pozycja];
			organizmy.erase(organizmy.begin() + pozycja);
		}
	}
}

int Swiat::znajdzPozycjewWektorzeOrganizmow(Organizm* organizm)
{
	for (int i = 0; i < organizmy.size(); i++)
	{
		if (organizmy[i] == organizm) return i;
	}

	return -1;
}

void Swiat::postarzOrganizmy()
{
	for (int i = 0; i < organizmy.size(); i++)
	{
		organizmy[i]->postarzOrganizm();
	}
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
	organizmDoPrzeniesienia->setPoprzedniePolozenie(staraPozycjaX, staraPozycjaY);
	organizmDoPrzeniesienia->setPolozenie(nowaPozycjaX, nowaPozycjaY);
	polaNaPlanszy[nowaPozycjaX][nowaPozycjaY] = organizmDoPrzeniesienia;
	polaNaPlanszy[staraPozycjaX][staraPozycjaY] = nullptr;
}


bool Swiat::sprawdzCzyKolizjaDlaDwochOrganizmow(Organizm* organizm1, Organizm* organizm2)
{
	if (porownajPolozenie(organizm1->getPolozenie(), organizm2->getPolozenie()))
	{
		wywolajKolizje(organizm1, organizm2);
		usunOrganizm(organizm1);
		usunOrganizm(organizm2);

		return true;
	}
	else return false;
}

void Swiat::wywolajKolizje(Organizm* organizm1, Organizm* organizm2)
{
	organizm1->kolizja(organizm2);
	organizm2->kolizja(organizm1);
}

void Swiat::sprawdzKolizje(Organizm* sprawdzanyOrganizm)
{
	for (int i = 0; i < organizmy.size(); i++)
	{
		if (sprawdzanyOrganizm == organizmy[i]) continue;
		if (sprawdzCzyKolizjaDlaDwochOrganizmow(sprawdzanyOrganizm, organizmy[i])) break;
	}
}

bool Swiat::porownajPolozenie(int* polozenie1, int* polozenie2)
{
	if (polozenie1[0] == polozenie2[0] && polozenie1[1] == polozenie2[1]) return true;
	else return false;
}


void Swiat::obsluzLicznikUmiejetnosciSpecjalnejGracza()
{
	for (int i = 0; i < organizmy.size(); i++)
	{
		if (dynamic_cast<Czlowiek*>(organizmy[i]))
		{
			Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(organizmy[i]);
			czlowiek->zmienLicznikiUmiejetnosciSpecjalnej();
			return;
		}
	}
}


void Swiat::zapiszStanSwiata(std::string nazwaPliku)
{
	ofstream strumienDoPliku(nazwaPliku + ".txt");

	// zmienne ogolne
	for (int i = 0; i < organizmy.size(); i++)
	{
		if (dynamic_cast<Czlowiek*>(organizmy[i]))
		{
			Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(organizmy[i]);
			int ileUmiejetnosci = czlowiek->getIleZostaloUmiejetnosciSpecjalnej();
			strumienDoPliku << licznikUmiejetnosciSpecjalnejWTurach << endl;
			strumienDoPliku << ileUmiejetnosci << endl;
			break;
		}
	}
	strumienDoPliku << numerTury << endl;

	// organizmy
	for (int i = 0; i < organizmy.size(); i++)
	{
		strumienDoPliku << organizmy[i]->getReprezentacjaZnakowa() << ";" << organizmy[i]->getPolozenie()[0]
			<< ";" << organizmy[i]->getPolozenie()[1] << ";" << organizmy[i]->getPoprzedniePolozenie()[0]
			<< ";" << organizmy[i]->getPoprzedniePolozenie()[0] << ";" << organizmy[i]->getSila() << ";"
			<< organizmy[i]->getWiek() << ";" << endl;
	}

	strumienDoPliku.close();
}

void Swiat::wczytajStanSwiataZPliku(std::string nazwaPliku)
{
	ifstream strumienDoPliku(nazwaPliku + ".txt");
	std::string napisy;
	int ileUmiejetnosci;

	if (strumienDoPliku.is_open())
	{
		char wiersz[10000];

		// zmienne ogolne
		std::getline(strumienDoPliku, napisy);
		licznikUmiejetnosciSpecjalnejWTurach = std::stoi(napisy);

		std::getline(strumienDoPliku, napisy);
		ileUmiejetnosci = std::stoi(napisy);

		std::getline(strumienDoPliku, napisy);
		numerTury = std::stoi(napisy);

		// organizmy
		while (strumienDoPliku.getline(wiersz, 10000))
		{
			dodajOrganizmNaPodstawiePliku(wiersz);
		}

		// zapisanie do odpowiednich zmiennych wczesniej zczytanych danych ogolnych
		for (int i = 0; i < organizmy.size(); i++)
		{
			if (dynamic_cast<Czlowiek*>(organizmy[i]))
			{
				Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(organizmy[i]);
				czlowiek->setIleZostaloUmiejetnosciSpecjalnej(ileUmiejetnosci);
				break;
			}
		}
	}
	else cout << "Nie uda³o siê otworzyæ pliku";

	strumienDoPliku.close();
}

void Swiat::dodajOrganizmNaPodstawiePliku(std::string wiersz)
{
	char reprezentacjaZnakowa;
	int polozenie[2];
	int poprzedniePolozenie[2];
	int sila;
	int czasZycia;

	int separatorIndex = 1;
	int separatorIndexNastepny = wiersz.find(';', separatorIndex + 1);

	reprezentacjaZnakowa = wiersz.substr(0, 1)[0];
	polozenie[0] = stoi(odczytajKolejnyElementWiersza(separatorIndex, separatorIndexNastepny, wiersz));
	polozenie[1] = stoi(odczytajKolejnyElementWiersza(separatorIndex, separatorIndexNastepny, wiersz));
	poprzedniePolozenie[0] = stoi(odczytajKolejnyElementWiersza(separatorIndex, separatorIndexNastepny, wiersz));
	poprzedniePolozenie[1] = stoi(odczytajKolejnyElementWiersza(separatorIndex, separatorIndexNastepny, wiersz));
	sila = stoi(odczytajKolejnyElementWiersza(separatorIndex, separatorIndexNastepny, wiersz));
	czasZycia = stoi(odczytajKolejnyElementWiersza(separatorIndex, separatorIndexNastepny, wiersz));

	Organizm* organizm{};
	if (reprezentacjaZnakowa == 't') organizm = new Trawa(*this, polozenie[0], polozenie[1]);
	else if (reprezentacjaZnakowa == 'm') organizm = new Mlecz(*this, polozenie[0], polozenie[1]);
	else if (reprezentacjaZnakowa == 'g') organizm = new Guarana(*this, polozenie[0], polozenie[1]);
	else if (reprezentacjaZnakowa == 'j') organizm = new WilczeJagody(*this, polozenie[0], polozenie[1]);
	else if (reprezentacjaZnakowa == 'b') organizm = new BarszczSosnowskiego(*this, polozenie[0], polozenie[1]);
	else if (reprezentacjaZnakowa == 'W') organizm = new Wilk(*this, polozenie[0], polozenie[1]);
	else if (reprezentacjaZnakowa == 'O') organizm = new Owca(*this, polozenie[0], polozenie[1]);
	else if (reprezentacjaZnakowa == 'L') organizm = new Lis(*this, polozenie[0], polozenie[1]);
	else if (reprezentacjaZnakowa == 'Z') organizm = new Zolw(*this, polozenie[0], polozenie[1]);
	else if (reprezentacjaZnakowa == 'A') organizm = new Antylopa(*this, polozenie[0], polozenie[1]);
	else if (reprezentacjaZnakowa == 'C') organizm = new Czlowiek(*this, polozenie[0], polozenie[1]);

	organizm->setSila(sila);
	organizm->setWiek(czasZycia);
	organizm->setPoprzedniePolozenie(poprzedniePolozenie[0], poprzedniePolozenie[1]);

	organizmy.push_back(organizm);
}

std::string Swiat::odczytajKolejnyElementWiersza(int& separatorIndex, int& separatorIndexNastepny, std::string wiersz)
{
	std::string tmp = wiersz.substr(separatorIndex + 1, separatorIndexNastepny - separatorIndex - 1);
	separatorIndex = separatorIndexNastepny;
	separatorIndexNastepny = wiersz.find(';', separatorIndex + 1);
	return tmp;
}

void Swiat::wyczyscSwiat()
{
	for (int i = 0; i < organizmy.size(); i++)
	{
		delete organizmy[i];
	}
}


Swiat::~Swiat()
{
}
