#include "konwerter.h"


char proba[20];
char komenda[2];
kom zadanie;
string linia,x,y;
string abc;
int pustePrzebiegi,przebiegiKreslace,plotX,plotY,linieProgramu,liniaWykonywana;
double pustePrzebiegiDlugosc, przebiegiKreslaceDlugosc, zmianaPisaka;



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
		zmianaPisaka=0;
		liniaWykonywana=0;
		

		ploter25D ploter;
		ploter.wlaczSilniki();

		while(getline(plik,linia))
		{

		liniaWykonywana++;
		cout << liniaWykonywana << " z " << linieProgramu << endl;
		int	i=0;
			
			if ((linia[i]=='I') && (linia[i+1]=='N')) {zadanie=IN;}
			if ((linia[i]=='S') && (linia[i+1]=='P')) {zadanie=SP; zmianaPisaka++;}
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

				while ((linia[i]<'0')&&(linia[i]>'9')&&(linia[i]!='-')) i++;
				while ( !((linia[i]==' ')||(linia[i]==',')) )
			
				
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
	
				ploter.rPunkt(plotX*50, plotY*50, 1000);	
			}

//*************************************
		
			if (zadanie==PD)
			{
		
				x.~string();
				y.~string();
	
				if (linia[i]==';') continue;
			
				while ((linia[i]<'0')&&(linia[i]>'9')&&(linia[i]!='-')) i++;
				while ( !((linia[i]==' ')||(linia[i]==',')) )
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
	
				ploter.rLiniaDo(plotX*50, plotY*50);	
			}

//*************************************

		}

		ploter.wylaczSilniki();
		cout << "Puste przebiegi: " << pustePrzebiegi << endl << "Przebiegi kreslace: " << przebiegiKreslace << endl << "Zmiana pisaka: " << zmianaPisaka << endl;


plik.close();

return 0;
}

else return 1;


}


//********************************************************************************************************************
int przeliczPlikPLT(char * nazwaPliku)
{
cout << "jestem w przelicz" << endl;
	ifstream plik(nazwaPliku);
	//plik.open(nazwaPliku);
	string linia;

	if (plik.is_open())
	{
		pustePrzebiegi=0;
		przebiegiKreslace=0;
		zmianaPisaka=0;
	    linieProgramu=0;

		while(getline(plik,linia))
		{
		
		linieProgramu++;
		int	i=0;
		
			if ((linia[i]=='I') && (linia[i+1]=='N')) {zadanie=IN;}
			if ((linia[i]=='S') && (linia[i+1]=='P')) {zadanie=SP; zmianaPisaka++;}
			if ((linia[i]=='P') && (linia[i+1]=='U')) {zadanie=PU; pustePrzebiegi++;}
			if ((linia[i]=='P') && (linia[i+1]=='D')) {zadanie=PD; przebiegiKreslace++;}
		}

	
		cout << "Puste przebiegi: " << pustePrzebiegi << endl << "Przebiegi kreslace: " << przebiegiKreslace << endl 
			<< "Zmiana pisaka: " << zmianaPisaka << endl << "Linii programu: " << linieProgramu << endl;

plik.close();

return 0;
}

else return 1;

}

//********************************************************************************************************************
int przeliczWymiary(char * nazwaPliku)
{
int minX=0,maxX=0,minY=0,maxY=0,deltaX=0,deltaY=0,przebiegi=0;

	ifstream plik(nazwaPliku);
	//plik.open(nazwaPliku);
	string linia;

	if (plik.is_open())
	{
		pustePrzebiegi=0;
		przebiegiKreslace=0;
		zmianaPisaka=0;
	
	

		while(getline(plik,linia))
		{


		int	i=0;
			
			if ((linia[i]=='I') && (linia[i+1]=='N')) {zadanie=IN;}
			if ((linia[i]=='S') && (linia[i+1]=='P')) {zadanie=SP; zmianaPisaka++;}
			if ((linia[i]=='P') && (linia[i+1]=='U')) {zadanie=PU; pustePrzebiegi++;}
			if ((linia[i]=='P') && (linia[i+1]=='D')) {zadanie=PD; przebiegiKreslace++;}

			i+=2;
	
//*************************************		
		
			if (zadanie==IN){}
	

//*************************************
		
			if (zadanie==SP) {}
		
;
//*************************************
		
			if (zadanie==PU)
			{
		
				x.~string();
				y.~string();

				while ( !((linia[i]<'0')||(linia[i]>'9')||(linia[i]!='-')) ) i++;
				while ( !((linia[i]==' ')||(linia[i]==',')) )
			
				
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
	
				if (przebiegi==0)
				{
					minX=plotX;
					maxX=plotX;
					minY=plotY;
					maxY=plotY;
					przebiegi++;
				}
				

				if (plotX<minX) minX=plotX;
				if (plotX>maxX) maxX=plotX;
				if (plotY<minY) minY=plotY;
				if (plotY>maxY) maxY=plotY;
				deltaX=maxX-minX;
				deltaY=maxY-minY;
			}

//*************************************
		
			if (zadanie==PD)
			{
		
				x.~string();
				y.~string();
	
				if (linia[i]==';') continue;
			
				while ( !((linia[i]<'0')||(linia[i]>'9')||(linia[i]!='-')) ) i++;
				while ( !((linia[i]==' ')||(linia[i]==',')) )
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
	
				if (przebiegi==0)
				{
					minX=plotX;
					maxX=plotX;
					minY=plotY;
					maxY=plotY;
					przebiegi++;
				}


				if (plotX<minX) minX=plotX;
				if (plotX>maxX) maxX=plotX;
				if (plotY<minY) minY=plotY;
				if (plotY>maxY) maxY=plotY;
				deltaX=maxX-minX;
				deltaY=maxY-minY;
			}

//*************************************

		}

	
		cout << "Puste przebiegi: " << pustePrzebiegi << endl << "Przebiegi kreslace: " << przebiegiKreslace << endl << "Zmiana pisaka: " << zmianaPisaka << endl;
		cout << "minX: " << minX << endl << "maxX: " << maxX << endl << "minY: " << minY << endl << "maxY: " << maxY << endl; 
			cout << "deltaX: " << deltaX << endl << "deltaY: " << deltaY << endl << endl;

plik.close();

return 0;
}

else return 1;



return 0;
}