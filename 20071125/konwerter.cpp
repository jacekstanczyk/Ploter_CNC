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

		ploter25D ploter;
		ploter.wlaczSilniki();

		while(getline(plik,linia))
		{


		int	i=0;
			
			if ((linia[i]=='I') && (linia[i+1]=='N')) {zadanie=IN;}
			if ((linia[i]=='S') && (linia[i+1]=='P')) {zadanie=SP;}
			if ((linia[i]=='P') && (linia[i+1]=='U')) {zadanie=PU; pustePrzebiegi++;}
			if ((linia[i]=='P') && (linia[i+1]=='D')) {zadanie=PD; przebiegiKreslace++;}

			i+=2;
	
//*************************************		
		
			if (zadanie==IN){}

//*************************************
		
			if (zadanie==SP)
			{
				if (linia[i]=='0') ploter.rPunkt(0, 0, 1000);
			}

//*************************************
		
			if (zadanie==PU)
			{
				x.~string();
				y.~string();

				while ((linia[i]<='0')||(linia[i]>='9')) i++;
				while ((linia[i]!=' ')||(linia[i]!=','))
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

				if (linia[i]==';') continue;
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

		int	i=0;
		
			if ((linia[i]=='I') && (linia[i+1]=='N')) {zadanie=IN;}
			if ((linia[i]=='S') && (linia[i+1]=='P')) {zadanie=SP;}
			if ((linia[i]=='P') && (linia[i+1]=='U')) {zadanie=PU; pustePrzebiegi++;}
			if ((linia[i]=='P') && (linia[i+1]=='D')) {zadanie=PD; przebiegiKreslace++;}
		}

	
		cout << "Puste przebiegi: " << pustePrzebiegi << "\t\tPrzebiegi kreslace: " << przebiegiKreslace << endl;

plik.close();
return 0;
}

else return 1;

}