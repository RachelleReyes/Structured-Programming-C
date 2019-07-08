/*Práctica 13: Elaborado por Reyes Udasco Rachelle Nerie
El objetivo de este programa es encriptar un archivo
*/
//Bibliotecas
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include"bits.h"

//Prototipo de funciones
void detener_pantalla(char* mensaje);
void informacion_err();
void lectura(char * archivo, char * encriptado,unsigned char clave);

int main(int argc, char* argv[])
{
    //declaracion de variables a utilizar
    int num = 0;
	
	//EXTRA
	clock_t start = clock();
	
    //Comprobacion de numero de parametros ingresados por consola
    if(argc<3)
    {
        informacion_err();
        detener_pantalla("\n\tPresione ENTER para salir");
        return 1;
    }
    else
    {
        num = atoi(argv[2]);
		//Comparacion si es un numero de 8 bits
       if(num>0 && num<255)
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
	
	printf("\n Tiempo transcurrido: %f",((double)clock()-start)/CLOCKS_PER_SEC);
    return 0;
}

//Funcion que detiene la pantalla
void detener_pantalla (char* mensaje)
{
    printf("\n%s\n", mensaje);
    setbuf(stdin, NULL);
    getchar();
}

//Funcion que muestra un mensaje de error
void informacion_err()
{
    printf("El programa debe recibir dos parametros obligatorios, y otro opcional");
    printf("\n   [1] Nombre del archivo que se va a encriptar");
    printf("\n   [2] Clave (numero de 8 bits)");
	printf("\n   [3] Nombre del archivo de salida (archivo encriptado)");
    printf("\n\nEjemplo:\n ultimateEncrypt.exe archivo 148 encriptado ");
}

//Funcion que lee el archivo
void lectura(char * archivo, char * encriptado,unsigned char clave)
{
	//Declaracion de variables a utilizar
	FILE * file1, * file2;
	int i=0,j=0;
	char contenido[500];
	
	//Abre los archivos
    file1 = fopen(archivo,"rb");
	if (encriptado!=NULL){file2 = fopen(encriptado,"wb");}
		else { encriptado = strcat(archivo, ".crypt");
			file2 = fopen(encriptado,"wb");}

	//Comparacion si los dos archivos fueron abiertos
	 if (file1 && file2) 
    {
		while (!feof(file1))
		{	
			contenido[i] = fgetc(file1);
			i++;
		}

		//LLama la funcion para encriptar el  mensaje
		encrypt(contenido,clave);
		printf("Mensaje encriptado: ");
		puts(contenido);

		//Imprime el contenido en el archivo
		while (j<i)
			{	
				fputc(contenido[j],file2);
				j++;
			}
	
    }
	//Cierra los dos archivos
	  fclose(file1);
	  fclose(file2);
}