#ifndef CARTE_H
#define CARTE_H

#include <iostream>
#include <string>
using namespace std;


class Carte
{
    private:
        string titlu, autor, gen;
        int anPublicare, pagini, exemplare;

    public:
        Carte() = delete;
        Carte(const string& titlu, const string& autor, int anPublicare, const string& gen, int pagini);
        Carte(const Carte& altaCarte);
        Carte(Carte&& altaCarte) noexcept;
        string getTitlu() const;
        void setTitlu(const string& titlu);
        void afiseazaInfoCarte() const;
        Carte& operator=(const Carte& altaCarte);
        ~Carte();
};

#endif

