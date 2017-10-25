#include "silnikKrokowy.h"
#include "port.h"

#include <windows.h>


/************************************************************************************************************************/
// Zeruje wszystkie wyjscia poru LPT1

void zerujWyjsciaLPT1()
{
	outport (Port,0);
	ustawBit (Port3,0,1);
	ustawBit (Port3,1,1);
	ustawBit (Port3,2,0);
	ustawBit (Port3,3,1);
}


/************************************************************************************************************************/
// Steruje silnikiem krokowym w kierunku "kierunek" o liczbe krokow "liczbaKrokow" ze zwlaka(milisekundy) "zwloka" podlaczenie 0x378 (0123)

void silnikKrokowy0123H378 (unsigned char kierunek, int liczbaKrokow, int zwloka)
{
	int tab [8][4] = {	1,0,0,0,
						1,0,0,1,
						0,0,0,1,
						0,1,0,1,
						0,1,0,0,
						0,1,1,0,
						0,0,1,0,
						1,0,1,0};
	static int licznik;

	if (kierunek)
	{
		for (int i=0 ; i<liczbaKrokow ; i++)
		{
				
				//if ( sprawdzPrzyciskStop() ) czekajDoWcisnieciaStart();
			
				ustawBit(Port,0,0);
				ustawBit(Port,1,0);
				ustawBit(Port,2,0);
				ustawBit(Port,3,0);
				
				for (int j=0 ; j<4 ; j++)
				{
					ustawBit(Port, j ,tab[licznik][j]); 
				}

				//Sleep(zwloka);
				for (int k=0 ; k<zwloka ; k++);

				licznik++;
				if (licznik>7) licznik=0; 
				
		}
	}
	else
	{
		for (int i=0 ; i<liczbaKrokow ; i++)
		{
				//if ( sprawdzPrzyciskStop() ) czekajDoWcisnieciaStart();
				
				ustawBit(Port,0,0);
				ustawBit(Port,1,0);
				ustawBit(Port,2,0);
				ustawBit(Port,3,0);
				
				for (int j=0 ; j<4 ; j++)
				{
					ustawBit(Port, j ,tab[licznik][j]); 
				}
	
				//Sleep(zwloka);
				for (int k=0 ; k<zwloka ; k++);

				licznik--;
				if (licznik<0) licznik=7; 
		}
	}
}


/************************************************************************************************************************/
// Steruje silnikiem krokowym w kierunku "kierunek" o liczbe krokow "liczbaKrokow" ze zwlaka(milisekundy) "zwloka" podlaczenie 0x378 (4567)

void silnikKrokowy4567H378 (unsigned char kierunek, int liczbaKrokow, int zwloka)
{
	int tab [8][4] = {	1,0,0,0,
						1,0,0,1,
						0,0,0,1,
						0,1,0,1,
						0,1,0,0,
						0,1,1,0,
						0,0,1,0,
						1,0,1,0};
	static int licznik;

	if (kierunek)
	{
		for (int i=0 ; i<liczbaKrokow ; i++)
		{
				//if ( sprawdzPrzyciskStop() ) czekajDoWcisnieciaStart();
			
				ustawBit(Port,4,0);
				ustawBit(Port,5,0);
				ustawBit(Port,6,0);
				ustawBit(Port,7,0);
				
				for (int j=0 ; j<4 ; j++)
				{
					ustawBit(Port, (j+4) ,tab[licznik][j]); 
				}
	
			//	Sleep(zwloka);
				for (int k=0 ; k<zwloka ; k++);

				licznik++;
				if (licznik>7) licznik=0; 
			
		}
	}
	else
	{
		for (int i=0 ; i<liczbaKrokow ; i++)
		{
				//if ( sprawdzPrzyciskStop() ) czekajDoWcisnieciaStart();
			
				ustawBit(Port,4,0);
				ustawBit(Port,5,0);
				ustawBit(Port,6,0);
				ustawBit(Port,7,0);
				
				for (int j=0 ; j<4 ; j++)
				{
					ustawBit(Port, (j+4) ,tab[licznik][j]); 
				}
	
			//	Sleep(zwloka);
				for (int k=0 ; k<zwloka ; k++);

				licznik--;
				if (licznik<0) licznik=7;
		}
	}
}


/************************************************************************************************************************/
// Steruje silnikiem krokowym w kierunku "kierunek" o liczbe krokow "liczbaKrokow" ze zwlaka(milisekundy) "zwloka" podlaczenie 0x37A (0123)

void silnikKrokowy0123H37A (unsigned char kierunek, int liczbaKrokow, int zwloka)
{
	int tab [8][4] = {	0,1,0,1,
						0,1,0,0,
						1,1,0,0,
						1,0,0,0,
						1,0,0,1,
						1,0,1,1,
						1,1,1,1,
						0,1,1,1};
	static int licznik;

	if (kierunek)
	{
		for (int i=0 ; i<liczbaKrokow ; i++)
		{
				//if ( sprawdzPrzyciskStop() ) czekajDoWcisnieciaStart();
			
				ustawBit(Port3,0,1);
				ustawBit(Port3,1,1);
				ustawBit(Port3,2,0);
				ustawBit(Port3,3,1);
				
				for (int j=0 ; j<4 ; j++)
				{
					ustawBit(Port3, j ,tab[licznik][j]); 
				}

			//	Sleep(zwloka);
				for (int k=0 ; k<zwloka ; k++);

				licznik++;
				if (licznik>7) licznik=0; 
				
		}
	}
	else
	{
		for (int i=0 ; i<liczbaKrokow ; i++)
		{
				//if ( sprawdzPrzyciskStop() ) czekajDoWcisnieciaStart();
			
				ustawBit(Port3,0,1);
				ustawBit(Port3,1,1);
				ustawBit(Port3,2,0);
				ustawBit(Port3,3,1);
				
				for (int j=0 ; j<4 ; j++)
				{
					ustawBit(Port3, j ,tab[licznik][j]); 
				}
	
				//Sleep(zwloka);
				for (int k=0 ; k<zwloka ; k++);

				licznik--;
				if (licznik<0) licznik=7; 
		}
	}
}




/************************************************************************************************************************/
// Steruje silnikiem krokowym w kierunku "kierunek" o liczbe krokow "liczbaKrokow" ze zwlaka(milisekundy) "zwloka" podlaczenie 0x378 (012)

void silnikKrokowy012H378 (unsigned char kierunek, int liczbaKrokow, int zwloka0, int zwloka1)
{


	if (kierunek)
	{
		ustawBit(Port,1,1);
		for (int i=0 ; i<liczbaKrokow ; i++)
		{
				
				//if ( sprawdzPrzyciskStop() ) czekajDoWcisnieciaStart();
			
				ustawBit(Port,0,1);
				//Sleep(zwloka1);
				for (int k=0 ; k<zwloka0 ; k++);
				ustawBit(Port,0,0);
				for (int j=0 ; j<zwloka1 ; j++);
				
		}
	}
	else
	{
		ustawBit(Port,1,0);
		for (int i=0 ; i<liczbaKrokow ; i++)
		{
				
			//	if ( sprawdzPrzyciskStop() ) czekajDoWcisnieciaStart();
			
				ustawBit(Port,0,1);
				//Sleep(zwloka1);
				for (int k=0 ; k<zwloka0 ; k++);
				ustawBit(Port,0,0);
				for (int j=0 ; j<zwloka1 ; j++);
		}
	}
}




/************************************************************************************************************************/
// Steruje silnikiem krokowym w kierunku "kierunek" o liczbe krokow "liczbaKrokow" ze zwlaka(milisekundy) "zwloka" podlaczenie 0x378 (345)

void silnikKrokowy345H378 (unsigned char kierunek, int liczbaKrokow, int zwloka0, int zwloka1)
{


	if (kierunek)
	{
		ustawBit(Port,4,0);
		for (int i=0 ; i<liczbaKrokow ; i++)
		{
				
			//	if ( sprawdzPrzyciskStop() ) czekajDoWcisnieciaStart();
			
				ustawBit(Port,3,1);
				//Sleep(zwloka1);
				for (int k=0 ; k<zwloka0 ; k++);
				ustawBit(Port,3,0);
				for (int j=0 ; j<zwloka1 ; j++);
				
		}
	}
	else
	{
		ustawBit(Port,4,1);
		for (int i=0 ; i<liczbaKrokow ; i++)
		{
				
				//if ( sprawdzPrzyciskStop() ) czekajDoWcisnieciaStart();
				
				ustawBit(Port,3,1);
				//Sleep(zwloka1);
				for (int k=0 ; k<zwloka0 ; k++);
				ustawBit(Port,3,0);
				for (int j=0 ; j<zwloka1 ; j++);
		}
	}
}





/************************************************************************************************************************/
// Steruje silnikiem krokowym w kierunku "kierunek" o liczbe krokow "liczbaKrokow" ze zwlaka(milisekundy) "zwloka" podlaczenie 0x378 (678)

void silnikKrokowy678H378 (unsigned char kierunek, int liczbaKrokow, int zwloka0, int zwloka1)
{


	if (kierunek)
	{
		ustawBit(Port,7,0);
		for (int i=0 ; i<liczbaKrokow ; i++)
		{
				
			//	if ( sprawdzPrzyciskStop() ) czekajDoWcisnieciaStart();
			
				ustawBit(Port,6,1);
				//Sleep(zwloka1);
				for (int k=0 ; k<zwloka0 ; k++);
				ustawBit(Port,6,0);
				for (int j=0 ; j<zwloka1 ; j++);
				
		}
	}
	else
	{
		ustawBit(Port,7,1);
		for (int i=0 ; i<liczbaKrokow ; i++)
		{
				
			//	if ( sprawdzPrzyciskStop() ) czekajDoWcisnieciaStart();
			
				ustawBit(Port,6,1);
				//Sleep(zwloka1);
				for (int k=0 ; k<zwloka0 ; k++);
				ustawBit(Port,6,0);
				for (int j=0 ; j<zwloka1 ; j++);
		}
	}
}




/************************************************************************************************************************/
void luzujSilnikKrokowy012H378()
{
		ustawBit(Port,2,0);
}

void luzujSilnikKrokowy345H378()
{
		ustawBit(Port,5,0);
}

void luzujSilnikKrokowy678H378()
{
		ustawBit(Port3,0,1);
}




void zalaczSilnikKrokowy012H378()
{
		ustawBit(Port,2,1);
}

void zalaczSilnikKrokowy345H378()
{
		ustawBit(Port,5,1);
}

void zalaczSilnikKrokowy678H378()
{
		ustawBit(Port3,0,0);
}





/************************************************************************************************************************/

void szukajPunktBazowyX()
{
	while(!stanLiniX()) silnikKrokowy012H378 (0, 1, 50000, 50000);
	while(stanLiniX()) silnikKrokowy012H378 (1, 1, 50000, 50000);
}

void szukajPunktBazowyY()
{
	while(!stanLiniY()) silnikKrokowy345H378 (0, 1, 50000, 50000);
	while(stanLiniY()) silnikKrokowy345H378 (1, 1, 50000, 50000);
}

void szukajPunktBazowyZ()
{
	while(!stanLiniZ()) silnikKrokowy678H378 (0, 1, 50000, 50000);
	while(stanLiniZ()) silnikKrokowy678H378 (1, 1, 50000, 50000);
}


int sprawdzIleX()
{
	int i=0;
	szukajPunktBazowyX();
	
	while(!stanLiniX()) 
	{	
		silnikKrokowy012H378 (1, 1, 50000, 50000);
		i++;
	}

	return i;
}

int sprawdzIleY()
{
	int i=0;
	szukajPunktBazowyY();
	
	while(!stanLiniY()) 
	{	
		silnikKrokowy345H378 (1, 1, 50000, 50000);
		i++;
	}

	return i;
}

int sprawdzIleZ()
{
	int i=0;
	szukajPunktBazowyZ();
	
	while(!stanLiniZ()) 
	{	
		silnikKrokowy678H378 (1, 1, 50000, 50000);
		i++;
	}

	return i;
}

/************************************************************************************************************************/

// Odczytuje stan lini X
unsigned char stanLiniX()
{
	if ( odczytajBit(Port2, 3) ) return 1;
	else return 0;
}

// Odczytuje stan lini Y
unsigned char stanLiniY()
{
	if ( odczytajBit(Port2, 4) ) return 1;
	else return 0;
}

// Odczytuje stan lini Z
unsigned char stanLiniZ()
{
	if ( odczytajBit(Port2, 5) ) return 1;
	else return 0;
}

unsigned char sprawdzPrzyciskStop()
{
		if ( odczytajBit(Port2, 6) ) return 1;
	else return 0;
}

unsigned char sprawdzPrzyciskStart()
{
		if ( odczytajBit(Port2, 7) ) return 1;
	else return 0;
}

void czekajDoWcisnieciaStart()
{
	while (  !( (!sprawdzPrzyciskStop())  &&  (sprawdzPrzyciskStart()) ) );
}

/************************************************************************************************************************/

void docieranieX()
{
	int i=0;
	for (;;)
	{
		while (!stanLiniX()) silnikKrokowy012H378 (i, 1, 5000, 5000);
		
		if (i==0) i=1; else i=0;
		silnikKrokowy012H378 (i, 1600, 5000, 5000);
	}
}

void docieranieY()
{
	int i=0;
	for (;;)
	{
		while (!stanLiniX()) silnikKrokowy345H378 (i, 1, 5000, 5000);
		
		if (i==0) i=1; else i=0;
		silnikKrokowy345H378 (i, 1600, 5000, 5000);
	}

}

void docieranieZ()
{
	int i=0;
	for (;;)
	{
		while (!stanLiniX()) silnikKrokowy678H378 (i, 1, 5000, 5000);
		
		if (i==0) i=1; else i=0;
		silnikKrokowy678H378 (i, 1600, 5000, 5000);
	}

}