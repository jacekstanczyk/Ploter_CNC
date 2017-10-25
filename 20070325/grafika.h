#ifndef GRAFIKA_H
#define GRAFIKA_H



#include <complex>
#include "silnikkrokowy.h"
const double pi=3.1415;


using namespace std;

class ploter2D
{
public:
	
	ploter2D();
	~ploter2D();

	void wlaczSilniki();
	void wylaczSilniki();
	void szukajPunktBazowy();
	void ustawRozdzielczosc();
	void pokazXYZ(int * x, int * y, int * z);

	void rLiniaB(int x0, int y0, int x1, int y1);
	void rLinia(int x0, int y0, int x1, int y1, int glebokosc);
	void rLiniaDo(int x, int y, int glebokosc);
	void rPunkt(int x, int y, int glebokosc);
	void rProstokat(int x0, int y0, int x1, int y1, int glebokosc);
	void rOkrag(int x, int y, int r, int glebokosc, double poczatek=0, double koniec=2*pi);
	

	void linia(double x0, double y0, double x1, double y1);
	void liniaDo(double x, double y);
	void punkt(double x, double y);
	void prostokat(double x0, double y0, double x1, double y1);
	void okrag(double x, double y, double r, double poczatek=0, double koniec=2*pi);

private:
	
	int polozenieFrezuX, polozenieFrezuY, polozenieFrezuZ;
	
	double kartezjanskieXMin, kartezjanskieXMax , kartezjanskieYMin, kartezjanskieYMax, kartezjanskieZMin, kartezjanskieZMax; //centymetry
	int ploteroweXMin, ploteroweXMax, ploteroweYMin, ploteroweYMax, ploteroweZMin, ploteroweZMax;
	
	double gruboscObrabianegoMaterialu;
	double wysokoscUnoszeniaNarzedzia;
	double glebokoscFrezowania;

	int skala(double a, double b, int c, int d, double x);
	int przeliczX(double x);
	int przeliczY(double y);
	double radian(double kat);
	

};

#endif