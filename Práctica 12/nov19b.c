  #include<stdio.h>

//Prototipo de funciones
void * memcpy(void * destination, const void * source, size_t num);
int memcmp (const void *ptr1, const void * ptr2, size_t num);
void * memset(void * ptr, int value, size_t num);
void * memchr (const void * ptr, int value, size_t num);
char *strcpy(char *destination, const char*source);
char * strncpy ( char * destination, const char * source, size_t num );
char * strcat ( char * destination, const char * source);
int strcmp ( const char * str1, const char * str2 );
int strcmpi ( const char * str1, const char * str2 );
char * strstr(char * str1, const char *str2);
int strlen(const char * str1);

//Funcion principal
int main()
{
    char string1[10];
    char string2[10];
    const char string3[10] ="Hello";
    const char string4[10] ="hellO there";
    char string5[10];
    char string6[30] ="Modifica esta oracion";
    const char string7[30] ="Realizar busqueda en esta oracion";

    strcpy(string1,"sangre");
    printf("String1: %s",string1);

    strncpy(string2,"Hello",10);
    printf("\nString2: %s",string2);

    printf("\nString concatenado: %s",strcat(string2,"BLABLABLA"));

    printf("\nString length: %d",strlen(string3));

    printf("\nString compare: %d",strcmp(string3,string4));

    printf("\nString compare i: %d",strcmpi(string3,string4));

    printf("\nString string: %d",strstr(string2,string3));

    memcpy(string5,string4,8);
    printf("\nMemcpy: %s",string5);

    printf("\nMemcmp: %d",memcmp(string3,string4,5));

    memset(string6,'$', 5);
    printf("\nMemset: %s",string6);

    printf("\nPrimer caracter: %p",&string7);
    printf("\nEncontrado en la direccion: %p",memchr(string7,'h',10));

    return 0;
}

/*Funcion que copia los valores de un numero definido de bytes
 desde una locacion inicial hasta una locacion destino*/
void * memcpy(void * destination, const void * source, size_t num)
{
    int i=0;
    //Declaracion de la copia de los apuntadores
    char * cdestination = (char*)destination;
    const char * csource = (const char*)source;
    for(i=0;i<num;i++)
    {
        cdestination[i] = csource[i];
    }
    cdestination[num]='\0';
    destination = cdestination;
}

/*Funcion que compara dos bloques de memoria acotados por
un numero de bytes */
int memcmp (const void *ptr1, const void * ptr2, size_t num)
{
    int i=0,cont1=0,cont2=0;
    const char * cptr1 = (char*)ptr1;
    const char * cptr2 = (char*)ptr2;

    do{
        cont1+= cptr1[i];
        cont2+= cptr2[i];
        i++;
    }while(i<num);

    if(cont1==cont2){return 0;}
    else if(cont1>cont2){return 1;}
    else if (cont2>cont1){return -1;}
}

/*Funcion que asigna un valor a un bloque de memoria
acotado por un determinado numero de bytes*/
void * memset(void * ptr, int value, size_t num)
{
    int i;
    char * ptr2 = (char*)ptr;
    for(i=0;i<num;i++)
    {
       ptr2[i] = value;
    }
    ptr = ptr2;
}

/*Funcion que busca un caracter dentro de un determinado
bloque de memoria acotado por un determinado numero de bytes*/
void * memchr (const void * ptr, int value, size_t num)
{
    int i=0,encontrado=0;
    const char * ptr2 = (const char*)ptr;
    do
    {
        if (ptr2[i] == value)
        {
            encontrado=1;
            return &ptr2[i];
            //break;
        }
        i++;
    }while(i<num && encontrado==0);

    if(i==num && encontrado==0)
    {
        return 0;
    }
}

/*Funcion que copia una cadena de caracteres a otra*/
char *strcpy(char *destination, const char*source)
{
    int i=0;
    //Ciclo que copia cada caracter de la cadena al variable destino
    //hasta llegar al fin de cadena
    do
    {
        destination[i] = source[i];
        i++;
    } while(source[i]!='\0');
    destination[i] = '\0';
}

/*Funcion que copia los primeros num cantidad de caracteres
de la cadena fuente a la cadena destino*/
char * strncpy ( char * destination, const char * source, size_t num )
{
    int i=0;
   //Ciclo que copia cada caracter
    do
    {
        if(num<i) { destination[i] = '0'; }
            else { destination[i] = source[i]; }
        i++;
    } while(source[i]!='\0');
    destination[i] = '\0';
}

/*Funcion que concatena una cadea a otra cadena destino*/
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

/*Funcion que compara dos cadenas de caracteres hasta el
caracter de fin de cadena*/
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

/*Funcion que compara dos cadenas de caracteres hasta el
caracter de fin de cadena. No distingue entre mayusculas
y minusculas*/
int strcmpi (const char * str1, const char * str2)
{
    int cont1=0,cont2=0,num1=0,num2=0;

    do{cont1++;}while(str1[cont1]!='\0');
    do {cont2++;}while(str2[cont2]!='\0');

    if(cont1==cont2){return 0;}
    else if(cont1>cont2){return 1;}
    else if (cont2>cont1){return -1;}
}

/*Funcion que busca una coincidencia de la cadena str2
en la cadena str1,y regrese la direccion de memoria donde
se encontro la coincidencia
*/
char * strstr(char * str1, const char *str2)
{
    int i=0;
    do
    {
        if(str1[i]==str2[i]){return &str1[i];}
        i++;
    }while(str1[i]!='\0' || str2[i]!='\0');
}

//Funcion que cuenta el numero de caracteres de una cadena
int strlen(const char * str1)
{
    int size=0;
    //Ciclo que cuenta los caracteres hasta que llegar al fin de cadena
    do
    {
      size++;
    } while(str1[size]!='\0');
    return size;
}
