#include<stdio.h>
#include<string.h>

//srtlen
int main()
{
    char string1[10];
    char string2[10];
    const char string3[10] ="Hello";
    const char string4[10] ="hellO";
    char string5[10];
    char string6[30] ="Modify this sentence";
    const char string7[30] ="Search this sentence";

    strcpy(string1,"sangre");
    printf("String1: %s",string1);

    strncpy(string2,"Hello",10);
    printf("\nString2: %s",string2);

    printf("\nString concatenado: %s",strcat(string2,"BLABLABLA"));

    printf("\nString length: %d",strlen(string3));

    printf("\nString compare: %d",strcmp(string3,string4));

    printf("\nString compare i: %d",strcmpi(string3,string4));

    printf("\nString string: %p",strstr(string2,string3));

    memcpy(string5,string4,2);
    string5[2]=0;
    printf("\nMemcopy: %s",string5);

    printf("\nMemcmp: %d",memcmp(string3,string4,5));

    printf("\nPrimer caracter: %p",&string7);
    printf("\nEncontrado en la direccion: %p",memchr(string7,'h',10));


    return 0;
}
