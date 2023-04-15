// tu bylo iostream
#include "Swiat.h"

int main()
{
    std::srand(std::time(nullptr));
    std::cout << "Programowanie obiektowe - projekt 1 - Anna Sztukowska 188803\n";
    int wysokoscPlanszy, szerokoscPlanszy;
    std::cin >> wysokoscPlanszy >> szerokoscPlanszy;
    Swiat nowySwiat(szerokoscPlanszy, wysokoscPlanszy);

    nowySwiat.dodajPoczatkoweOrganizmy();
    nowySwiat.rysujSwiat();

    nowySwiat.przebiegGry();

    return 0;
}