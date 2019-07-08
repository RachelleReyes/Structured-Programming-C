#include<stdio.h>
#include<string.h>

int main()
{
const char string1[50]="Esta funcion sirve para copiar";
    char string2[50];
    const char string3[30] ="Primera oracion";
    const char string4[30] ="Segundaaaa oracion";
    char string5[30] ="Modifica esta oracion";
    const char string6[50] ="Realizar busqueda en esta oracion";
    char string7[30];
    char string8[30];


   //MEMCPY
    memcpy(string2,string1,18);
    printf("\na.) MEMCPY");
    printf("\nCadena copiado: %s",string2);

   //MEMCMP
    printf("\n\nb.) MEMCMP");
    printf("\nCadena comparado: %d",memcmp(string3,string4,10));
    switch(memcmp(string3,string4,10))
    {
        case 0: printf("\nSon iguales");
            break;
        case 1: printf("\nLa primera cadena es mayor");
            break;
        case -1: printf("\nLa segunda cadena es mayor");
            break;
    }

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
    strncpy(string8,string1,60);
    printf("\nString copiado: %s",string8);

    return 0;
}
