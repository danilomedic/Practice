#include <iostream>
#include <math.h>

using namespace std;

class XnaY
{
private:
    int x;
    int y;
public:
    XnaY()
    {
        x = 1;
        y = 1;
    }
    XnaY(int xx, int yy)
    {
        x = xx;
        y = yy;
    }
    /// konstruktor kopije fali
    void setX(int xx)
    {
        x = xx;
    }
    void setY(int yy)
    {
        y = yy;
    }
    void setX_Y(int xx, int yy)
    {
        x = xx;
        y = yy;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    int getXnaY()
    {
        return pow(x, y);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
