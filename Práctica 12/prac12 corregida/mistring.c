//mistring.c
/* Práctica 12: Elaborado por Reyes Udasco Rachelle Nerie*/
#include<stdio.h>
#include "mistring.h"

/*Funcion que copia los valores de un numero definido de bytes
 desde una locacion inicial hasta una locacion destino*/
void * memcpy(void * destination, const void * source, size_t num)
{
    int i=0;
    //Declaracion de la copia de los apuntadores
    char * cdestination = (char*)destination;
    const char * csource = (const char*)source;

    for(i=0;i<num;i++)
    {
        cdestination[i] = csource[i];
    }
    cdestination[num]='\0';
	return 0;
}

/*Funcion que compara dos bloques de memoria acotados por un numero de bytes */
int memcmp (const void *ptr1, const void * ptr2, size_t num)
{
    int i=0,cont1=0,cont2=0;
    const char * cptr1 = (char*)ptr1;
    const char * cptr2 = (char*)ptr2;

    do{
        cont1+= cptr1[i];
        cont2+= cptr2[i];
        i++;
    }while(i<num);

    if(cont1>cont2){return 1;}
    else if (cont2>cont1){return -1;}
    else{return 0;}
}

/*Funcion que asigna un valor a un bloque de memoria
acotado por un determinado numero de bytes*/
void * memset(void * ptr, int value, size_t num)
{
    int i;
    char * ptr2 = (char*)ptr;
    for(i=0;i<num;i++)
    {
       ptr2[i] = value;
    }
    ptr = ptr2;
	return 0;
}

/*Funcion que busca un caracter dentro de un determinado
bloque de memoria acotado por un determinado numero de bytes*/
void * memchr (const void * ptr, int value, size_t num)
{
	int i=0,encontrado=0;
    char * ptr2 = (char*)ptr;
	char * direccion;
    do
    {
        if (ptr2[i] == value)
        {
            encontrado=1;
			direccion = &ptr2[i];
        }
		
        i++;
    }while(i<num && encontrado==0);
	
	  if (ptr2[i-1] == value)
        {
			return direccion;
        }
	else return 0;
}

/*Funcion que copia una cadena de caracteres a otra*/
char *strcpy(char *destination, const char*source)
{
    int i=0;
    //Ciclo que copia cada caracter de la cadena al variable destino
    //hasta llegar al fin de cadena
    do
    {
        destination[i] = source[i];
        i++;
    } while(source[i]!='\0');
    destination[i] = '\0';
	return 0;
}

/*Funcion que copia los primeros num cantidad de caracteres
de la cadena fuente a la cadena destino*/
char * strncpy ( char * destination, const char * source, size_t num )
{
    int i=0;
   //Ciclo que copia cada caracter
    do
    {
        if(source[i]=='\0'){destination[i] = 0;}
        else {destination[i] = source[i];}
        i++;
    } while(num>=i);
	return 0;
}

/*Funcion que concatena una cadea a otra cadena destino*/
char * strcat ( char * destination, const char * source )
{
    int i=0,j=0;
    do
    {
        i++;
    } while(destination[i]!='\0');

     do
    {
        destination[i+j] = source[j];
        j++;
    }while(source[j]!='\0');
	return 0;
}

/*Funcion que compara dos cadenas de caracteres hasta el caracter de fin de cadena*/
int strcmp (const char * str1, const char * str2)
{
    int cont1=0,cont2=0,i=0,diferente=0, diferente1=0, diferente2=0;

    do{ cont1++; }while(str1[cont1]!='\0');
    do{ cont2++; }while(str2[cont2]!='\0');
    do
    {
       if(str1[i]!=str2[i])
       {
           diferente1= str1[i];
           diferente2= str2[i];
           diferente=1;
       }
        i++;
    }while(diferente==0);

    if(cont1==cont2)
    {
        if(diferente==0){return 0;}
        else if(diferente1>diferente2){return 1;}
        else{return -1;}
    }
    else if(cont1>cont2){ return 1;}
    else{ return -1;}
}

/*Funcion que compara dos cadenas de caracteres hasta el caracter de fin
de cadena. No distingue entre mayusculas y minusculas*/
int strcmpi (const char * str1, const char * str2)
{
    int cont1=0,cont2=0;

	//Ciclo que cuenta el numero de caracteres de cada cadena
    do{cont1++;}while(str1[cont1]!='\0');
    do {cont2++;}while(str2[cont2]!='\0');
	
    if(cont1>cont2){return 1;}
    else if (cont2>cont1){return -1;}
	else{return 0;}

}

/*Funcion que busca una coincidencia de la cadena str2 en la cadena str1,
y regrese la direccion de memoria donde se encontro la coincidencia
*/
char * strstr(char * str1, const char *str2)
{
    int i=0,j=0,encontrado=0;
   
	do
	{
		do
		{
			if(str2[j]==str1[i]){encontrado =i;}
			i++;
		}while(str1[i]!='\0' && encontrado==0);
		j++;
		i=0;
	}while(str2[j]!='\0' && encontrado==0);

	return &str1[encontrado];
}

//Funcion que cuenta el numero de caracteres de una cadena
int strlen(const char * str1)
{
    int size=0;
    //Ciclo que cuenta los caracteres hasta que llegar al fin de cadena
    do
    {
      size++;
    } while(str1[size]!='\0');
    return size;
}
