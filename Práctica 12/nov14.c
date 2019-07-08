#include<stdio.h>
//#include<stdlib.h>

char *strcpy(char *destination, const char*source);
char * strncpy ( char * destination, const char * source, size_t num );
int strcmp ( const char * str1, const char * str2 );
int strcmpi ( const char * str1, const char * str2 );
char * strcat ( char * destination, const char * source);
int strlen(const char * str1);
char * strstr(char * str1, const char *str2);
void * memcpy(void * destination, const void * source, size_t num);

//srtlen
int main()
{
    char string1[10];
    char string2[10];
    char string3[10] ="Hello";
    char string4[10] ="hellO";
    char string5[10];

    strcpy(string1,"sangre");
    printf("String1: %s",string1);

    strncpy(string2,"Hello",10);
    printf("\nString2: %s",string2);

    printf("\nString concatenado: %s",strcat(string2,"BLABLABLA"));

    printf("\nString length: %d",strlen(string3));

    printf("\nString compare: %d",strcmp(string3,string4));

    printf("\nString compare i: %d",strcmpi(string3,string4));

    printf("\nString string: %d",strstr(string2,string3));

    printf("\nMemcpy: %d",memcpy(string5,string4,strlen(string4)+1));


    return 0;
}

int strlen(const char * str1)
{
    int size=0;
    do
    {
        size++;
    } while(str1[size]!='\0');

    return size;
}

char *strcpy(char *destination, const char*source)
{
    int i=0;
    do
    {
        destination[i] = source[i];
        i++;
    } while(source[i]!='\0');
    destination[i] = '\0';
}

char * strncpy ( char * destination, const char * source, size_t num )
{
    int i=0;
    do
    {
        if(num<i) { destination[i] = '0'; }
            else { destination[i] = source[i]; }
        i++;
    } while(source[i]!='\0');
    destination[i] = '\0';
}

char * strcat ( char * destination, const char * source )
{
    int i=0,j=0;
    do
    {
        if(destination[i]=='\0')
        {
            do
            {
                destination[i+j] = source[j];
                j++;
            }while(source[j]!='\0');
        }
        i++;
    } while(source[j]!='\0');

}

int strcmp (const char * str1, const char * str2)
{
    int cont1=0,cont2=0,num1=0,num2=0,i=0,diferente=0;

    do
    {
        num1+= str1[cont1];
        cont1++;
    }while(str1[cont1]!='\0');
    do
    {
        num2+= str2[cont2];
        cont2++;
    }while(str2[cont2]!='\0');
    do
    {
       if(str1[i]!=str2[i])
       {
           diferente =1;
       }
        i++;
    }while(str1[i]!='\0' && str2[i]!='\0');

    if(num1==num2 && diferente==0)
    {
        return 0;
    }
    else if(num1>num2)
    {
        return 1;
    }
    else if (num2>num1)
    {
         return -1;
    }
    else
    {
        do
        {
           if(str1[i]!=str2[i])
           {
               diferente =1;
           }
            i++;
        }while(str1[i]!='\0' && str2[i]!='\0');

        return 23;
    }

/*
    int c = 0;

   while (a[c] == b[c]) {
      if (a[c] == '\0' || b[c] == '\0')
         break;
      c++;
   }

   if (a[c] == '\0' && b[c] == '\0')
      return 0;
   else if (a[c] == '\0')
      return 1;
   else if (b[c] == '\0')
        return -1;
*/
}


int strcmpi (const char * str1, const char * str2)
{
    int cont1=0,cont2=0,num1=0,num2=0;

    do{cont1++;}while(str1[cont1]!='\0');
    do {cont2++;}while(str2[cont2]!='\0');

    if(cont1==cont2){return 0;}
    else if(cont1>cont2){return 1;}
    else if (cont2>cont1){return -1;}
}

char * strstr(char * str1, const char *str2)
{
    int i=0;
    do
    {
        if(str1[i]==str2[i]){return &str1[i];}
        i++;
    }while(str1[i]!='\0' || str2[i]!='\0');
}

void * memcpy(void * destination, const void * source, size_t num)
{
    int i=0;
    char * cdestination = (char*)destination;
    const char * csource = (const char*)source;
    for(i=0;i<num;i++)
    {
        destination2[i] = source2[i];
    }

    do
    {
        if(num<i) { destination2[i] = '\0'; }
            else { ; }
        i++;
    } while(source2[i]!='\0');

    *destination = *(void*)destination2;

}


