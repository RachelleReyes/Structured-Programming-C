#include<stdio.h>
#include<string.h>

char *strcpy(char *destination, const char*source);

//srtlen
int main()
{
    char string1[10];
    char string2[10];
    char string3[10] ="HellO";
    char string4[10] ="Hello";

    //string3 = "HELLO";

    strcpy(string1,"blabla");
    printf("String1: %s",string1);

    strncpy(string2,"Hello ",10);
    printf("\nString2: %s",string2);

    printf("\nString concatenado %s",strcat(string2,"BLABLA"));

    printf("\n%d",strcmp(string1,string2));

    printf("\n%d",strlen(string3));
    printf("\n%d",strcmpi(string3,string4));


    return 0;
}
