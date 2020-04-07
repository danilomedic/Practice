#include <iostream>
using namespace std;

enum TipMenjaca {AUTOMATIK, MANUAL};
enum BojaSkoljke {CRVENA, PLAVA, ZELENA};
enum AutoStanje {UGASEN, POKVAREN, U_VOZNJI};

class Menjac
{
private:
    TipMenjaca t;
    int brBrzina;
public:
    Menjac(){t = MANUAL; brBrzina = 3;}
    Menjac(TipMenjaca tt, int b){t = tt; brBrzina = b;}
    Menjac(Menjac &m){t = m.t; brBrzina = m.brBrzina;}
    TipMenjaca getTip(){return t;}
    int getBrzina(){return brBrzina;}
    void setTip(TipMenjaca tt){t = tt;}
    void setBrzina(int b){brBrzina = b;}
};

class Skoljka
{
private:
    BojaSkoljke b;
public:
    Skoljka(){b = PLAVA;}
    Skoljka(BojaSkoljke bb){b = bb;}
    Skoljka(Skoljka &s){b = s.b;}
    BojaSkoljke getBoja(){return b;}
    void setBoja(BojaSkoljke bb){b = bb;}
};

class Automobil
{
private:
    Menjac m;
    Skoljka s;
    AutoStanje a;
    int trenBrzina;
public:
    Automobil() : m(), s() {a = UGASEN; trenBrzina = 0;}
    Automobil(Menjac mm, Skoljka ss, AutoStanje aa, int b)
    {
        m = mm;
        s = ss;
        a = aa;
        trenBrzina = b;
    }
    Autombil(Automobil &aa)
    {
        m = aa.m;
        s = aa.s;
        a = aa.a;
        trenBrzina = aa.trenBrzina;
    }
    bool upali()
    {
        if(a == UGASEN){a = U_VOZNJI; cout << "Auto upaljen" << endl;}
        if(a == POKVAREN){cout << "Auto je pokvaren, ne moze da se upali" << endl;}
        return true;
    }
    bool ugasi()
    {
        if(a == U_VOZNJI){a = UGASEN; cout << "Auto ugasen" << endl;}
        if(a == POKVAREN){cout << "Auto ugasen usled kvara" << endl;}
        return true;
    }
    bool pokvari()
    {
        if(a != POKVAREN){a = POKVAREN; cout << "Uspesan kvar" << endl;}
        return true;
    }
    bool popravi()
    {
        if(a == POKVAREN){a = UGASEN; cout << "Uspesna popravka" << endl;}
        return true;
    }
    bool povecajBrzinu()
    {
        if(a != U_VOZNJI || trenBrzina == m.getBrzina()){return false;}
        trenBrzina++;
        return true;
    }
    bool smanjiBrzinu()
    {
        if(a != U_VOZNJI || trenBrzina == 0){return false;}
        trenBrzina--;
        return true;
    }
};

int main()
{
    return 0;
}
