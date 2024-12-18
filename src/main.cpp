#include "Carte.h"

int main()
{

    Carte test("Titlu Test", "Autor Test", 2021, "Gen Test", 100);
    Carte *carte1 = new Carte("The Great Gatsby", "F. Scott Fitzgerald", 1925, "Novel", 180);
    Carte *carte2 = new Carte("1984", "George Orwell", 1949, "Dystopian", 328);

    //Afisare informatii initiale
    carte1->afiseazaInfoCarte();
    carte2->afiseazaInfoCarte();

    //Modificare titlu
    carte1->setTitlu("The Great Gatsby: Revised Edition");

    //Copiere
    *carte2 = *carte1;
    carte1->afiseazaInfoCarte();
    carte2->afiseazaInfoCarte();

    //Test copy constructor
    Carte carte3 = *carte1;
    carte3.afiseazaInfoCarte();

    //Test move constructor
    Carte carte4 = std::move(*carte1);
    carte4.afiseazaInfoCarte();

    //Verificam stare carte1 (mutat)
    carte1->afiseazaInfoCarte();

    delete carte1;
    delete carte2;

    return 0;
}

