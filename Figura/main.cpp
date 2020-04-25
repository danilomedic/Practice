#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14

class Figura
{
protected:
    double a, b;
public:
    virtual double Obim() = 0;
    virtual double Povrsina() = 0;
};

class Pravougaonik : public Figura
{
public:
    Pravougaonik()
    {
        a = 1;
        b = 2;
    }
    Pravougaonik(double aa, double bb)
    {
        if(aa > 0 && bb > 0)
        {
            a = aa;
            b = bb;
        }
    }
    Pravougaonik(const Pravougaonik &p)
    {
        a = p.a;
        b = p.b;
    }
    double getA() const
    {
        return a;
    }
    double getB() const
    {
        return b;
    }
    double Obim()
    {
        return a + a + b + b;
    }
    double Povrsina()
    {
        return a * b;
    }
};

class Elipsa : public Figura
{
public:
    Elipsa()
    {
        a = 1;
        a = 2;
    }
    Elipsa(double aa, double bb)
    {
        a = aa;
        b = bb;
    }
    Elipsa(const Elipsa &e)
    {
        a = e.a;
        b = e.a;
    }
    double getA() const
    {
        return a;
    }
    double getB() const
    {
        return b;
    }
    double Obim()
    {
        return PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
    }
    double Povrsina()
    {
        return a * b * PI;
    }
};

class Kvadrat : public Pravougaonik
{
public:
    Kvadrat() : Pravougaonik(1, 1){}
    Kvadrat(double aa) : Pravougaonik (aa, aa){}
    Kvadrat(const Kvadrat &k) : Pravougaonik(k.a, k.b){}
};

class Krug : public Elipsa
{
public:
    Krug() : Elipsa(1, 1){}
    Krug(double r) : Elipsa(r, r){}
    Krug(const Krug &k) : Elipsa(k.a, k.b){}
};

class Oblik
{
private:
    Kvadrat A;
    Krug B;
public:
    Oblik()
    {
        A = Kvadrat();
        B = Krug();
    }
    Oblik(double a, double r)
    {
        A = Kvadrat(a);
        B = Krug(r);
    }
    Oblik(const Oblik &o)
    {
        A = Kvadrat(o.A);
        B = Krug(o.B);
    }
    double Obim()
    {
        return A.Obim() + B.Obim();
    }
    double Povrsina()
    {
        return A.Povrsina() - B.Povrsina();
    }
};

int main()
{

}
