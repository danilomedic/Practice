#include <iostream>
#include "dinstring.hpp"
#include "list.hpp"
using namespace std;

class Igracka
{
protected:
    DinString naziv;
    DinString opsegGodina;
public:
    virtual void ispisi() const;
    DinString getNaziv() const
    {
        return naziv;
    }
    DinString getOG() const
    {
        return opsegGodina;
    }
};

enum Vrsta {Medo, Zeko, Kuca, Maca};
class PlisanaIgracka : public Igracka
{
private:
    Vrsta vrsta;
public:
    PlisanaIgracka()
    {
        naziv = "Hello Kitty";
        opsegGodina = "2 - 7";
        vrsta = Maca;
    }
    PlisanaIgracka(DinString n, DinString oG, Vrsta v)
    {
        naziv = n;
        opsegGodina = oG;
        vrsta = v;
    }
    void ispisi()
    {
        cout << "****PLISANA IGRACKA****" << endl;
        cout << "Naziv: " << naziv << endl;
        cout << "Opseg godina: " << opsegGodina << endl;
        switch(vrsta)
        {
            case 0: cout << "Vrsta: Medo" << endl;
            case 1: cout << "Vrsta: Zeko" << endl;
            case 2: cout << "Vrsta: Kuca" << endl;
            case 3: cout << "Vrsta: Maca" << endl;
        }
    }
};

class Autic : public Igracka
{
private:
    bool naStruju;
public:
    Autic(){}
    Autic(DinString n, DinString oG, bool nS)
    {
        naziv = n;
        opsegGodina = oG;
        naStruju = nS;
    }
    void ispisi()
    {
        cout << "****AUTIC****" << endl;
        cout << "Naziv: " << naziv << endl;
        cout << "Opseg godina: " << opsegGodina << endl;
        if(naStruju)
            cout << "Ide na struju" << endl;
        else
            cout << "Ne ide na struju" << endl;
    }
};

class Igraonica
{
private:
    List<Igracka> *igracke;
public:
    bool dodajIgracku(Igracka *i)
    {
        return igracke->add(igracke->size() + 1, *i);
    }
    bool baciIgracku(int pozicija)
    {
        return igracke->remove(pozicija);
    }
    bool nadjiIgracku(DinString ime)
    {
        Igracka ig;
        for(int i = 1; i <= igracke->size(); ++i)
        {
            igracke->read(i, ig);
            if(ime == ig.getNaziv())
                return true;
        }
        return false;
    }
    void ispisi() const
    {
        cout << "****IGRAONICA****" << endl;
        cout << "Broj igracaka: " << igracke->size() << endl;
        Igracka ig;
        for(int i = 1; i <= igracke->size(); ++i)
        {
            igracke->read(i, ig);
            cout << "Naziv: " << ig.getNaziv() << endl;
            cout << "Opseg godina: " << ig.getOG() << endl;
        }
    }
};

int main()
{

}
