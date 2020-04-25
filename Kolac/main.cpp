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
    void setPreliv(TipPreliva preliv)
    {
        tip = preliv;
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
        if(preliv.getPreliv() != COKOLADNI_SA_SLAGOM)
        {
            stanje = PECE_SE;
            temperatura++;
            return true;
        }
        return false;
    }
    bool ispeciKolac()
    {
        if(stanje == PECE_SE)
        {
            stanje = U_PRIPREMI;
            temperatura = 20;
            return true;
        }
        return false;
    }
    bool zavrsiKolac()
    {
        if(stanje == U_PRIPREMI)
        {
            stanje = PRIPREMLJEN;
            return true;
        }
        return false;
    }
    bool povecajTemperaturu()
    {
        if(stanje == PECE_SE && temperatura < 100)
        {
            temperatura++;
            return true;
        }
        stanje = ZAGOREO;
        return false;
    }
    bool smanjiTemperaturu()
    {
        if(stanje == PECE_SE && temperatura > 40)
        {
                temperatura--;
                return true;
        }
        return false;
    }
    bool dodajSlag()
    {
        if(stanje == U_PRIPREMI && preliv.getPreliv() == COKOLADNI)
        {
            preliv.setPreliv(COKOLADNI_SA_SLAGOM);
            return true;
        }
        return false;
    }
    bool ukloniSlag()
    {
        if(stanje == U_PRIPREMI && preliv.getPreliv() == COKOLADNI_SA_SLAGOM)
        {
            preliv.setPreliv(COKOLADNI);
            return true;
        }
        return false;
    }
};

int meni()
{
    int n = 0;
    do
    {
        cout << endl <<"*************************" << endl;
        cout <<"|1. Stavi da se pece"<< endl;
        cout <<"|2. Ispeci kolac"<< endl;
        cout <<"|3. Zavrsi kolac"<< endl;
        cout <<"|4. Povecaj temperaturu"<< endl;
        cout <<"|5. Smanji temperaturu"<< endl;
        cout <<"|6. Dodaj slag";
        cout <<"|7. Ukloni slag"<< endl;
        cout <<"|8. Ispisi preliv"<< endl;
        cout <<"|9. EXIT"<< endl;
        cout <<"> Izaberite opciju: ";
        fflush(stdin);
        cin >> n;
        if(n < 1 || n > 9)
            cout << "> ERROR: NEPOSTOJECA OPCIJA" << endl;
    }
    while(n > 9 || n < 1);
    return n;
}

int main()
{
    Kolac k;
    k = Kolac();
    int a;
    do
    {
        a = meni();
        switch(a)
        {
        case 1:
            if(k.staviDaSePece())
                cout << "Kolac se pece" << endl;
            else
                cout << "Kolac nije u potrebnom stanju" << endl;
            break;
        case 2:
            if(k.ispeciKolac())
                cout << "Ispecen kolac" << endl;
            else
                cout << "Kolac nije u potrebnom stanju" << endl;
            break;
        case 3:
            if(k.zavrsiKolac())
                cout <<"Kolac zavrsen" << endl;
            else
                cout << "Kolac nije u potrebnom stanju" << endl;
            break;
        case 4:
            if(k.povecajTemperaturu())
                cout << "Temp povecana" << endl;
            else
                cout << "Kolac nije u potrebnom stanju" << endl;
            break;
        case 5:
            if(k.smanjiTemperaturu())
                cout << "Temp smanjena" << endl;
            else
                cout << "Kolac nije u potrebnom stanju" << endl;
            break;
        case 6:
            if(k.dodajSlag())
                cout << "Slag dodat" << endl;
            else
                cout << "Kolac nije u potrebnom stanju" << endl;
            break;
        case 7:
            if(k.ukloniSlag())
                cout << "Slag uklonjen" << endl;
            else
                cout << "Kolac nije u potrebnom stanju" << endl;
            break;
        case 8:
            ispisiPreliv(Preliv());
            break;
        }
    }while(a != 9);
    return 0;
}
