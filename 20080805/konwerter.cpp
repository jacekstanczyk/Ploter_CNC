#include "konwerter.h"


//char proba[20];
//char komenda[2];
komenda zadanie;
pozycjaPiora gdziePioro;

const double wspPosuwu=6.7733;

string linia,x,y;
string abc;
int pustePrzebiegi,przebiegiKreslace,plotX,plotY,linieProgramu,liniaWykonywana;
double pustePrzebiegiDlugosc, przebiegiKreslaceDlugosc, zmianaPisaka;

int wysokoscUnoszenia=1600;

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
		gdziePioro=Dol;

		ploter25D ploter;
		ploter.wlaczSilniki();

	
		
		
		
		
		while(getline(plik,linia)) // kazde wywolanie czyta nastepny wiersz pliku
		{

		liniaWykonywana++;
	
		int	i=0;
			
		for (;;) // sprawdza komendy w lini do wystapienia kodow konca znaku (10 i 13) lub konca pliku (26)
		{
		
			if (linia[i]=='\0')  break;
		
			 ;
	        if ((linia[i]=='I') && (linia[i+1]=='N')) {zadanie=IN; 	i+=2;}								//
  			if ((linia[i]=='S') && (linia[i+1]=='P')) {zadanie=SP; 	i+=2; zmianaPisaka++;}				//
			if ((linia[i]=='P') && (linia[i+1]=='U')) {zadanie=PU; 	i+=2; pustePrzebiegi++;}			//			sprawdza komendy
			if ((linia[i]=='P') && (linia[i+1]=='D')) {zadanie=PD; 	i+=2; przebiegiKreslace++;}			//
			if ((linia[i]=='P') && (linia[i+1]=='A')) {zadanie=PA; 	i+=2;}								//
			if ((linia[i]=='L') && (linia[i+1]=='T')) {zadanie=LT; 	i+=2;}

		
	
		
	
//*************************************		
		
			if (zadanie==IN){		cout << liniaWykonywana << " z " << linieProgramu << "\t" << "IN" << endl;}

//*************************************
		
			if (zadanie==SP)
			{
				cout << liniaWykonywana << " z " << linieProgramu << "\t" << "SP" << linia[i] << endl;

				if (linia[i]=='0') ploter.rPunkt(0, 0, wysokoscUnoszenia);
				if (linia[i]=='1') wysokoscUnoszenia=1000;
				if (linia[i]=='2') wysokoscUnoszenia=1000;
				if (linia[i]=='3') wysokoscUnoszenia=1000;
				if (linia[i]=='4') wysokoscUnoszenia=1000;
				if (linia[i]=='5') wysokoscUnoszenia=1000;
				if (linia[i]=='6') wysokoscUnoszenia=1000;
				if (linia[i]=='7') wysokoscUnoszenia=1000;
				if (linia[i]=='8') wysokoscUnoszenia=1000;
				i++;
			}

//*************************************
		
			if (zadanie==PU)
			{
		
				x.~string();
				y.~string();

				if (linia[i]==';') // jesli linia konczy sie Srednikiem 
				{
					if (gdziePioro!=Gora) // jesli pioro nie jest na gorze wykonaj
					{
						cout << liniaWykonywana << " z " << linieProgramu << "\t" << "PU " << endl;
						silnikKrokowy678H378 (1, wysokoscUnoszenia, wypelnienie, wypelnienie1);
						gdziePioro=Gora;
					}
					
				}

				else

				{
				
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

					cout << liniaWykonywana << " z " << linieProgramu << "\t" << "PU " << plotX << " " << plotY << endl;
	
					ploter.rPunkt(plotX*wspPosuwu, plotY*wspPosuwu, wysokoscUnoszenia);	
				}
			}

//*************************************
		
			if (zadanie==PD)
			{
			
				x.~string();
				y.~string();
	
				if (linia[i]==';')  // jesli linia konczy sie Srednikiem 
				{
					if (gdziePioro!=Dol) // jesli pioro nie jest na dole wykonaj
					{
						cout << liniaWykonywana << " z " << linieProgramu << "\t" << "PD " << endl;
						//silnikKrokowy678H378 (0, wysokoscUnoszenia, wypelnienie, wypelnienie1);
						silnikKrokowy678H378 (0, wysokoscUnoszenia, 3000000, 30000);
						gdziePioro=Dol;
					}
				
				}

				else

				{
			
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

					cout << liniaWykonywana << " z " << linieProgramu << "\t" << "PD " << plotX << " " << plotY << endl;
	
					ploter.rLiniaDo(plotX*wspPosuwu, plotY*wspPosuwu);	
				}
			}

//*************************************
			if (zadanie==PA)
			{
			
				x.~string();
				y.~string();
	
					if (linia[i]==';')
				{
				
				}

				else

				{
			
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

					cout << liniaWykonywana << " z " << linieProgramu << "\t" << "PA " << plotX << " " << plotY << endl;
	
				}	ploter.rLiniaDo(plotX*wspPosuwu, plotY*wspPosuwu);	
			}

//*************************************
			
			if (zadanie==LT)
			{
				cout << liniaWykonywana << " z " << linieProgramu << "\t" << "LT" << endl;
			}


//*************************************







			while (linia[i]==';') i++;																	// jesli znakiem odczytanym jest SREDNIK to posun sie o jeden znak dalej
			while (linia[i]==' ') i++;																	// jesli znakiem odczytanym jest SPACJA to posun sie o jeden znak dalej

//*************************************



		}//end for
		}//end while getline

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
			if ((linia[i]=='P') && (linia[i+1]=='A')) {zadanie=PA; przebiegiKreslace++;}
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