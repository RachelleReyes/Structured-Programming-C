#ifndef BITS
#define BITS
/*Práctica 13: Elaborado por Reyes Udasco Rachelle Nerie*/

void display(unsigned int valor);
int clearbit(unsigned int valor, unsigned int pos);
int setbit(unsigned int valor, unsigned int pos);
unsigned char getbit(unsigned int valor, unsigned int pos);
unsigned int togglebit(unsigned int valor, unsigned int pos);
unsigned int introtright(unsigned int valor, unsigned int loc);
unsigned int introtleft(unsigned int valor, unsigned int loc);
unsigned char getbyte(unsigned int valor, unsigned int pos);
unsigned char byterotright(unsigned char valor, unsigned char loc);
unsigned char byterotleft(unsigned char valor, unsigned char loc);
void encrypt(char * mensaje, unsigned char clave);
unsigned int add(unsigned int num1, unsigned int num2);
unsigned int complemento2(unsigned int valor);
unsigned int sub(unsigned int num1, unsigned int num2);

#endif