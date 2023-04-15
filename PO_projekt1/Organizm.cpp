#include "Organizm.h"

Organizm::Organizm() : obecnySwiat(nullptr), sila(0), inicjatywa(0), reprezentacjaZnakowa('*')
{
	this->polozenie[0] = 0;
	this->polozenie[1] = 0;
	this->wiek = 0;
}

Organizm::Organizm(int sila, int inicjatywa, int pozycjaX, int pozycjaY, char reprezentacjaZnakowa)
	: sila(sila), inicjatywa(inicjatywa), reprezentacjaZnakowa(reprezentacjaZnakowa)
{
	this->polozenie[0] = pozycjaX;
	this->polozenie[1] = pozycjaY;
	this->wiek = 0;
}

Swiat* Organizm::getSwiat()
{
	return obecnySwiat;
}

void Organizm::setSwiat(Swiat* swiat)
{
	this->obecnySwiat = swiat;
}

void Organizm::setPolozenie(int nowaPozycjaX, int nowaPozycjaY)
{
	this->polozenie[0] = nowaPozycjaX;
	this->polozenie[1] = nowaPozycjaY;
}

char Organizm::getReprezentacjaZnakowa()
{
	return this->reprezentacjaZnakowa;
}

int* Organizm::getPolozenie()
{
	return polozenie;
}

int Organizm::getWiek()
{
	return this->wiek;
}

int Organizm::getSila()
{
	return this->sila;
}

void Organizm::postarzOrganizm()
{
	this->wiek++;
}

bool Organizm::operator<(const Organizm& drugiOrganizm) const
{
	if (inicjatywa == drugiOrganizm.inicjatywa)
	{
		return wiek > drugiOrganizm.wiek;
	}
	else
	{
		return inicjatywa > drugiOrganizm.inicjatywa;
	}
}

void Organizm::rysowanie()
{
	std::cout << getReprezentacjaZnakowa();
}

Organizm::~Organizm()
{
}
