#include<stdio.h>
#include<stdlib.h>

//void display(unsigned int valor);
int clearbit(unsigned int valor, unsigned int pos);
int setbit(unsigned int valor, unsigned int pos);
unsigned char getbit(unsigned int valor, unsigned int pos);
unsigned int togglebit(unsigned int valor, unsigned int pos);
unsigned int rotright(unsigned int valor, unsigned char loc);
/*unsigned int rotleft(unsigned int valor, int loc);
unsigned char byterotright(unsigned char valor, unsigned char loc);
unsigned char byterotleft(unsigned char valor, unsigned char loc);
*/

int main()
{
    unsigned int num;
/*
    //DISPLAY
    num = 12;
    display(num);
*/

    printf("Setbit: %d",setbit(5,3));
    printf("\nClearbit: %d",clearbit(6,1));
    //printf("\nGetbit: %c",getbit(6,1));
    printf("\nTogglebit: %d",togglebit(6,4));
    printf("\nRotright: %d",rotright(6,1));
    return 0;
}
/*
void display(unsigned int valor)
{
    int i=1;
    do
    {
        p
    }while(i<=8);

}*/

int clearbit(unsigned int valor, unsigned int pos)
{
    valor = valor&~(1<<pos-1);
    return valor;
}

int setbit(unsigned int valor, unsigned int pos)
{
    valor = valor|(1<<pos-1);
    return valor;
}
/*
unsigned char getbit(unsigned int valor, unsigned char pos)
{
    //valor = valor|~(1<<pos-1);
    valor = valor
    return valor;
}*/
unsigned int togglebit(unsigned int valor, unsigned int pos)
{
    valor = valor^(1<<pos-1);
    return valor;
}

unsigned int rotright(unsigned int valor, unsigned char loc)
{
    //valor = valor<<loc;

}
