#include "Carte.h"

Carte::Carte(const string& titlu, const string& autor, int anPublicare, const string& gen, int pagini)
    : titlu(titlu), autor(autor), anPublicare(anPublicare), gen(gen), pagini(pagini), exemplare(1) {
    cout << "Constructor apelat pentru cartea: " << titlu << endl;
}

Carte::Carte(const Carte& altaCarte)
    : titlu(altaCarte.titlu), autor(altaCarte.autor), anPublicare(altaCarte.anPublicare),
      gen(altaCarte.gen), pagini(altaCarte.pagini), exemplare(altaCarte.exemplare) {
    cout << "Copy constructor apelat pentru cartea: " << titlu << endl;
}

Carte::Carte(Carte&& altaCarte) noexcept
    : titlu(move(altaCarte.titlu)), autor(move(altaCarte.autor)), anPublicare(altaCarte.anPublicare),
      gen(move(altaCarte.gen)), pagini(altaCarte.pagini), exemplare(altaCarte.exemplare) {
    cout << "Move constructor apelat pentru cartea: " << titlu << endl;
}

string Carte::getTitlu() const { return titlu; }

void Carte::setTitlu(const string& titlu)
{
    this->titlu = titlu;
    cout << "Titlul a fost modificat!" << endl;
}

void Carte::afiseazaInfoCarte() const
{
    cout << "\nTitlu: " << titlu << "\nAutor: " << autor << "\nAn Publicare: " << anPublicare << "\nGen: " << gen
    << "\nPagini: " << pagini << "\nExemplare: " << exemplare << endl;
}

Carte& Carte::operator=(const Carte& altaCarte)
{
    titlu = altaCarte.titlu;
    autor = altaCarte.autor;
    anPublicare = altaCarte.anPublicare;
    gen = altaCarte.gen;
    pagini = altaCarte.pagini;
    exemplare = altaCarte.exemplare;
    return *this;
}

Carte::~Carte()
{
    cout << "Destructor apelat pentru cartea: " << titlu << endl;
}

