//bubble_sort.c
/*
Ejemplo de implementación del algoritmo de ordenamiento burbuja de numeros enteros
Desarrollar un programa para ordenar cualquier tipo de dato
*/
#include<stdio.h>
#include<string.h>

void swap(int *a, int *b);
void printArray(int* array, int n);
int compare(const int a, const int b);
void bubbleSort(int* array, int n, int(cmp)(int, int));

int main(void)
{
    int array[] = {1,9,-1,5,7,8,3,7,5,2,6,8,8,9,7,6}; //16 elementos
    int n = sizeof(array)/sizeof(array[0]); //No aplica en memoria dinamica
    int i,j;
    printf("\nArray inicial: ");
    printArray(array, n);
    bubbleSort(array, n, compare);
    printf("\nArray ordenado: ");
    printArray(array, n);
    return 0;
}


void bubbleSort(int* array, int n, int(cmp)(int, int))
{
    int i,j;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if( cmp(array[i],array[j]) > 0)
            {
                printf("\n\n--------------------------\n");
                printArray(array, n);
                printf("\narray[%d]:%d > array[%d]:%d", i, array[i], j, array[j]);
                printf("\nANTES\n[%d]: %d, [%d]: %d", i, array[i], j, array[j]);
                swap(&array[i], &array[j]);
                printf("\nDESPUES\n[%d]: %d, [%d]: %d", i, array[i], j, array[j]);
                printArray(array, n);
                printf("\n--------------------------\n");
                getchar();
            }
        }
    }
}

void swap(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}


void printArray(int* array, int n)
{
    int i;
    printf("\n");
    for(i=0; i<n; i++)
        printf(" [%d]:%d ",i, array[i]);
    printf("\n");
}

int compare(const int a, const int b)
{
    return a-b;
}
