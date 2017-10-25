#ifndef KONWERTER_H
#define KONWERTER_H

#include "grafika.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

enum komenda
{
	IN=0,
	SP=1,
	PU=2,
	PD=3,
	PA=4,
	LT=5
};

enum pozycjaPiora
{
	Dol=0,
	Gora=1
};

int rysujPlikPLT(char * nazwaPliku);
int przeliczPlikPLT(char * nazwaPliku);
int przeliczWymiary(char * nazwaPliku);


#endif