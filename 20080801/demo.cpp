#include "demo.h"



void demo()
{

ploter25D zlom;
zlom.wlaczSilniki();



zlom.rProstokat(0,0,253333,168000,1000);
/*zlom.rLinia(0,10000,20000,10000,1000);
zlom.rLinia(10000,0,10000,20000,1000);
zlom.rLinia(0,0,20000,20000,1000);
zlom.rLinia(0,20000,20000,0,1000);

for (int i=1000; i<11000; i+=1000)
zlom.rOkrag(10000, 10000, i, 1000);

zlom.rOkrag(5000, 5000, 5000, 1000);
zlom.rOkrag(5000, 15000, 5000, 1000);
zlom.rOkrag(15000, 5000, 5000, 1000);
zlom.rOkrag(15000, 15000, 5000, 1000);

zlom.rPunkt(0, 0, 1000);


//zlom.rLiniaB(70000, 0,0, 0);
*/
zlom.wylaczSilniki();
}


void demo1()
{

ploter25D zlom;
zlom.wlaczSilniki();

int yR=13000;


for (int xR=3000; xR<=13000; xR+=1000)
{

	zlom.rElipsa(0, 0, xR, yR, 1000);
	yR-=1000;
	
}
zlom.rPunkt(0, 0, 1000);

zlom.wylaczSilniki();
}


void demo2()
{
	ploter25D zlom;
	zlom.wlaczSilniki();
	
	zlom.rLiniaDo(10000,0);
	zlom.rPunkt(230000,0,1000);
	zlom.rLiniaDo(240000,0);
	zlom.rLiniaDo(240000,10000);
	zlom.rPunkt(240000,150000,1000);
	zlom.rLiniaDo(240000,160000);
	zlom.rLiniaDo(230000,160000);
	zlom.rPunkt(10000,160000,1000);
	zlom.rLiniaDo(0,160000);
	zlom.rLiniaDo(0,150000);
	zlom.rPunkt(0,10000,1000);
	zlom.rLiniaDo(0,0);






	zlom.wylaczSilniki();

}