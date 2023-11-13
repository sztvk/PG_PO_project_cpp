#include "Organizm.h"

Organizm::Organizm(Swiat& obecnySwiat, int sila, int inicjatywa, int pozycjaX, int pozycjaY, char reprezentacjaZnakowa)
	: obecnySwiat(obecnySwiat), sila(sila), inicjatywa(inicjatywa), reprezentacjaZnakowa(reprezentacjaZnakowa)
{
	this->polozenie[0] = pozycjaX;
	this->polozenie[1] = pozycjaY;

	this->poprzedniePolozenie[0] = pozycjaX;
	this->poprzedniePolozenie[0] = pozycjaY;

	this->wiek = 1;
}

Swiat& Organizm::getSwiat()
{
	return obecnySwiat;
}

void Organizm::setSwiat(Swiat& swiat)
{
	this->obecnySwiat = swiat;
}

void Organizm::setPolozenie(int nowaPozycjaX, int nowaPozycjaY)
{
	this->polozenie[0] = nowaPozycjaX;
	this->polozenie[1] = nowaPozycjaY;
}

void Organizm::setPoprzedniePolozenie(int pozycjaX, int pozycjaY)
{
	poprzedniePolozenie[0] = pozycjaX;
	poprzedniePolozenie[1] = pozycjaY;
}

void Organizm::setWiek(int wiek)
{
	this->wiek = wiek;
}

void Organizm::setSila(int sila)
{
	this->sila = sila;
}

char Organizm::getReprezentacjaZnakowa()
{
	return this->reprezentacjaZnakowa;
}

int* Organizm::getPolozenie()
{
	return polozenie;
}

int* Organizm::getPoprzedniePolozenie()
{
	return poprzedniePolozenie;
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

std::vector<std::pair<int,int>> Organizm::zwrocWolnePolaWokolOrganizmu()
{
	Swiat swiat = getSwiat();
	std::vector<std::pair<int,int>> wolnePola;
	bool znalezionoPolozenie = false;
	
	for (int zmianaX = -1; zmianaX <= 1; zmianaX++)
	{
		for (int zmianaY = -1; zmianaY <= 1; zmianaY++)
		{
			if (zmianaX == 0 && zmianaY == 0) continue;

			int pozycjaXDoSprawdzenia = polozenie[0] + zmianaX;
			int pozycjaYDoSprawdzenia = polozenie[1] + zmianaY;

			if (pozycjaXDoSprawdzenia >= 0 && pozycjaXDoSprawdzenia < swiat.getSzerokosc() && pozycjaYDoSprawdzenia >= 0 && pozycjaYDoSprawdzenia < swiat.getWysokosc())
			{
				int polozenieDoSprawdzenia[2] = { pozycjaXDoSprawdzenia, pozycjaYDoSprawdzenia };

				for (std::vector<Organizm*>::iterator it = swiat.getOrganizmy().begin(); it != swiat.getOrganizmy().end(); it++)
				{
					znalezionoPolozenie = swiat.porownajPolozenie((*it)->getPolozenie(), polozenieDoSprawdzenia);
					if (znalezionoPolozenie == true) break;
				}

				if (znalezionoPolozenie == false) wolnePola.push_back({ pozycjaXDoSprawdzenia, pozycjaYDoSprawdzenia });
			}
		}
	}

	return wolnePola;

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

void Organizm::walczZOrganizmem(Organizm* przeciwnik)
{
	if (getSila() >= przeciwnik->getSila())
	{
		if (przeciwnik->czyOdbilAtak(getSila()))
		{
			std::string noweZdarzenie = "Atak organizmu o gatunku: " + getNazwa() + " zostaje odbity przez zwierze gatunku: " + przeciwnik->getNazwa();
			getSwiat().getZdarzenia().push_back(noweZdarzenie);
			przeciwnik->setPolozenie(przeciwnik->getPolozenie()[0], przeciwnik->getPolozenie()[1]);
			this->setPolozenie(getPoprzedniePolozenie()[0], getPoprzedniePolozenie()[1]);
			return;
		}

		if (przeciwnik->czyUcieklPrzedWalka())
		{
			std::string noweZdarzenie = "Organizm gatunku: " + przeciwnik->getNazwa() + " uciekl przed walka z gatunkiem: " + getNazwa();
			getSwiat().getZdarzenia().push_back(noweZdarzenie);
			return;
		}

		if (przeciwnik->umiejetnoscSpecjalna(this))
		{
			std::string noweZdarzenie = przeciwnik->getNazwa() + " odstraszyl organizm gatunku: " + getNazwa();
			getSwiat().getZdarzenia().push_back(noweZdarzenie);
			return;
		}

		przeciwnik->setWiek(0);
		std::string noweZdarzenie = "Zwierze gatunku: " + getNazwa() + " zabilo zwierze gatunku: " + przeciwnik->getNazwa();
		getSwiat().getZdarzenia().push_back(noweZdarzenie);
	}
	else
	{
		setWiek(0);
	}
}

bool Organizm::czyOdbilAtak(int silaAtakujacego)
{
	return false;
}

bool Organizm::czyUcieklPrzedWalka()
{
	return false;
}

bool Organizm::umiejetnoscSpecjalna(Organizm* organizmDoOdstraszenia)
{
	return false;
}

bool Organizm::czyLosowyRuch()
{
	return true;
}

Organizm::~Organizm()
{
}
