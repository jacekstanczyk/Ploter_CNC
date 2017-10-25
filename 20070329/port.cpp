#include "port.h"

/************************************************************************************************************************/
// Zapisuje bajt danych "co" do portu o numerze "port"


void outport (unsigned int port, unsigned char co)
{

__asm	mov dx,word ptr port
__asm	mov al,byte ptr co
__asm	out dx,al

}


/************************************************************************************************************************/
// Odczytuje bajt danych z portu o numerze "port"

unsigned char inport (unsigned int port)
{
unsigned char a;

__asm	mov dx,word ptr port
__asm	in al,dx
__asm	mov a,al
	 
	
return a;  
}


/************************************************************************************************************************/
// Ustawia stan logiczny bitu o numerze "ktoryBit" w porcie o numerze "port" na wartosc "najakaWartosc"

void ustawBit(int port, unsigned char ktoryBit, unsigned char najakaWartosc)
{
	int maska;
	
		if (ktoryBit == 0) maska = 1;
		if (ktoryBit == 1) maska = 2;
		if (ktoryBit == 2) maska = 4;
		if (ktoryBit == 3) maska = 8;
		if (ktoryBit == 4) maska = 16;
		if (ktoryBit == 5) maska = 32;
		if (ktoryBit == 6) maska = 64;
		if (ktoryBit == 7) maska = 128;
	
	if (najakaWartosc)		outport(port, inport(port) | maska);
	else					outport(port, inport(port) & (~maska));
}


/************************************************************************************************************************/
// Sprawdza stan logiczny bitu o numerze "ktoryBit" w porcie o numerze "port"

unsigned char odczytajBit(int port, unsigned char ktoryBit)
{
	int maska;
	
		if (ktoryBit == 0) maska = 1;
		if (ktoryBit == 1) maska = 2;
		if (ktoryBit == 2) maska = 4;
		if (ktoryBit == 3) maska = 8;
		if (ktoryBit == 4) maska = 16;
		if (ktoryBit == 5) maska = 32;
		if (ktoryBit == 6) maska = 64;
		if (ktoryBit == 7) maska = 128;

	if (inport(port) & maska)	return 1;
	else						return 0;
}


/************************************************************************************************************************/

