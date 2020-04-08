#include <iostream>
using namespace std;

enum TipPreliva {COKOLADNI, COKOLADNI_SA_SLAGOM};
enum KolacStanje {U_PRIPREMI, PECE_SE, ZAGOREO, PRIPREMLJEN};

class Preliv
{
private:
    TipPreliva tip;
public:
    Preliv(TipPreliva t = COKOLADNI){}
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
    TipPreliva getPreliv(){return tip;}
    void ispisiPreliv(const Preliv &t)
    {
        cout << "-------------------" << endl << "Preliv: ";
        switch(t.tip)
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

class Kolac
{
private:
    KolacStanje stanje;
    int temperatura;
    Preliv preliv;
public:
    Kolac()
    {
        stanje = U_PRIPREMI;
        temperatura = 20;
        preliv = COKOLADNI;
    }
    Kolac(Kolac &k)
    {
        stanje = k.stanje;
        temperatura = k.temperatura;
        preliv = k.preliv;
    }
};

int main()
{
    return 0;
}
