#ifndef GRAFIKA_H
#define GRAFIKA_H


#include <iostream>
#include <complex>
#include "silnikkrokowy.h"
const double pi=3.1415;


using namespace std;

class ploter25D
{
public:
	
	ploter25D();
	~ploter25D();

	void wlaczSilniki();
	void wylaczSilniki();
	void szukajPunktBazowy();
	void szukajRozdzielczosc();
	void pobierzXYZ(int * x, int * y, int * z);
	void pokazXYZ();
	void ustawKartezjanskieXYZ(int kartezjanskieMinX, int kartezjanskieMaxX, int kartezjanskieMinY, int kartezjanskieMaxY, int kartezjanskieMinZ, int kartezjanskieMaxZ);

	void rLiniaB(int x0, int y0, int x1, int y1);
	void rLinia(int x0, int y0, int x1, int y1, int glebokosc);
	void rLiniaDo(int x, int y);
	void rPunkt(int x, int y, int glebokosc);
	void rProstokat(int x0, int y0, int x1, int y1, int glebokosc);
	void rOkrag(int x, int y, int r, int glebokosc, double poczatek=0, double koniec=2*pi);
	void rElipsa(int x, int y, int xR, int yR, int glebokosc, double poczatek=0, double koniec=2*pi);

	void linia(double x0, double y0, double x1, double y1);
	void liniaDo(double x, double y);
	void punkt(double x, double y);
	void prostokat(double x0, double y0, double x1, double y1);
	void okrag(double x, double y, double r, double poczatek=0, double koniec=2*pi);
	void elipsa(double x, double y, double xR, double yR, double poczatek, double koniec);
	


private:
	
	int polozenieFrezuX, polozenieFrezuY, polozenieFrezuZ;
	
	int ploteroweXMin, ploteroweXMax, ploteroweYMin, ploteroweYMax, ploteroweZMin, ploteroweZMax;
	double kartezjanskieXMin, kartezjanskieXMax , kartezjanskieYMin, kartezjanskieYMax, kartezjanskieZMin, kartezjanskieZMax; //centymetry
	
	
	
	double gruboscObrabianegoMaterialu;
	double wysokoscUnoszeniaNarzedzia;
	double glebokoscFrezowania;

	int skala(double a, double b, int c, int d, double x);
	int przeliczX(double x);
	int przeliczY(double y);
	double kat2radian(double kat);
	

};

#endif