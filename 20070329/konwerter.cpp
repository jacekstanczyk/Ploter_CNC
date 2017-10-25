#include "konwerter.h"


char proba[20];
char komenda[2];
kom zadanie;
string linia,x,y;

int pustePrzebiegi,przebiegiKreslace,plotX,plotY;
double pustePrzebiegiDlugosc, przebiegiKreslaceDlugosc;



//********************************************************************************************************************
int rysujPlikPLT(char * nazwaPliku)
{

	ifstream plik(nazwaPliku);
	//plik.open(nazwaPliku);
	string linia;

	if (plik.is_open())
	{
		pustePrzebiegi=0;
		przebiegiKreslace=0;

		ploter2D ploter;
		ploter.wlaczSilniki();

		while(getline(plik,linia))
		{


			if ((linia[0]=='I') && (linia[1]=='N')) {zadanie=IN;}
			if ((linia[0]=='S') && (linia[1]=='P')) {zadanie=SP;}
			if ((linia[0]=='P') && (linia[1]=='U')) {zadanie=PU; pustePrzebiegi++;}
			if ((linia[0]=='P') && (linia[1]=='D')) {zadanie=PD; przebiegiKreslace++;}
	
//*************************************		
		
			if (zadanie==IN){}

//*************************************
		
			if (zadanie==SP)
			{
				if (linia[2]=='0') ploter.rPunkt(0, 0, 1000);
			}

//*************************************
		
			if (zadanie==PU)
			{
				x.~string();
				y.~string();

				int i=2;
				while (linia[i]!=' ')
				{
					x+=linia[i];
					i++;
				}
				
				i++;
				while (linia[i]!=';')
				{
					y+=linia[i];
					i++;
				}

				plotX=atof(x.data());
				plotY=atof(y.data());

				ploter.rPunkt(plotX*7, plotY*7, 1000);	
			}

//*************************************
		
			if (zadanie==PD)
			{
				x.~string();
				y.~string();

				int i=2;
				while (linia[i]!=' ')
				{
					x+=linia[i];
					i++;
				}
				
				i++;
				while (linia[i]!=';')
				{
					y+=linia[i];
					i++;
				}

				plotX=atof(x.data());
				plotY=atof(y.data());

				ploter.rLiniaDo(plotX*7, plotY*7);	
			}

//*************************************

		}

		ploter.wylaczSilniki();
		cout << "Puste przebiegi: " << pustePrzebiegi << "\t\tPrzebiegi kreslace: " << przebiegiKreslace << endl;


plik.close();
return 0;
}

else return 1;


}


//********************************************************************************************************************
int przeliczPlikPLT(char * nazwaPliku)
{

	ifstream plik(nazwaPliku);
	//plik.open(nazwaPliku);
	string linia;

	if (plik.is_open())
	{
		pustePrzebiegi=0;
		przebiegiKreslace=0;



		while(getline(plik,linia))
		{


			if ((linia[0]=='I') && (linia[1]=='N')) {zadanie=IN;}
			if ((linia[0]=='S') && (linia[1]=='P')) {zadanie=SP;}
			if ((linia[0]=='P') && (linia[1]=='U')) {zadanie=PU; pustePrzebiegi++;}
			if ((linia[0]=='P') && (linia[1]=='D')) {zadanie=PD; przebiegiKreslace++;}
		}

	
		cout << "Puste przebiegi: " << pustePrzebiegi << "\t\tPrzebiegi kreslace: " << przebiegiKreslace << endl;

plik.close();
return 0;
}

else return 1;

}