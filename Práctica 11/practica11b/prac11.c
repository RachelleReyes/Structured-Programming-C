/*Practica 11: Uso del campo de bits
Elaborado por Reyes Udasco Rachelle Nerie
Este programa tiene como objetivo leer el encabezado de una imagen bmp y desplegar informacion sobre ello
*/

/*PREGUNTAS
1. Ilustre la(s) estructuras utilizadas en este ejercicio
    typedef struct{
        unsigned char ID[2];
        unsigned char size[4];
        unsigned char reservado[4];
        unsigned char offset[4];
        unsigned char n_bits[4];
        unsigned char ancho[4];
        unsigned char altura[4];
        unsigned char colores[2];
        unsigned char bits_pixel[2];
        unsigned char bi_rgb[4];
        unsigned char bitmap[4];
        unsigned char res_horizontal[4];
        unsigned char res_vertical[4];
        unsigned char palette[4];
        unsigned char imp_colors[4];
    }header;

2. Por que una estructura con los campos descritos en el encabezado no mide los 54 bytes calculados?
    Porque 54 bytes no es un múltiplo del tamaño de los campos definidos en la estructura, lo cual es 4.

3. De que forma se puede leer de forma correcta el archivo?
    //Declarando un apuntador File para abrir el archivo, lo cual es una imagen bmp
    FILE *archivo;
    //Usando rb con fopen
    archivo=fopen("ejemplo.bmp","rb");
	if (!archivo)
	{
		printf("\nError al abrir la imagen");
		exit(1);
	}

4. Que soluciones se proponen para almacenar el encabezado en una estructura?
	//Usar fread para guardar los valores en un registro de la estructura
     fread(&img1,sizeof(img1),1,archivo);

5. Proponga un procedimiento para escribir en otro archivo el mismo encabezado pero con ciertas modificaciones.
   Crear un nuevo archivo e imprimir el encabezado guardado en la estructura con fprintf
   Enseguida dar una opcion para editar los campos con las modificaciones que se desea hacer

Conclusion:
    La parte más difícil de esta práctica fue averiguar como tener 54 bytes en la estructura
    y poder imprimir los valores correctamente de los campos solicitados en esta practica.
*/

#include <stdio.h>

//Definicion de la estructura para el encabezado
typedef struct{
	unsigned char ID[2];
	unsigned char size[4];
	unsigned char reservado[4];
	unsigned char offset[4];
	unsigned char n_bits[4];
	unsigned char ancho[4];
	unsigned char altura[4];
	unsigned char colores[2];
	unsigned char bits_pixel[2];
	unsigned char bi_rgb[4];
	unsigned char bitmap[4];
	unsigned char res_horizontal[4];
	unsigned char res_vertical[4];
	unsigned char palette[4];
	unsigned char imp_colors[4];
}header;

//Funciones prototipo
void recorrerestructura(header imagen, int *tamanio, int *ancho, int *largo);
void imprimirdatos(header imagen, int tamanio, int ancho, int largo);

//Funcion principal
int main()
{
    //Declaracion de variables
     header img1;
     header img2;
     FILE *archivo;
     FILE *archivo2;
     int tamanio, ancho, largo;

     //Lectura de las dos imagenes
     archivo=fopen("ejemplo.bmp","rb");
     archivo2=fopen("ejemplo2.bmp","rb");

     //Se sale del programa si no abre los archivos
    if (!archivo || !archivo2)
    {
        printf("\nError al abrir la imagen");
        exit(1);
    }

     //Imprime el tamanio de la estructura
     printf("Tamanio de la estructura: %d\n",sizeof(header));

     //Guarda los encabezados de la imagen
     fread(&img1,sizeof(img1),1,archivo);
     fread(&img2,sizeof(img2),1,archivo2);

     //Datos de la primera imagen
     printf("\nPrimera imagen");
     recorrerestructura(img1,&tamanio,&ancho,&largo);
     imprimirdatos(img1,tamanio,ancho,largo);

     //Datos de la segunda imagen
     printf("\n\nSegunda imagen");
     recorrerestructura(img2,&tamanio,&ancho,&largo);
     imprimirdatos(img2,tamanio,ancho,largo);

     printf("\n\n");
     fclose(archivo);
     fclose(archivo2);

     return 0;
}

//Funcion que recorre el registro de la estructura
void recorrerestructura(header imagen, int *tamanio, int *ancho, int *largo)
{
    int i;
    *tamanio=0;
    *ancho=0;
    *largo=0;

    //Recorre cada caracter guardando en los campos de la estrucura
    for(i=3;i>=0;i--)
     {
         //Almacena los valores de cada campo en una variable
         *tamanio+= imagen.size[i];
         *ancho+= imagen.ancho[i];
         *largo+= imagen.altura[i];

         //Recorre los valores de la variable para dar lugar al valor siguiente
         if (i!=0)
         {
            *tamanio = *tamanio<<8;
            *ancho = *ancho<<8;
            *largo = *largo<<8;
         }
     }
}

//Funcion que imprime los datos de la imagen
void imprimirdatos(header imagen, int tamanio, int ancho, int largo)
{
 	 printf("\nID: %c%c",imagen.ID[0],imagen.ID[1]);
     printf("\nTamanio: %d bytes",tamanio);
     printf("\nAncho: %d pixeles",ancho);
     printf("\nLargo: %d pixeles",largo);
}
