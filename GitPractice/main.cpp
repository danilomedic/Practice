#include <iostream>
#include <math.h>

/// Napisati klasu koja predstavlja Jednakokraki torugao.
/// Klasa treba da sadrzi prazan konstruktor, konstruktor sa parametrima,
/// sve get i set metode kao i metodu za dobijanje obima i povrsine.
/// Sve metode i konstruktore je potrebno pozvati u mainu.
/// Stranica ( double ili float, odraditi i provere za stranice )

using namespace std;

class JednakokrakiTrougao
{
private:
    float a = 3;
    float b = 4;
    float c = 5;
public:
    JednakokrakiTrougao(){}
    JednakokrakiTrougao(float aa, float bb, float cc)
    {
        a = aa; b = bb; c = cc;
    }
    void setA(float aa)
    {
        a = aa;
    }
    void setB(float bb)
    {
        b = bb;
    }
    void setC(float cc)
    {
        c = cc;
    }
    float getA()
    {
        return a;
    }
    float getB()
    {
        return b;
    }
    float getC()
    {
        return c;
    }
    float returnObim()
    {
        return a + b + c;
    }
    float returnPovrsina()
    {
        float x = (a + b + c) * 0.5;
        return sqrt(x * (x - a) * (x - b) * (x - c));
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
