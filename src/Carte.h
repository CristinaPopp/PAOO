#ifndef CARTE_H
#define CARTE_H

#include <iostream>
#include <string>
#include <memory> 

using namespace std;

class Carte
{
private:
    string titlu, autor, gen;
    int anPublicare, pagini, exemplare;
    std::unique_ptr<std::string> descriere; 

public:
    Carte() = delete;
    Carte(const string& titlu, const string& autor, int anPublicare, const string& gen, int pagini);
    Carte(const Carte& altaCarte);
    Carte(Carte&& altaCarte) noexcept;
    Carte& operator=(const Carte& altaCarte);
    Carte& operator=(Carte&& altaCarte) noexcept;
    ~Carte();
    string getTitlu() const;
    void setTitlu(const string& titlu);
    void afiseazaInfoCarte() const;
};

#endif 

