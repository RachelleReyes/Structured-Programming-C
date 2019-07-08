//bits.c
/* Práctica 13: Elaborado por Reyes Udasco Rachelle Nerie*/
#include<stdio.h>
#include<stdlib.h>
#include "bits.h"

/*Funcion que imprime el valor de un numero de forma binaria*/
void display(unsigned int valor)
{
    unsigned int mask= 0x80000000;
    int i,j=0,imprimir=0;
    for(i=0;i<(sizeof(int))*8;i++)
    {
            j++;
            if (valor&mask){imprimir=1;}

            if (imprimir==1)
            {
                if (valor&mask) { putchar('1');}
                    else{ putchar('0');}

                if(j==4){printf(" ");}
            }
        mask = mask >>1;
        if(j==4){j=0;}
    }
    printf("\n");
}

/*Funcion que establece el valor 0 en un determiado bit(en la
posicion pos) de un numero entero(valor) */
int clearbit(unsigned int valor, unsigned int pos)
{
    valor = valor&~(1<<(pos-1));
    return valor;
}

/*Funcion que establece el valor 1 en un determiado bit(en la
posicion pos) de un numero entero(valor) */
int setbit(unsigned int valor, unsigned int pos)
{
    valor = valor|(1<<(pos-1));
    return valor;
}

/*Funcion que regresa el valor en un determiado bit (en la
posicion pos) de un numero entero (valor) */
unsigned char getbit(unsigned int valor, unsigned int pos)
{
    unsigned char bit;
    if (valor&(1<<(pos-1))) {bit = '1'; }
        else { bit = '0';}
        return bit;
}

/*Funcion que intercambia el valor de un determinado
bit (en la posicion pos) de un numero entero (valor)*/
unsigned int togglebit(unsigned int valor, unsigned int pos)
{
    valor = valor^(1<<(pos-1));
    return valor;
}

/*Funcion que rota a la derecha un determinado numero de locaciones
(definido por loc) de un numero (valor)*/
unsigned int introtright(unsigned int valor, unsigned int loc)
{
    valor = (valor>>loc)|(valor<<(sizeof(int)*8-loc));
    return valor;
}

/*Funcion que rota a la izquierda un determinado numero de locaciones
(definido por loc) de un numero (valor)*/
unsigned int introtleft(unsigned int valor, unsigned int loc)
{
    valor = (valor<<loc)|(valor>> (sizeof(int)*8-loc));
    return valor;
}

/*Funcion que rota a la derecha un determinado numero de locaciones
(definido por loc) de un byte (valor)*/
unsigned char byterotright(unsigned char valor, unsigned char loc)
{
   int i;
   for(i=0;i<loc;i++)
   {
       if (valor&(1>>0x00))
        {
            valor = valor>>1;
            valor = setbit(valor,8);
        }
        else { valor = valor>>1;}
   }
    return valor;
}

/*Funcion que rota a la izquierda un determinado numero de locaciones
(definido por loc) de un byte (valor)*/
unsigned char byterotleft(unsigned char valor, unsigned char loc)
{
   int i;
   for(i=0;i<loc;i++)
   {
       if (valor&(0x80))
        {
            valor = valor<<1;
            valor = setbit(valor,1);
        }
        else { valor = valor<<1;}
   }
    return valor;
}

unsigned char getbyte(unsigned int valor, unsigned int pos)
{
    valor = valor&(1<<(pos-1));
    return valor;
}

/*Funcion que encripta un mensaje, empleando xor con una clave en especifico*/
void encrypt(char * mensaje, unsigned char clave)
{
    int i=0,j=0;
    char *modificado;
    do{ j++;}while(mensaje[j]!='\0');
    modificado = (char*)malloc(j*sizeof(char));
    do
    {
        modificado[i] = (mensaje[i])^(clave);
        printf("%c",modificado[i]);
        i++;
    }while(mensaje[i]!='\0');
}

///////////////////////////////EXTRAS/////////////////////////////////////////

/*Funcion que suma dos numeros en forma binaria*/
unsigned int add(unsigned int num1, unsigned int num2)
{
    int sobra;
    /*Ciclo que procesa la suma de los dos numeros(termina cuando el
    segundo numero es cero*/
    while (num2!=0)
    {
        sobra = (num1&num2) <<1;
        num1 = num1^num2;
        num2 = sobra;
    }
    return num1;
}

/*Funcion que convierte un numero positivo a negativo*/
unsigned int complemento2(unsigned int valor)
{
    int complemento;
    complemento = add(~valor,1);
    return complemento;
}

/*Funcion que resta dos numeros en forma binaria*/
unsigned int sub(unsigned int num1, unsigned int num2)
{
    int sobra;

    //Usa la funcion de complemento2 para convertir el numero a negativo
    num2 = complemento2(num2);

    /*Ciclo que procesa la resta de los dos numeros(termina cuando el
    segundo numero es cero*/
    while (num2!=0)
    {
        sobra = (num1&num2) <<1;
        num1 = num1^num2;
        num2 = sobra;
    }
    return num1;
}
