#include "Carte.h"

Carte::Carte(const string& titlu, const string& autor, int anPublicare, const string& gen, int pagini)
    : titlu(titlu), autor(autor), anPublicare(anPublicare), gen(gen), pagini(pagini), exemplare(1)
{
    descriere = std::make_unique<std::string>("Descriere necompletata");
    cout << "Constructor apelat pentru cartea: " << titlu << endl;
}

Carte::Carte(const Carte& altaCarte)
    : titlu(altaCarte.titlu),
      autor(altaCarte.autor),
      anPublicare(altaCarte.anPublicare),
      gen(altaCarte.gen),
      pagini(altaCarte.pagini),
      exemplare(altaCarte.exemplare)
{
    if (altaCarte.descriere) {
        descriere = std::make_unique<std::string>(*altaCarte.descriere);
    }
    cout << "Copy constructor apelat pentru cartea: " << titlu << endl;
}


Carte::Carte(Carte&& altaCarte) noexcept
    : titlu(std::move(altaCarte.titlu)),
      autor(std::move(altaCarte.autor)),
      anPublicare(altaCarte.anPublicare),
      gen(std::move(altaCarte.gen)),
      pagini(altaCarte.pagini),
      exemplare(altaCarte.exemplare),
      descriere(std::move(altaCarte.descriere)) 
{
    cout << "Move constructor apelat pentru cartea: " << titlu << endl;
    altaCarte.anPublicare = 0;
    altaCarte.pagini = 0;
    altaCarte.exemplare = 0;
}


Carte& Carte::operator=(const Carte& altaCarte)
{
    if (this == &altaCarte)
        return *this;

    titlu = altaCarte.titlu;
    autor = altaCarte.autor;
    anPublicare = altaCarte.anPublicare;
    gen = altaCarte.gen;
    pagini = altaCarte.pagini;
    exemplare = altaCarte.exemplare;

    if (altaCarte.descriere) 
    {
        descriere = std::make_unique<std::string>(*altaCarte.descriere);
    } 
    else 
    {
        descriere.reset();
    }

    cout << "Copy assignment operator apelat pentru cartea: " << titlu << endl;
    return *this; 
}


Carte& Carte::operator=(Carte&& altaCarte) noexcept
{
    if (this == &altaCarte)
        return *this;

    titlu = std::move(altaCarte.titlu);
    autor = std::move(altaCarte.autor);
    anPublicare = altaCarte.anPublicare;
    gen = std::move(altaCarte.gen);
    pagini = altaCarte.pagini;
    exemplare = altaCarte.exemplare;
    descriere = std::move(altaCarte.descriere);

    altaCarte.anPublicare = 0;
    altaCarte.pagini = 0;
    altaCarte.exemplare = 0;

    cout << "Move assignment operator apelat pentru cartea: " << titlu << endl;
    return *this;
}

string Carte::getTitlu() const { return titlu; }

void Carte::setTitlu(const string& titlu)
{
    this->titlu = titlu;
    cout << "Titlul a fost modificat!" << endl;
}

void Carte::afiseazaInfoCarte() const
{
    cout << "\nTitlu: " << titlu 
         << "\nAutor: " << autor 
         << "\nAn Publicare: " << anPublicare 
         << "\nGen: " << gen
         << "\nPagini: " << pagini 
         << "\nExemplare: " << exemplare 
         << "\nDescriere: " << (descriere ? *descriere : "N/A") 
         << endl;
}

Carte::~Carte()
{
    cout << "Destructor apelat pentru cartea: " << titlu << endl;
}

