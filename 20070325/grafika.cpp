#include "grafika.h"




//******************************************************************************************************

//Konstruktor
ploter2D::ploter2D()
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
}

//Destruktor
ploter2D::~ploter2D()
{
}
//*******************************************************************************************************
void ploter2D::wlaczSilniki()
{
	zerujWyjsciaLPT1();

	zalaczSilnikKrokowy012H378();
	zalaczSilnikKrokowy345H378();
	zalaczSilnikKrokowy678H378();
}



void ploter2D::wylaczSilniki()
{
	zerujWyjsciaLPT1();

	luzujSilnikKrokowy012H378();
	luzujSilnikKrokowy345H378();
	luzujSilnikKrokowy678H378();



}



void ploter2D::szukajPunktBazowy()
{
	szukajPunktBazowyX();
	szukajPunktBazowyY();
	szukajPunktBazowyZ();

	polozenieFrezuX=0;
	polozenieFrezuY=0;
	polozenieFrezuZ=0;
}


void ploter2D::ustawRozdzielczosc()
{
	ploteroweXMax=sprawdzIleX();
	ploteroweYMax=sprawdzIleY();
	ploteroweZMax=sprawdzIleZ();
}


void ploter2D::pokazXYZ(int * x, int * y, int * z)
{
	*x=polozenieFrezuX;
	*y=polozenieFrezuY;
	*z=polozenieFrezuZ;
}




//*******************************************************************************************************
int ploter2D::skala(double a, double b, int c, int d, double x)
{
	return ( c+(x-a)*(d-c)/(b-a) );
}


int ploter2D::przeliczX(double x)
{
	return ( (int)skala(kartezjanskieXMin, kartezjanskieXMax, ploteroweXMin, ploteroweXMax, x) );
}

int ploter2D::przeliczY(double y)
{
	return ( (int)skala(kartezjanskieYMin, kartezjanskieYMax, ploteroweYMin, ploteroweYMax, y) );
}

double ploter2D::radian(double kat)
{
	return ( ((2*pi)/360)*kat );
}

//*******************************************************************************************************

void ploter2D::rLiniaB(int x0, int y0, int x1, int y1)
{

	int x=x0, y=y0, pomX=x, pomY=y; 
	int	deltaX, deltaY, zwiekszenieX, zwiekszenieY;
	float odchylenie=0;

	
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
		for (int i=0; i<deltaX; i++)
		{
			if (x>pomX) silnikKrokowy012H378 (1, 1, 4000, 4000); 
			if (x<pomX) silnikKrokowy012H378 (0, 1, 4000, 4000); 
			if (y>pomY) silnikKrokowy345H378 (1, 1, 4000, 4000); 
			if (y<pomY) silnikKrokowy345H378 (0, 1, 4000, 4000); 

			if (odchylenie>=0)
			{
				odchylenie=odchylenie-deltaX/2;
				pomY=y;
				y=y+zwiekszenieY;	
			}

			odchylenie=odchylenie+deltaY/2;
			pomX=x;
			x=x+zwiekszenieX;
		}
	}

	else

	{
		for (int i=0; i<deltaY; i++)
		{
			if (x>pomX) silnikKrokowy012H378 (1, 1, 4000, 4000); 
			if (x<pomX) silnikKrokowy012H378 (0, 1, 4000, 4000); 
			if (y>pomY) silnikKrokowy345H378 (1, 1, 4000, 4000); 
			if (y<pomY) silnikKrokowy345H378 (0, 1, 4000, 4000); 

			if (odchylenie>=0)
			{
				odchylenie=odchylenie-deltaY/2;
				pomX=x;
				x=x+zwiekszenieX;
			}

			odchylenie=odchylenie+deltaX/2;
			pomY=y;
			y=y+zwiekszenieY;
		}
	}

	polozenieFrezuX=x1;
	polozenieFrezuY=y1;

}



void ploter2D::rLinia(int x0, int y0, int x1, int y1, int glebokosc)
{
	if ((polozenieFrezuX!=x0)||(polozenieFrezuY!=y0))
	{
		silnikKrokowy678H378 (1, glebokosc, 4000, 4000); 
		rLiniaB(polozenieFrezuX, polozenieFrezuY, x0, y0);
		silnikKrokowy678H378 (0, glebokosc, 4000, 4000); 
	}
		
	rLiniaB(x0, y0, x1, y1);

}



void ploter2D::rLiniaDo(int x, int y, int glebokosc)
{
	rLiniaB(polozenieFrezuX, polozenieFrezuY, x, y);
}



void ploter2D::rPunkt(int x, int y, int glebokosc)
{
	if ((polozenieFrezuX!=x)||(polozenieFrezuY!=y))
	{
		silnikKrokowy678H378 (1, glebokosc, 4000, 4000); 
		rLiniaB(polozenieFrezuX, polozenieFrezuY, x, y);
		silnikKrokowy678H378 (0, glebokosc, 4000, 4000); 
	}

}




void ploter2D::rProstokat(int x0, int y0, int x1, int y1, int glebokosc)
{
	if ((polozenieFrezuX!=x0)||(polozenieFrezuY!=y0))
	{
		silnikKrokowy678H378 (1, glebokosc, 4000, 4000); 
		rLiniaB(polozenieFrezuX, polozenieFrezuY, x0, y0);
		silnikKrokowy678H378 (0, glebokosc, 4000, 4000); 
	}

	rLiniaB(x0, y0, x0, y1);
	rLiniaB(x0, y1, x1, y1);
	rLiniaB(x1, y1, x1, y0);
	rLiniaB(x1, y0, x0, y0);
}

void ploter2D::rOkrag(int x, int y, int r, int glebokosc, double poczatek, double koniec)
{
	
	int pomX, pomY;

	if ((polozenieFrezuX!=x)||(polozenieFrezuY!=y))
	{
		silnikKrokowy678H378 (1, glebokosc, 4000, 4000); 
		rLiniaB(polozenieFrezuX, polozenieFrezuY, x, y);
		silnikKrokowy678H378 (0, glebokosc, 4000, 4000); 
	}
	
	while (poczatek<=koniec)
	{
		pomX=x+r*cos(radian(poczatek));
		pomY=y+r*sin(radian(poczatek));

		rLiniaDo(pomX,pomY,glebokosc);

		poczatek++;
	}
}




//*******************************************************************************************************                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      


void ploter2D::linia(double x0, double y0, double x1, double y1)
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



void ploter2D::liniaDo(double x, double y)
{
	int xx,yy,glebokosc,gMax,gMin;

	xx=przeliczX(x);
	yy=przeliczX(y);

	gMax=(int)skala(0,kartezjanskieZMax-kartezjanskieZMin, ploteroweZMin, ploteroweZMax,	gruboscObrabianegoMaterialu+wysokoscUnoszeniaNarzedzia);
	gMin=(int)skala(0,kartezjanskieZMax-kartezjanskieZMin, ploteroweZMin, ploteroweZMax,	gruboscObrabianegoMaterialu-glebokoscFrezowania);
	glebokosc=gMax-gMin;

	rLiniaDo(xx, yy, glebokosc);
}


void ploter2D::punkt(double x, double y)
{
	int xx,yy,glebokosc,gMax,gMin;

	xx=przeliczX(x);
	yy=przeliczX(y);

	gMax=(int)skala(0,kartezjanskieZMax-kartezjanskieZMin, ploteroweZMin, ploteroweZMax,	gruboscObrabianegoMaterialu+wysokoscUnoszeniaNarzedzia);
	gMin=(int)skala(0,kartezjanskieZMax-kartezjanskieZMin, ploteroweZMin, ploteroweZMax,	gruboscObrabianegoMaterialu-glebokoscFrezowania);
	glebokosc=gMax-gMin;

	rPunkt(xx, yy, glebokosc);
}


void ploter2D::prostokat(double x0, double y0, double x1, double y1)
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


void ploter2D::okrag(double x, double y, double r, double poczatek, double koniec)
{
	int xx,yy,rr,glebokosc,gMax,gMin;

	xx=przeliczX(x);
	yy=przeliczX(y);
	rr=(int)skala(0,kartezjanskieXMax-kartezjanskieXMin, ploteroweXMin, ploteroweXMax, r);
		
	gMax=(int)skala(0,kartezjanskieZMax-kartezjanskieZMin, ploteroweZMin, ploteroweZMax,	gruboscObrabianegoMaterialu+wysokoscUnoszeniaNarzedzia);
	gMin=(int)skala(0,kartezjanskieZMax-kartezjanskieZMin, ploteroweZMin, ploteroweZMax,	gruboscObrabianegoMaterialu-glebokoscFrezowania);
	glebokosc=gMax-gMin;

	rOkrag(xx, yy, rr, glebokosc, poczatek, koniec);
}