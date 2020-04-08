#include <iostream>
using namespace std;

enum TipPreliva {COKOLADNI = 1, COKOLADNI_SA_SLAGOM};
enum KolacStanje {U_PRIPREMI = 1, PECE_SE, ZAGOREO, PRIPREMLJEN};

class Preliv
{
private:
    TipPreliva tip;
public:
    Preliv(TipPreliva t = COKOLADNI) {}
    bool dodajSlag()
    {
        if(tip == COKOLADNI)
        {
            tip = COKOLADNI_SA_SLAGOM;
            return true;
        }
        return false;
    }
    bool ukloniSlag()
    {
        if(tip == COKOLADNI_SA_SLAGOM)
        {
            tip = COKOLADNI;
            return true;
        }
        return false;
    }
    TipPreliva getPreliv()const
    {
        return tip;
    }
    void ispisiPreliv()
    {
        cout << "-------------------" << endl << "Preliv: ";
        switch(tip)
        {
        case COKOLADNI:
            cout << "COKOLADNI" << endl;
            break;
        case COKOLADNI_SA_SLAGOM:
            cout << "COKOLADNI_SA_PRELIVOM" << endl;
            break;
        }
        cout << "-------------------" << endl;
    }

};

void ispisiPreliv(const Preliv &t)
{
    cout << "-------------------" << endl << "Preliv: ";
    switch(t.getPreliv())
    {
    case COKOLADNI:
        cout << "COKOLADNI" << endl;
        break;
    case COKOLADNI_SA_SLAGOM:
        cout << "COKOLADNI_SA_PRELIVOM" << endl;
        break;
    }
    cout << "-------------------" << endl;
}

class Kolac
{
private:
    KolacStanje stanje;
    int temperatura;
    Preliv preliv;
public:
    Kolac() : preliv()
    {
        stanje = U_PRIPREMI;
        temperatura = 20;

    }
    Kolac(const Kolac &k) : preliv(k.preliv.getPreliv())
    {
        stanje = k.stanje;
        temperatura = k.temperatura;
    }
    bool staviDaSePece()
    {
        if(preliv.getPreliv() == COKOLADNI_SA_SLAGOM)
        {
            stanje = PECE_SE;
            return true;
        }
        return false;
    }
    bool ispeciKolac()
    {

    }
    bool zavrsiKolac(){}
    bool povecajTemperaturu(){}
    bool smanjiTemperaturu(){}
    bool dodajSlag(){}
    bool ukloniSlag(){}
};

int main()
{
    return 0;
}
