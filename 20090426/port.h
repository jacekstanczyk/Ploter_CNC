#ifndef PORT_H
#define PORT_H


void outport (unsigned int port, unsigned char co);
unsigned char inport (unsigned int port);
void ustawBit(int port, unsigned char ktorybit, unsigned char najakawartosc);
unsigned char odczytajBit(int port, unsigned char ktorybit);


#endif