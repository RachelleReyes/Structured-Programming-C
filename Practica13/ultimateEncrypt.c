/*Práctica 13: Elaborado por Reyes Udasco Rachelle Nerie
El objetivo de este programa es encriptar un archivo
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include"bits.h"

void detener_pantalla(char* mensaje);
void informacion_err();
void lectura(char * archivo, char * encriptado,unsigned char clave);

int main(int argc, char* argv[])
{
    //declaracion de variables a utilizar
    int num = 0;

    //comprobacion de numero de parametros ingresados por consola
    if(argc<3)
    {
        //Por defecto el programa recibe un argumento, el nombre del archivo (ej. practica2.c).
        informacion_err();
        detener_pantalla("\n\tPresione ENTER para salir");
        return 1;
    }
    else
    {
        num = atoi(argv[2]);
       if(argv[3]!=NULL)
	   {
		   lectura(argv[1],argv[3],num);
	   }
	   else if(argv[3]==NULL)
	   {
		   lectura(argv[1],argv[3],num);
	   }
        else
        {
            informacion_err();
            detener_pantalla("\n\tPresione ENTER para salir");
            return 1;
        }
    }
	
    detener_pantalla("\n\tPresione ENTER para salir");
	printf("Hello");
    return 0;
}

void detener_pantalla (char* mensaje)
{
    printf("\n%s\n", mensaje);
    setbuf(stdin, NULL);
    getchar();
}

void informacion_err()
{
    printf("El programa debe recibir dos parametros obligatorios, y otro opcional");
    printf("\n   [1] Nombre del archivo que se va a encriptar");
    printf("\n   [2] Clave (numero de 8 bits)");
	printf("\n   [3] Nombre del archivo de salida (archivo encriptado)");
    printf("\n\nEjemplo:\n ultimateEncrypt.exe archivo 148 encriptado ");
}


void lectura(char * archivo, char * encriptado,unsigned char clave)
{
	FILE * file1, * file2;
	//char caracter;
	char * contenido=NULL;
    file1 = fopen(strcat(archivo,".dat"),"rb");
	if(encriptado!=0) {file2 = fopen(strcat(encriptado,".dat"),"ab");}
		else {file2 = fopen(strcat(archivo,".crypt"),"ab");}
	/*
	 file1 = fopen(strcat(archivo,".txt"),"r");
	if(encriptado!=0) {file2 = fopen(strcat(encriptado,".txt"),"w+");}
		else {file2 = fopen(strcat(archivo,".crypt"),"w+");}
		*/
    if (file1 && file2) 
    {
		while(!feof(file1))
		{
			fread(contenido,10,1,file1);
			//caracter = fgetc(file1);
			encrypt(contenido,clave);
			fwrite(contenido,10,1,file2);
			printf("%s", contenido);
			//fputc(caracter,file2);
			//printf("%c",caracter);
		}
    }
    fclose(file1);
	fclose(file2);
}