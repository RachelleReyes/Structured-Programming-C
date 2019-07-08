/*Practica 11: Uso del campo de bits
Elaborado por Reyes Udasco Rachelle Nerie
Este programa tiene como objetivo leer el encabezado de una imagen bmp y desplegar informacion sobre ello
*/
/*PREGUNTAS
1. Ilustre​ ​la(s)​ ​estructuras​ ​utilizadas​ ​en​ ​este​ ​ejercicio
typedef struct
{
	unsigned char ID[2];
	unsigned int size;
    unsigned char reservado[4];
	unsigned int offset;
	unsigned int n_bits;
	unsigned int ancho;
	unsigned int altura;
	unsigned char colores[2];
	unsigned char bits_pixel[2];
	unsigned int bi_rgb;
	unsigned int bitmap;
	unsigned int res_horizontal;
	unsigned int res_vertical;
	unsigned int palette;
	unsigned int imp_colors;
}header;

2. ¿Por qué una estructura con los campos descritos en el encabezado no mide los 54 bytes calculados?
Porque 54 bytes no es un múltiplo del tamaño de los campos definidos en la estructura, lo cual es 4.
Una solucion podria ser usar tipo de dato char en todos los campos del encabezado, sin embargo
esto no funciona eficientemente al manipularlo para realizar la practica
typedef struct
{
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


3. ¿De qué forma se puede leer de forma correcta el archivo?
    //Declarando un apuntador File para abrir el archivo, lo cual es una imagen bmp
    FILE *file;
    //Usando rb con fopen
    file=fopen(nombre,"rb");
	if (!file)
	{
		printf("\nError al abrir la imagen");
		exit(1);
	}

4. ¿Qué soluciones se proponen para almacenar el encabezado en una estructura?

	//Ir recorriendo el archivo con fread para guardar los valores en un registro de la estructura
	fread(&image->sizebmp,sizeof(int),1,file);

5. Proponga un procedimiento para escribir en otro archivo el mismo encabezado pero​ ​con​ ​ciertas​ ​modificaciones.
Crear un nuevo archivo e imprimir el encabezado guardado en la estructura con fprintf
Enseguida dar una opcion para editar los campos con las modificaciones que se desea hacer

Conclusion:
La parte más difícil de esta práctica fue averiguar cómo meter adecuadamente los valores en la estructura de 54 bytes,
por ende, opte por usar una estructura de 56 bytes, lo cual tiene datos de tipo int y char.

*/

#include <stdio.h>
#include <stdlib.h>

//Estructura en donde se almacenara el encabezado de la imagen
typedef struct
{
	unsigned char ID[2];
	unsigned int size;
    unsigned char reservado[4];
	unsigned int offset;
	unsigned int n_bits;
	unsigned int ancho;
	unsigned int altura;
	unsigned char colores[2];
	unsigned char bits_pixel[2];
	unsigned int bi_rgb;
	unsigned int bitmap;
	unsigned int res_horizontal;
	unsigned int res_vertical;
	unsigned int palette;
	unsigned int imp_colors;
}header;

//Funciones prototipos
void abrir_img(header *imagen, char *nombre);
void imprimirdatos(header *image);

int main()
{
	//Declaracion de variables
	header imagen;	//Variable para guardar los valores del encabezado de la primera imagen
	header imagen2;	//Variable para guardar los valores del encabezado de la segunda imagen

    //printf("El tamanio de la estructura es: %d\n\n",sizeof(header));

	printf("Primera imagen");
    abrir_img(&imagen,"ejemplo.bmp");
	imprimirdatos(&imagen);

	printf("Segunda imagen");
	abrir_img(&imagen2,"ejemplo2.bmp");
	imprimirdatos(&imagen2);
    return 0;
}

//Funcion que imprime el ID, tamanio, ancho y largo de la imagen
void imprimirdatos(header *image)
{
    printf("\nID: %.2s",image->ID);
	printf("\nTamanio: %d", image->size);
	printf("\nAncho: %d ", image->ancho);
	printf("\nLargo: %d \n\n", image->altura);

}

//Funcion que abre la imagen
void abrir_img(header *image, char *nombre)
{
	//Definicion de un apuntadores de tipo FILE
    FILE *file;
    file=fopen(nombre,"rb");

	//Abre la imagen que el usuario eligio
	if (!file)
	{
		printf("\nError al abrir la imagen");
		exit(1);
	}
	//Lee el archivo y guarda el encabezado en la estructura
	fseek(file,0,SEEK_SET);
	fread(&image->ID,sizeof(char),2,file);
	fread(&image->size,sizeof(int),1,file);
	fread(&image->reservado,sizeof(int),1,file);
	fread(&image->offset,sizeof(int),1,file);
	fread(&image->n_bits,sizeof(int),1,file);
	fread(&image->ancho,sizeof(int),1,file);
	fread(&image->altura,sizeof(int),1,file);
	fread(&image->colores,sizeof(char),2,file);
	fread(&image->bits_pixel,sizeof(char),2,file);
	fread(&image->bi_rgb,sizeof(int),1,file);
	fread(&image->bitmap,sizeof(int),1,file);
	fread(&image->res_horizontal,sizeof(int),1,file);
	fread(&image->res_vertical,sizeof(int),1,file);
	fread(&image->palette,sizeof(int),1,file);
	fread(&image->imp_colors,sizeof(int),1,file);

	//Comparacion para ver si la imagen es un bitmap
	if(image->ID[0]!='B'||image->ID[1]!='M'){
		printf("\nLa imagen debe ser un bitmap.");
		exit(1);
    }
	//Cierra los archivos
	fclose(file);
}
