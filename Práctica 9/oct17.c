#include<stdio.h>
#include<string.h>

//Es necesario mandar el tamaño de cada dato = int size
void bubbleSort(void* array, int n, int size,int(*cmp)(const void*, const void*));
int comparar(const void *a, const void *b);
void swap(void *, void *, unsigned int);
void printArray(int* array, int n);
int compararAlumnos(const void*a, const void*b);

typedef struct Alumno_
{
    char nombre[10];
    int edad;
}Alumno;

int main(void)
{
    /*int array[] = {1,9,-1,5,7,8,3,7,5,2,6,8,8,9,7,6}; //16 elementos
    int n = sizeof(array)/sizeof(array[0]); //No aplica en memoria dinamica
    //int i,j;
    printArray(array, n);
    bubbleSort(array, n, sizeof(int),comparar);
    printArray(array, n);
    */

    Alumno alumnos[3];
    strcpy(alumnos[0].nombre,"Homer");
    alumnos[0].edad =35;
    strcpy(alumnos[1].nombre,"Raul");
    alumnos[1].edad =26;
    strcpy(alumnos[2].nombre,"Draven");
    alumnos[2].edad =29;

    printAlumnos(alumnos,3);
    bubbleSort(alumnos,3,sizeof(Alumno),compararAlumnos);
    printAlumnos(alumnos,3);
    return 0;
}
int comparar(const void *a, const void *b)
{
    return (*(int*)a- *(int*)b);
}

//Intercambia byte por byte
//unsigned int size / tamaño de las variables
void swap(void *a, void *b,unsigned int size)
{
    int i;
    //Para tener tamaño de un byte
    unsigned char aux;

    for(i=0;i<size;i++)
    {
        aux = *(unsigned char*)(a+i);
        *(unsigned char*)(a+i) = *(unsigned char*)(b+i);
        *(unsigned char*)(b+i)=aux;
    }
}

void bubbleSort(void* array, int n, int size,int(*cmp)(const void*, const void*))
{
    int i,j;
    for(i=0; i<n-1;i++)
    {
        for(j=i+1; j<n;j++)
        {
            //Multiplica la direccion por el tamaño del dato
            if(cmp((array+i*size),(array+j*size))>0)
            swap(array+i*size,array+j*size,size);
        }
    }
}

void printArray(int* array, int n)
{
    int i;
    printf("\n");
    for(i=0; i<n; i++)
        printf(" [%d]:%d ",i, array[i]);
    printf("\n");
}

int compararAlumnos(const void *a, const void *b)
{
    //Asigna todos los valores que contiene la estructura
    Alumno alumnoA = *(Alumno*)a;
    Alumno alumnoB = *(Alumno*)b;
    return alumnoA.edad-alumnoB.edad;
}

void printAlumnos(Alumno* array,int n)
{
    int i;
    printf("\n");
    for(i=0; i<n; i++)
    {
        printf("Alumno: %d",i);
        printf("\n");
        printf("Nombre: %s",array[i].nombre);
        printf("\n");
        printf("Edad: %d",array[i].edad);
        printf("\n");
    }
}
