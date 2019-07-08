#include <stdio.h>
#include <stdlib.h>

struct test
{
    int a:8;
    int b:8;
    int c:8;
    int d:8;
};

struct Disk
{
    int booteable:1;
    int solo_lectura:1;
    int direcciones:5;
    int ocupado:1;
};


int main ()
{
    printf("Tamaño estructura test %d",sizeof(struct test));
    printf("\nTamaño estructura Disk %d",sizeof(struct Disk));
    return 0;
}
