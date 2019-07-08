 #include<stdio.h>

//Prototipo de funciones
void comparar(int valor);
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
    const char string1[50]="Esta funcion sirve para copiar";
    char string2[50];
    const char string3[30] ="Primera oracion";
    const char string4[30] ="Segundaa oracion";
    char string5[100] ="Modifica esta oracion";
    const char string6[50] ="Realizar busqueda en esta oracion";
    char string7[30];
    char string8[50];


   //MEMCPY
    memcpy(string2,string1,18);
    printf("\na.) MEMCPY");
    printf("\nCadena copiado: %s",string2);

   //MEMCMP
    printf("\n\nb.) MEMCMP");
    printf("\nCadena comparado: %d",memcmp(string3,string4,10));
    comparar(memcmp(string3,string4,10));

    //MEMSET
    printf("\n\nc.) MEMSET");
    printf("\nCadena original: %s",string5);
    memset(string5,'$', 5);
    printf("\nCadena modificada: %s",string5);

    //MEMCHR
    printf("\n\nd.) MEMCHR");
    printf("\nCadena: %s",string6);
    printf("\nDireccion del primer caracter: %p",&string6);
    printf("\nLetra 'e' encontrado en la direccion: %p",memchr(string6,'e',10));

    //STRCPY
    printf("\n\ne.) STRCPY");
    strcpy(string7,"Copia esta oracion");
    printf("\nString copiado: %s",string7);

    //STRNCPY
    printf("\n\nf.) STRNCPY");
    strncpy(string8,string1,40);
    printf("\nString copiado: %s",string8);

    //STRCAT
    printf("\n\ng.) STRCAT");
    printf("\nString original: %s",string6);
    printf("\nString concatenado: %s",strcat(string6," agregando mas palabras"));

    //STRCMP
    printf("\n\nh.) STRCMP");
    printf("\nRevisar esta funcion");
    printf("\nCadenas comparadas: %d",strcmp(string3,string4));

    //STRCMPI
    printf("\n\ni.) STRCMPI");
    printf("\nCadenas comparadas: %d",strcmpi(string3,string4));
    comparar(strcmpi(string3,string4));

    //STRSTR
    printf("\n\nj.) STRSTR");
    printf("\nDireccion del primer string %p", &string3);
    printf("\nLas dos cadenas coinciden en: %p",strstr(string3,string4));

    //STRLEN
    printf("\n\nk.) STRLEN");
    printf("\nCadena %s", string3);
    printf("\nNumero de caracteres: %d\n",strlen(string3));

    return 0;
}

void comparar(int valor)
{
    switch(valor)
    {
        case 0: printf("\nSon iguales");
            break;
        case 1: printf("\nLa primera cadena es mayor");
            break;
        case -1: printf("\nLa segunda cadena es mayor");
            break;
    }
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
    //destination = cdestination;
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
        if(source[i]=='\0'){destination[i] = 0;}
        else {destination[i] = source[i];}
        i++;
    } while(num>=i);
}

/*Funcion que concatena una cadea a otra cadena destino*/
char * strcat ( char * destination, const char * source )
{
    int i=0,j=0;
    do
    {
        i++;
    } while(destination[i]!='\0');

     do
    {
        destination[i+j] = source[j];
        j++;
    }while(source[j]!='\0');
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
