#ifndef SILNIKKROKOWY_H
#define SILNIKKROKOWY_H



#define Port 0x378
#define Port2 0x379
#define Port3 0x37A

void zerujWyjsciaLPT1();

void silnikKrokowy0123H378 (unsigned char kierunek, int liczbaKrokow, int zwloka=0);
void silnikKrokowy4567H378 (unsigned char kierunek, int liczbaKrokow, int zwloka=0);
void silnikKrokowy0123H37A (unsigned char kierunek, int liczbaKrokow, int zwloka=0);

void silnikKrokowy012H378 (unsigned char kierunek, int liczbaKrokow, int zwloka0=0, int zwloka1=0);
void silnikKrokowy345H378 (unsigned char kierunek, int liczbaKrokow, int zwloka0=0, int zwloka1=0);
void silnikKrokowy678H378 (unsigned char kierunek, int liczbaKrokow, int zwloka0=0, int zwloka1=0);

void luzujSilnikKrokowy012H378();
void luzujSilnikKrokowy345H378();
void luzujSilnikKrokowy678H378();
void zalaczSilnikKrokowy012H378();
void zalaczSilnikKrokowy345H378();
void zalaczSilnikKrokowy678H378();


void szukajPunktBazowyX();
void szukajPunktBazowyY();
void szukajPunktBazowyZ();

int sprawdzIleX();
int sprawdzIleY();
int sprawdzIleZ();


unsigned char stanLiniX();
unsigned char stanLiniY();
unsigned char stanLiniZ();

unsigned char sprawdzPrzyciskStop();
unsigned char sprawdzPrzyciskStart();
void czekajDoWcisnieciaStart();


void docieranieX();
void docieranieY();
void docieranieZ();


#endif