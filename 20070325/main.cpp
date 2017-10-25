#include "silnikkrokowy.h"
#include "grafika.h"

#include <iostream>
using namespace std;

int main()
{

ploter2D zlom;

zlom.wlaczSilniki();
//zlom.szukajPunktBazowy();

zlom.rLiniaB(0,0,10000,10000);
zlom.rLiniaB(10000,10000,0,10000);
zlom.rLiniaB(0,10000,0,20000);
zlom.rLiniaB(0,20000,10000,20000);

zlom.wylaczSilniki();

return 0;
}
