/*
Practica 9 Repaso de apuntadores
Programa elaborado por Reyes Udasco Rachelle Nerie
Objetivo: Ordenar los registros de un archivo de acuerdo a sus diferentes campos

PREGUNTAS
-¿Qué configuración de apuntadores se requerirían para constituir la lista de
elementos a ordenar?
Para ordenar los elementos de los registros se necesita guardar los valores en un arreglo de apuntadores de tipo struct

-¿Cómo sería el prototipo de la función swap?
void swap(void *a, void *b,unsigned int size);

-¿Cómo sería el prototipo de la función compare?
int comparar(const void *a, const void *b);

-¿Cómo sería el prototipo de la función bubbleSort?
void bubbleSort(void* array, int n, int size,int(*cmp)(const void*, const void*));

-¿Cuáles son las diferencias en cuanto al proceso de ordenamiento en el
ejemplo de la práctica 8 y en esta solución?
-En la práctica 8 trabaja directamente con archivos
-En la práctica 9 se hace un ordenamiento en memoria, es decir
guardando cada registro en un arreglo, compararlos y ordenarlos intercambiando las memorias.

-Ventajas y deventajas
a. En qué situaciones sería más apropiado hacer el ordenamiento
directamente sobre el archivo.
Cuando se desea ordenar los registros y guardarlos en el mismo archivo
b. En qué situaciones sería más apropiado hacer el ordenamiento en
memoria.
En situaciones en las cuales necesitamos ver los registros ordenados de
acuerdo al campo que queremos sin alterar el archivo original.
*/
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "bubblesort.h"
#define CLEAR() system("CLS")

struct date
{
  int dia;
  int mes;
  int anio;
};

//Definicion de la estructura del anuncio
typedef struct Anuncio_
{
  int numero;
  char clasificacion[15];
  char responsable[20];
  char telefono[11];
  char contenido[100];
  struct date fecha;
}Anuncio;

//Prototipo de funciones
int tamano();
void lectura(Anuncio *anuncioPtr);
void imprimiranuncio(Anuncio *anuncioPtr, int);
void swap(void *a, void *b,unsigned int size);
void bubbleSort(void* array, int n, int size,int(*cmp)(const void*, const void*));
int compararA_num(const void *a, const void *b);
int compararA_clas(const void *a, const void *b);
int compararA_res(const void *a, const void *b);
int compararA_tel(const void *a, const void *b);
int compararA_cont(const void *a, const void *b);
int compararA_fecha(const void *a, const void *b);
void imprimiranuncios(Anuncio *anuncioPtr, int);
void pausa();
void grabar(Anuncio *anuncioPtr,int);
void mostrar();
void imprimir(Anuncio registro);
char imprimirmenu();
void elegiropcion(Anuncio *anuncioPtr, int, char);

int main(void)
{
    Anuncio *anuncioPtr;
    int tam;
    tam = tamano();
    anuncioPtr = malloc(tam*sizeof(Anuncio));
    lectura(anuncioPtr);
    char opcion;

    do
    {   CLEAR();
		
		opcion = imprimirmenu();

        //Comparacion de la opcion elegida por el usuario
		elegiropcion(anuncioPtr, tam, opcion);
		
    }while (opcion!=48);

    free(anuncioPtr);

    return 0;
}

//Impresion del menu
char imprimirmenu()
{
	char opc;
	
	puts("1) Ordenar por numero de anuncio");
	puts("2) Ordenar por clasficacion");
	puts("3) Ordenar por responsable");
	puts("4) Ordenar por telefono");
	puts("5) Ordenar por contenido");
	puts("6) Ordenar por fecha");
	puts("7) Imprimir anuncios");
	puts("8) Guardar en archivo");
	puts("9) Abrir archivo ordenado");
	puts("0) Salir");
	printf("Opcion:");
	setbuf(stdin, 0);
	opc=getchar();
	
	return opc;
}

void elegiropcion(Anuncio *anuncioPtr, int tam, char opc)
{
	switch(opc)
	{
		case '1':   bubbleSort(anuncioPtr,tam,sizeof(Anuncio),compararA_num); break;
		case '2':   bubbleSort(anuncioPtr,tam,sizeof(Anuncio),compararA_clas); break;
		case '3':   bubbleSort(anuncioPtr,tam,sizeof(Anuncio),compararA_res); break;
		case '4':   bubbleSort(anuncioPtr,tam,sizeof(Anuncio),compararA_tel); break;
		case '5':   bubbleSort(anuncioPtr,tam,sizeof(Anuncio),compararA_cont); break;
		case '6':   bubbleSort(anuncioPtr,tam,sizeof(Anuncio),compararA_fecha); break;
		case '7':   imprimiranuncios(anuncioPtr,tam);
					pausa(); break;
		case '8':   grabar(anuncioPtr,tam); break;
		case '9':   mostrar();
					pausa(); break;

	}
}


//Funcion que realiza una pausa
void pausa()
{
    setbuf(stdin,0);
    getchar();
}

//Funcion que imprime los anuncios
void imprimiranuncios(Anuncio *anuncioPtr, int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        imprimiranuncio(anuncioPtr,i);
    }
}

//Funcion que cuenta cuantos registros hay en el archivo
int tamano()
{
    FILE * flujo;
    Anuncio registro;
    int tamano=0;

    flujo= fopen("registros.dat","rb");
    if (flujo)
    {
        while((fread(&registro,sizeof(Anuncio),1,flujo)>0)&& !feof(flujo))
        {
            tamano++;
        }
        fclose(flujo);
    }
    return tamano;
}

//Funcion que lee los registros del archivo
void lectura(Anuncio *anuncioPtr)
{
    FILE * flujo;
    Anuncio registro;
    int size =0;

    flujo= fopen("registros.dat","rb");
    if (flujo)
    {
        while((fread(&registro,sizeof(Anuncio),1,flujo)>0)&& !feof(flujo))
        {
            anuncioPtr[size].numero = registro.numero;
            strcpy(anuncioPtr[size].clasificacion,registro.clasificacion);
            strcpy(anuncioPtr[size].responsable,registro.responsable);
            strcpy(anuncioPtr[size].telefono,registro.telefono);
            strcpy(anuncioPtr[size].contenido,registro.contenido);
            anuncioPtr[size].fecha.anio = registro.fecha.anio;
            anuncioPtr[size].fecha.mes = registro.fecha.mes;
            anuncioPtr[size].fecha.dia = registro.fecha.dia;
            imprimiranuncios(anuncioPtr,size);
            size++;
        }
        fclose(flujo);
    }
}

//Funcion que imprime un anuncio en especifico
void imprimiranuncio(Anuncio *anuncioPtr, int registro)
{
    printf("%d\n",anuncioPtr[registro].numero);
    printf("%s\n",anuncioPtr[registro].clasificacion);
    printf("%s\n",anuncioPtr[registro].responsable);
    printf("%s\n",anuncioPtr[registro].telefono);
    printf("%s\n",anuncioPtr[registro].contenido);
    printf("%d/%d/%d\n",anuncioPtr[registro].fecha.dia,anuncioPtr[registro].fecha.mes,anuncioPtr[registro].fecha.anio);
    printf("\n");
}


//Funcion que compara los registros de acuerdo a su numero
int compararA_num(const void *a, const void *b)
{
    //Asigna todos los valores que contiene la estructura
    Anuncio anuncioA = *(Anuncio*)a;
    Anuncio anuncioB = *(Anuncio*)b;
    return anuncioA.numero-anuncioB.numero;
}

//Funcion que compara los registros de acuerdo a su clasficacion
int compararA_clas(const void *a, const void *b)
{
    //Asigna todos los valores que contiene la estructura
    Anuncio anuncioA = *(Anuncio*)a;
    Anuncio anuncioB = *(Anuncio*)b;
    return strcmp(anuncioA.clasificacion, anuncioB.clasificacion);
}

//Funcion que compara los registros de acuerdo a su responsable
int compararA_res(const void *a, const void *b)
{
    //Asigna todos los valores que contiene la estructura
    Anuncio anuncioA = *(Anuncio*)a;
    Anuncio anuncioB = *(Anuncio*)b;
    return strcmp(anuncioA.responsable, anuncioB.responsable);
}

//Funcion que compara los registros de acuerdo a su telefono
int compararA_tel(const void *a, const void *b)
{
    //Asigna todos los valores que contiene la estructura
    Anuncio anuncioA = *(Anuncio*)a;
    Anuncio anuncioB = *(Anuncio*)b;
    return strcmp(anuncioA.telefono, anuncioB.telefono);
}

//Funcion que compara los registros de acuerdo a su contenido
int compararA_cont(const void *a, const void *b)
{
    //Asigna todos los valores que contiene la estructura
    Anuncio anuncioA = *(Anuncio*)a;
    Anuncio anuncioB = *(Anuncio*)b;
    return strcmp(anuncioA.contenido, anuncioB.contenido);
}

//Funcion que compara los registros de acuerdo a su fecha
int compararA_fecha(const void *a, const void *b)
{
    //Asigna todos los valores que contiene la estructura
    Anuncio anuncioA = *(Anuncio*)a;
    Anuncio anuncioB = *(Anuncio*)b;
    return ((anuncioA.fecha.anio)*10000+(anuncioA.fecha.mes)*100+(anuncioA.fecha.dia))-((anuncioB.fecha.anio)*10000+(anuncioB.fecha.mes)*100+(anuncioB.fecha.dia));
}

//Funcion que graba el arreglo ordenado de acuerdo a un campo en especifico
void grabar(Anuncio *anuncioPtr,int size)
{
    FILE * flujo;
    char nombre[10];
    int i=0;
    printf("Ingrese el nombre del archivo(sin extension): ");
    setbuf(stdin, 0);
    gets(nombre);

    flujo=fopen(strcat(nombre,".dat"),"wb");

    if (flujo!=NULL)
    {
        for(i=0;i<size;i++)
        {
            fwrite((anuncioPtr+i),sizeof(Anuncio),1,flujo);
        }

    }
    else
        printf("No se pudo abrir");
    fclose(flujo);
}

//Funcion que imprime registros
void imprimir(Anuncio registro)
{
    printf("\n Numero: %d",registro.numero);
    printf("\n Clasificacion: %s", registro.clasificacion);
    printf("\n Responsable: %s",registro.responsable);
    printf("\n Telefono: %s",registro.telefono);
    printf("\n Contenido: %s",registro.contenido);
    printf("\n Fecha: %d/%d/%d",registro.fecha.dia,registro.fecha.mes,registro.fecha.anio);
}

void mostrar()
{
    FILE * flujo;
    Anuncio registro;
    int cont=0;
    char nombre[10];
    printf("Ingrese el nombre del archivo que deseas leer: ");
    setbuf(stdin, 0);
    gets(nombre);

    flujo= fopen(strcat(nombre,".dat"),"rb");
    if (flujo)
    {
        while(fread(&registro,sizeof(Anuncio),1,flujo)>0)
        {
            printf("\n\n  Registro No. %d\n", cont);
            imprimir(registro);
            pausa();
            cont++;
        }
    }
    fclose(flujo);
}
