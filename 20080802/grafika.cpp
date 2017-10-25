#include "grafika.h"




//******************************************************************************************************

//Konstruktor
ploter25D::ploter25D()
{
	kartezjanskieXMin=-40;
	kartezjanskieXMax=40; 
	kartezjanskieYMin=-30; 
	kartezjanskieYMax=30;
	kartezjanskieZMin=-20; 
	kartezjanskieZMax=20;


	ploteroweXMin=0;
	ploteroweXMax=214000;
	ploteroweYMin=0;
	ploteroweYMax=160000;
	ploteroweZMin=0;
	ploteroweZMax=120000;


	gruboscObrabianegoMaterialu=0.1;
	wysokoscUnoszeniaNarzedzia=1;
	glebokoscFrezowania=0.05;

	
	polozenieFrezuX=0;
	polozenieFrezuY=0;
	polozenieFrezuZ=0;
}

//Destruktor
ploter25D::~ploter25D()
{
}
//*******************************************************************************************************
void ploter25D::wlaczSilniki()
{
	zerujWyjsciaLPT1();

	zalaczSilnikKrokowy012H378();
	zalaczSilnikKrokowy345H378();
	zalaczSilnikKrokowy678H378();
}



void ploter25D::wylaczSilniki()
{
	zerujWyjsciaLPT1();

	luzujSilnikKrokowy012H378();
	luzujSilnikKrokowy345H378();
	luzujSilnikKrokowy678H378();



}



void ploter25D::szukajPunktBazowy()
{
	szukajPunktBazowyX();
	szukajPunktBazowyY();
	szukajPunktBazowyZ();

	polozenieFrezuX=0;
	polozenieFrezuY=0;
	polozenieFrezuZ=0;
}


void ploter25D::szukajRozdzielczosc()
{
	ploteroweXMax=sprawdzIleX();
	ploteroweYMax=sprawdzIleY();
	ploteroweZMax=sprawdzIleZ();
}


void ploter25D::pobierzXYZ(int * x, int * y, int * z)
{
	*x=polozenieFrezuX;
	*y=polozenieFrezuY;
	*z=polozenieFrezuZ;
}


void ploter25D::pokazXYZ()
{
	int a,b,c;
	pobierzXYZ(&a, &b, &c);
	cout << "Wspolzedna x: " << a << "\t";
	cout << "Wspolzedna y: " << b << "\t";
	cout << "Wspolzedna z: " << c << "\n";

}


void ploter25D::ustawKartezjanskieXYZ(int kartezjanskieMinX, int kartezjanskieMaxX, int kartezjanskieMinY, int kartezjanskieMaxY, int kartezjanskieMinZ, int kartezjanskieMaxZ)
{
	kartezjanskieXMin=kartezjanskieMinX;
	kartezjanskieXMax=kartezjanskieMaxX;
	kartezjanskieYMin=kartezjanskieMinY;
	kartezjanskieYMax=kartezjanskieMaxY;
	kartezjanskieZMin=kartezjanskieMinZ;
	kartezjanskieZMax=kartezjanskieMaxZ;
}


//*******************************************************************************************************
int ploter25D::skala(double a, double b, int c, int d, double x)
{
	return ( c+(x-a)*(d-c)/(b-a) );
}


int ploter25D::przeliczX(double x)
{
	return ( (int)skala(kartezjanskieXMin, kartezjanskieXMax, ploteroweXMin, ploteroweXMax, x) );
}

int ploter25D::przeliczY(double y)
{
	return ( (int)skala(kartezjanskieYMin, kartezjanskieYMax, ploteroweYMin, ploteroweYMax, y) );
}

double ploter25D::kat2radian(double kat)
{
	return ( ((2*pi)/360)*kat );
}

//*******************************************************************************************************

void ploter25D::rLiniaB(int x0, int y0, int x1, int y1)
{

	int x=x0, y=y0, pomX=x, pomY=y; 
	int	deltaX, deltaY, zwiekszenieX, zwiekszenieY;
	int  d , delta_A, delta_B; 

	
	deltaX=x1-x0;
	deltaY=y1-y0;

	if (deltaX >=0) zwiekszenieX=1;
	else 
	{
		zwiekszenieX=-1;
		deltaX=-deltaX;
	}

	if (deltaY >=0) zwiekszenieY=1;
	else 
	{	
		zwiekszenieY=-1;
		deltaY=-deltaY;
	}






	if (deltaX>deltaY)

	{

		d  = 2*deltaY - deltaX;
		delta_A = 2*deltaY;
		delta_B = 2*deltaY - 2*deltaX;


	
		for (int i=0; i<=deltaX; i++)
		{
			
			if (x>pomX) silnikKrokowy012H378 (1, 1, wypelnienie, wypelnienie1); 
			if (x<pomX) silnikKrokowy012H378 (0, 1, wypelnienie, wypelnienie1); 
			if (y>pomY) silnikKrokowy345H378 (1, 1, wypelnienie, wypelnienie1); 
			if (y<pomY) silnikKrokowy345H378 (0, 1, wypelnienie, wypelnienie1); 

			if (d > 0)
			{
                d += delta_B;
				pomX=x;
				pomY=y;
                x += zwiekszenieX;
                y += zwiekszenieY;
			}
            
			else
			{
                d += delta_A;
				pomX=x;
				pomY=y;
                x += zwiekszenieX;
			}
			
		
		}
	}

	else

	{

		d       = 2*deltaX - deltaY ;
        delta_A = 2*deltaX;
        delta_B = 2*deltaX - 2*deltaY ;


		for (int i=0; i<=deltaY; i++)
		{
			if (x>pomX) silnikKrokowy012H378 (1, 1, wypelnienie, wypelnienie1); 
			if (x<pomX) silnikKrokowy012H378 (0, 1, wypelnienie, wypelnienie1); 
			if (y>pomY) silnikKrokowy345H378 (1, 1, wypelnienie, wypelnienie1); 
			if (y<pomY) silnikKrokowy345H378 (0, 1, wypelnienie, wypelnienie1); 
			
			if (d > 0)
			{
                d += delta_B;
				pomX=x;
				pomY=y;
                x += zwiekszenieX;
                y += zwiekszenieY;
			}

            else
			{
                d += delta_A;
				pomX=x;
				pomY=y;
                y += zwiekszenieY;
			}

		}
	}

polozenieFrezuX=x1;
polozenieFrezuY=y1;	
}


void ploter25D::rLinia(int x0, int y0, int x1, int y1, int glebokosc)
{
	if ((polozenieFrezuX!=x0)||(polozenieFrezuY!=y0))
	{
		silnikKrokowy678H378 (1, glebokosc, wypelnienie, wypelnienie1); 
		rLiniaB(polozenieFrezuX, polozenieFrezuY, x0, y0);
		silnikKrokowy678H378 (0, glebokosc, wypelnienie, wypelnienie1); 
	}
		
	rLiniaB(x0, y0, x1, y1);

}



void ploter25D::rLiniaDo(int x, int y)
{
	rLiniaB(polozenieFrezuX, polozenieFrezuY, x, y);
}



void ploter25D::rPunkt(int x, int y, int glebokosc)
{
	if ((polozenieFrezuX!=x)||(polozenieFrezuY!=y))
	{
		silnikKrokowy678H378 (1, glebokosc, wypelnienie, wypelnienie1); 
		rLiniaB(polozenieFrezuX, polozenieFrezuY, x, y);
		silnikKrokowy678H378 (0, glebokosc, wypelnienie, wypelnienie1); 
	}

}




void ploter25D::rProstokat(int x0, int y0, int x1, int y1, int glebokosc)
{
	if ((polozenieFrezuX!=x0)||(polozenieFrezuY!=y0))
	{
		silnikKrokowy678H378 (1, glebokosc, wypelnienie, wypelnienie1); 
		rLiniaB(polozenieFrezuX, polozenieFrezuY, x0, y0);
		silnikKrokowy678H378 (0, glebokosc, wypelnienie, wypelnienie1); 
	}

	rLiniaB(x0, y0, x0, y1);
	rLiniaB(x0, y1, x1, y1);
	rLiniaB(x1, y1, x1, y0);
	rLiniaB(x1, y0, x0, y0);
}

void ploter25D::rOkrag(int x, int y, int r, int glebokosc, double poczatek, double koniec)
{
	
	int pomX, pomY;


	pomX=x+r*cos(poczatek);
	pomY=y+r*sin(poczatek);

	if ((polozenieFrezuX!=pomX)||(polozenieFrezuY!=pomY))
	{
		silnikKrokowy678H378 (1, glebokosc, wypelnienie, wypelnienie1); 
		rLiniaB(polozenieFrezuX, polozenieFrezuY, pomX, pomY);
		silnikKrokowy678H378 (0, glebokosc, wypelnienie, wypelnienie1); 
	}
	
	while (poczatek<=koniec)
	{
		poczatek+=0.01;

		pomX=x+r*cos(poczatek);
		pomY=y+r*sin(poczatek);

		rLiniaDo(pomX,pomY);	
	}
}


void ploter25D::rElipsa(int x, int y, int xR, int yR, int glebokosc, double poczatek, double koniec)
{
	
	int pomX, pomY;


	pomX=x+xR*cos(poczatek);
	pomY=y+yR*sin(poczatek);

	if ((polozenieFrezuX!=pomX)||(polozenieFrezuY!=pomY))
	{
		silnikKrokowy678H378 (1, glebokosc, wypelnienie, wypelnienie1); 
		rLiniaB(polozenieFrezuX, polozenieFrezuY, pomX, pomY);
		silnikKrokowy678H378 (0, glebokosc, wypelnienie, wypelnienie1); 
	}
	
	while (poczatek<=koniec)
	{
		poczatek+=0.01;

		pomX=x+xR*cos(poczatek);
		pomY=y+yR*sin(poczatek);

		rLiniaDo(pomX,pomY);
	}
}


//*******************************************************************************************************                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      


void ploter25D::linia(double x0, double y0, double x1, double y1)
{
	int xx0,yy0,xx1,yy1,glebokosc,gMax,gMin;

	xx0=przeliczX(x0);
	yy0=przeliczX(y0);
	xx1=przeliczX(x1);
	yy1=przeliczX(y1);
	
	gMax=(int)skala(0,kartezjanskieZMax-kartezjanskieZMin, ploteroweZMin, ploteroweZMax,	gruboscObrabianegoMaterialu+wysokoscUnoszeniaNarzedzia);
	gMin=(int)skala(0,kartezjanskieZMax-kartezjanskieZMin, ploteroweZMin, ploteroweZMax,	gruboscObrabianegoMaterialu-glebokoscFrezowania);
	glebokosc=gMax-gMin;

	rLinia(xx0, yy0, xx1, yy1, glebokosc);

}



void ploter25D::liniaDo(double x, double y)
{
	int xx,yy,glebokosc,gMax,gMin;

	xx=przeliczX(x);
	yy=przeliczX(y);

	gMax=(int)skala(0,kartezjanskieZMax-kartezjanskieZMin, ploteroweZMin, ploteroweZMax,	gruboscObrabianegoMaterialu+wysokoscUnoszeniaNarzedzia);
	gMin=(int)skala(0,kartezjanskieZMax-kartezjanskieZMin, ploteroweZMin, ploteroweZMax,	gruboscObrabianegoMaterialu-glebokoscFrezowania);
	glebokosc=gMax-gMin;

	rLiniaDo(xx, yy);
}


void ploter25D::punkt(double x, double y)
{
	int xx,yy,glebokosc,gMax,gMin;

	xx=przeliczX(x);
	yy=przeliczX(y);

	gMax=(int)skala(0,kartezjanskieZMax-kartezjanskieZMin, ploteroweZMin, ploteroweZMax,	gruboscObrabianegoMaterialu+wysokoscUnoszeniaNarzedzia);
	gMin=(int)skala(0,kartezjanskieZMax-kartezjanskieZMin, ploteroweZMin, ploteroweZMax,	gruboscObrabianegoMaterialu-glebokoscFrezowania);
	glebokosc=gMax-gMin;

	rPunkt(xx, yy, glebokosc);
}


void ploter25D::prostokat(double x0, double y0, double x1, double y1)
{
	int xx0,yy0,xx1,yy1,glebokosc,gMax,gMin;

	xx0=przeliczX(x0);
	yy0=przeliczX(y0);
	xx1=przeliczX(x1);
	yy1=przeliczX(y1);
	
	gMax=(int)skala(0,kartezjanskieZMax-kartezjanskieZMin, ploteroweZMin, ploteroweZMax,	gruboscObrabianegoMaterialu+wysokoscUnoszeniaNarzedzia);
	gMin=(int)skala(0,kartezjanskieZMax-kartezjanskieZMin, ploteroweZMin, ploteroweZMax,	gruboscObrabianegoMaterialu-glebokoscFrezowania);
	glebokosc=gMax-gMin;

	rLinia(xx0, yy0, xx0, yy1,glebokosc);
	rLinia(xx0, yy1, xx1, yy1,glebokosc);
	rLinia(xx1, yy1, xx1, yy0,glebokosc);
	rLinia(xx1, yy0, xx0, yy0,glebokosc);
}


void ploter25D::okrag(double x, double y, double r, double poczatek, double koniec)
{
	int xx,yy,rr,glebokosc,gMax,gMin;

	xx=przeliczX(x);
	yy=przeliczX(y);
	rr=(int)skala(0,kartezjanskieXMax-kartezjanskieXMin, ploteroweXMin, ploteroweXMax, r);
		
	gMax=(int)skala(0,kartezjanskieZMax-kartezjanskieZMin, ploteroweZMin, ploteroweZMax,	gruboscObrabianegoMaterialu+wysokoscUnoszeniaNarzedzia);
	gMin=(int)skala(0,kartezjanskieZMax-kartezjanskieZMin, ploteroweZMin, ploteroweZMax,	gruboscObrabianegoMaterialu-glebokoscFrezowania);
	glebokosc=gMax-gMin;

	poczatek=kat2radian(poczatek);
	koniec=kat2radian(koniec);

	rOkrag(xx, yy, rr, glebokosc, poczatek, koniec);
}


void ploter25D::elipsa(double x, double y, double xR, double yR, double poczatek, double koniec)
{
	int xx,yy,xxR,yyR,glebokosc,gMax,gMin;

	xx=przeliczX(x);
	yy=przeliczX(y);
	
	xxR=(int)skala(0,kartezjanskieXMax-kartezjanskieXMin, ploteroweXMin, ploteroweXMax, xR);
	yyR=(int)skala(0,kartezjanskieXMax-kartezjanskieXMin, ploteroweXMin, ploteroweXMax, yR);

		
	gMax=(int)skala(0,kartezjanskieZMax-kartezjanskieZMin, ploteroweZMin, ploteroweZMax,	gruboscObrabianegoMaterialu+wysokoscUnoszeniaNarzedzia);
	gMin=(int)skala(0,kartezjanskieZMax-kartezjanskieZMin, ploteroweZMin, ploteroweZMax,	gruboscObrabianegoMaterialu-glebokoscFrezowania);
	glebokosc=gMax-gMin;

	poczatek=kat2radian(poczatek);
	koniec=kat2radian(koniec);

	rElipsa(xx, yy, xR, yR, glebokosc, kat2radian(poczatek), kat2radian(koniec));
}