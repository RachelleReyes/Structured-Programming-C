/*Práctica 12: Elaborado por Reyes Udasco Rachelle Nerie
El objetivo de este programa es comprobar las funciones de la biblioteca string realizada

Conclusion: Esta practica fue relativamente sencilla de realizar, me sirvio para practicar
todo lo visto en las clases
*/

//Bibliotecas
#include<stdio.h>
#include"mistring.h"

void comparar(int valor);

//Funcion principal
int main()
{
    //Declaracion de variables
    const char string1[50]="Esta funcion sirve para copiar";
    char string2[50];
    const char string3[30] ="Primera oracion";
    const char string4[30] ="Segunda oracion";
    char string5[100] = "Modifica esta oracion";
    const char string6[50] = "Realizar busqueda en esta oracion";
    char string7[30];
    char string8[50];


	/*PRUEBA PARA CADA UNA DE LAS FUNCIONES DE LA BIBLIOTECA REALIZADA*/
	
   //MEMCPY
    memcpy(string2,string1,18);
    printf("\na.) MEMCPY");
    printf("\nCadena copiado: %s",string2);

   //MEMCMP
    printf("\n\nb.) MEMCMP");
    printf("\nCadena comparado: %d",memcmp(string3,string4,10));
    comparar(memcmp(string3,string4,10));

    //MEMSET
    printf("\n\nc.) MEMSET");
    printf("\nCadena original: %s",string5);
    memset(string5,'$', 5);
    printf("\nCadena modificada: %s",string5);

    //MEMCHR
    printf("\n\nd.) MEMCHR");
    printf("\nCadena: %s",string6);
    printf("\nDireccion del primer caracter: %p",&string6);
    printf("\nLetra 'e' encontrado en la direccion: %p",memchr(string6,'e',10));

    //STRCPY
    printf("\n\ne.) STRCPY");
    strcpy(string7,"Copia esta oracion");
    printf("\nString copiado: %s",string7);

    //STRNCPY
    printf("\n\nf.) STRNCPY");
    strncpy(string8,string1,40);
    printf("\nString copiado: %s",string8);

    //STRCAT
    printf("\n\ng.) STRCAT");
    printf("\nString original: %s",string5);
    printf("\nString concatenado: %s",strcat(string5," agregando mas palabras"));

    //STRCMP
    printf("\n\nh.) STRCMP");
    printf("\nCadenas comparadas: %d",strcmp(string3,string4));
    comparar(strcmp(string3,string4));

    //STRCMPI
    printf("\n\ni.) STRCMPI");
    printf("\nCadenas comparadas: %d",strcmpi(string3,string4));
    comparar(strcmpi(string3,string4));

    //STRSTR
    printf("\n\nj.) STRSTR");
    printf("\nDireccion del primer string %p", &string3);
    printf("\nLas dos cadenas coinciden en: %p",strstr(string5,string4));

    //STRLEN
    printf("\n\nk.) STRLEN");
    printf("\nCadena: %s", string3);
    printf("\nNumero de caracteres: %d\n",strlen(string3));

    return 0;
}

//Funcion que compara el valor dado por las funciones de comparacion
void comparar(int valor)
{
    switch(valor)
    {
        case 0: printf("\nSon iguales");
            break;
        case 1: printf("\nLa primera cadena es mayor");
            break;
        case -1: printf("\nLa segunda cadena es mayor");
            break;
    }
}