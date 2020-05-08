#include <iostream>
#include "dinstring.hpp"
#include "list.hpp"
using namespace std;

class Karta
{
protected:
    DinString mestoPolaska;
    DinString mestoDolaska;
    float duzinaPutovanjaKM;
    float cenaKarte;
    int identifikatorKarte;
public:
    Karta(){}
    Karta(DinString mP, DinString mD, float dPkm, float cK, int iK)
    {
        mestoPolaska = mP;
        mestoDolaska = mD;
        duzinaPutovanjaKM = dPkm;
        cenaKarte = cK;
        identifikatorKarte = iK;
    }
    virtual bool jeftinaKarta() = 0;
    DinString getMestoPolaska() const { return mestoPolaska; }
    DinString getMestoDolaska() const { return mestoDolaska; }
    float getDuzinaPutovanjaKM() const { return duzinaPutovanjaKM; }
    float getCenaKarte() const { return cenaKarte; }
    int getIdentifikatorKarte() const { return identifikatorKarte; }
};

class AvionskaKarta : public Karta
{
public:
    bool jeftinaKarta()
    {
        if(cenaKarte / duzinaPutovanjaKM < 1)
            return true;
        return false;
    }
    void ispisi()
    {
        cout << "****KARTA****" << endl;
        cout << "Polazak iz: " << mestoPolaska << endl;
        cout << "Dolazak u: " << mestoDolaska << endl;
        cout << "Distanca: " << duzinaPutovanjaKM << endl;
        cout << "Cena: " << cenaKarte << endl;
        cout << "ID:" << identifikatorKarte << endl;
    }
};

class Putovanje
{
private:
    DinString nazivPutovanja;
    int maxCena;
    List<AvionskaKarta> karte;
public:
    Putovanje(){}
    Putovanje(DinString nP, int mC, List<AvionskaKarta> &k)
    {
        nazivPutovanja = nP;
        maxCena = mC;
        karte = k;
    }
    DinString getNazivPutovanja() const
    {
        return nazivPutovanja;
    }
    int getMaxCena() const
    {
        return maxCena;
    }
    bool dodajKartu(const AvionskaKarta &dodata)
    {
        int provera = 0;
        AvionskaKarta a;
        for(int i = 1; i <= karte.size(); ++i)
        {
            karte.read(i, a);
            if(a.getMestoDolaska() == dodata.getMestoDolaska() && a.getMestoPolaska() == dodata.getMestoPolaska() && dodata.getIdentifikatorKarte() != a.getIdentifikatorKarte())
                provera++;
        }
        if(provera == karte.size())
        {
            if(dodata.getCenaKarte() <= maxCena)
            {
                return karte.add(karte.size() + 1, dodata);
            }
            return false;
        }
        return false;
    }
    bool izbaciKartu(int ID)
    {
        AvionskaKarta a;
        for(int i = 1; i <= karte.size(); ++i)
        {
            karte.read(i, a);
            if(a.getIdentifikatorKarte() == ID)
            {
                karte.remove(i);
                return true;
            }
        }
        return false;
    }
    void ispisi()
    {
        cout << "****PUTOVANJE****" << endl;
        cout << "Naziv: " << nazivPutovanja << endl;
        cout << "Max. cena: " << maxCena << endl;
        cout << "Broj karata: " << karte.size() << endl;
        cout << "Jeftine karte: " << endl;
        AvionskaKarta a;
        for(int i = 1; i <= karte.size(); ++i)
        {
            karte.read(i, a);
            if(a.jeftinaKarta())
                a.ispisi();
        }
    }
};

int main()
{

}
