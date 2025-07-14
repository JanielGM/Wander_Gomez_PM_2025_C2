#include <stdio.h>

/* Cadena invertida resuelta en forma recursiva. */
void inverso(char *);             /* Prototipo de funci�n. */

void main(void)
{
    char fra[50];
    printf("\nIngrese la linea de texto: ");
    gets(fra);
    printf("\nEscribe la linea de texto en forma inversa: ");
    inverso(fra);
}

void inverso(char *cadena)

/* La funci�n inverso obtiene precisamente el inverso de la cadena. La soluci�n
presentada es simple, pero para comprenderla es necesario tener conocimientos
tanto de pilas como de recursividad. */
{
    if(cadena[0] != '\0')
    {
        inverso(&cadena[1]);
        putchar(cadena[0]);
    }
}
