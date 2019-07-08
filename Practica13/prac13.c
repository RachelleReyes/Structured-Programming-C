/*Práctica 13: Elaborado por Reyes Udasco Rachelle Nerie
El objetivo de este programa es comprobar las funciones de la biblioteca bits realizada

Conclusion: Para realizar esta practica, fue necesario emplear los operadores de bits aprendidos en clase, 	
			analizando cuidadosamente el objetivo de cada una de las funciones a realizar. 
*/

//Bibliotecas
#include<stdio.h>
#include"bits.h"

int main()
{
    //PRUEBA DE FUNCIONES

    //DISPLAY
    printf("Numero: 2304");
    printf("\nDisplay: ");
    display(2304);

    //SETBIT
    printf("\nNumero: 5, Posicion: 3");
    printf("\nSetbit: %d",setbit(5,3));

    //CLEARBIT
    printf("\n\nNumero: 6, Posicion: 1");
    printf("\nClearbit: %d",clearbit(6,1));

    //GETBIT
    printf("\n\nNumero: 155, Posicion: 7");
    printf("\nGetbit: %c",getbit(155,7));

    //TOGGLEBIT
    printf("\n\nNumero: 6, Posicion: 4");
    printf("\nTogglebit: %d",togglebit(6,4));

    //INT ROTRIGHT
    printf("\n\nInt rotright (decimal): %u",introtright(1,1));
    printf("\nInt rotright (binario): ");
    display(introtright(0x80000000,4));

    //INT ROTLEFT
    printf("\nInt rotleft (decimal): %u",introtleft(0x80000000,4));
    printf("\nInt rotleft (binario): ");
    display(introtleft(0x80000000,4));

    //BYTE ROTRIGHT
    printf("\nByte to right (decimal): %d",byterotright(1,1));
    printf("\nByte to right (binario): ");
    display(byterotright(1,1));

    //BYTE ROTLEFT
    printf("\nByte to left(decimal): %d",byterotleft(128,1));
    printf("\nByte to left (binario): ");
    display(byterotleft(128,1));

    //GETBYTE
    printf("\nNumero: 35, Posicion: 7");
    printf("\nGetbyte: %d",getbyte(35,7));

    //ENCRYPT
    char mensaje[100] = "Este es un mensaje regular";
    printf("\n\nMensaje original: %s, clave: A",mensaje);
    printf("\nMensaje encriptado: ");
    encrypt(mensaje,'A');

    //////////////////EXTRAS////////////////////

    //SUMA
    printf("\n\nNum1: 10, Num2: 34");
    printf("\nSuma: %d",add(10,34));
    //COMPLEMENTO2
    printf("\n\nNum: 43");
    printf("\nComplemento: %d",complemento2(43));
    //RESTA
    printf("\n\nNum1: 100, Num2: 30");
    printf("\nResta: %d",sub(100,30));
    printf("\n");\

    return 0;
}