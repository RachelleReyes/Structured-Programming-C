#ifndef MISTRING
#define MISTRING
/*Práctica 12: Elaborado por Reyes Udasco Rachelle Nerie*/

void * memcpy(void *, const void *,size_t);
int memcmp (const void *, const void *, size_t);
void * memset(void *, int, size_t);
void * memchr (const void * , int, size_t );
char *strcpy(char *, const char *);
char * strncpy ( char *, const char * , size_t);
char * strcat ( char * , const char *);
int strcmp ( const char * , const char * );
int strcmpi ( const char *, const char * );
char * strstr(char * , const char *);
int strlen(const char * );

#endif