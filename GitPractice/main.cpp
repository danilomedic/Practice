#include <iostream>

/// Napisati klasu koja predstavlja Jednakokraki torugao.
/// Klasa treba da sadrzi prazan konstruktor, konstruktor sa parametrima,
/// sve get i set metode kao i metodu za dobijanje obima i povrsine.
/// Sve metode i konstruktore je potrebno pozvati u mainu.
/// Stranica ( double ili float, odraditi i provere za stranice )

using namespace std;

class JednakokrakiTrougao
{
private:
    int a;
    int b;
    int c;
public:
    JednakokrakiTrougao(){}
    JednakokrakiTrougao(int aa, int bb, int cc)
    {
        a = aa; b = bb; c = cc;
    }
    void setA(int aa)
    {
        a = aa;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
