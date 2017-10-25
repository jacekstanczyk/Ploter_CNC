#ifndef KONWERTER_H
#define KONWERTER_H

#include "grafika.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

enum kom 
{
	IN=0,
	SP=1,
	PU=2,
	PD=3
};

int rysujPlik(char * nazwaPliku);
int przeliczPlik(char * nazwaPliku);


#endif