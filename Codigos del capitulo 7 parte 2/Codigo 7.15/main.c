
#include <stdio.h>
#include <ctype.h>

/* Decodifica.
   El programa decodifica una cadena de caracteres compuesta por n�meros y letras. */

void interpreta(char *);  // Prototipo de funci�n
void main(void)
{
char cad[50];
printf("\nIngrese la cadena de caracteres: ");
gets(cad);
interpreta(cad);
}

void interpreta(char *cadena)
/* Esta funci�n se utiliza para decodificar la cadena de caracteres. */
{
    int i = 0, j, k;
    while (cadena[i] != '\0')
    {
        if (isalpha(cadena[i]))  // Si es una letra
        {
            k = cadena[i - 1] - 48;  // Convertir d�gito anterior (en ASCII) a n�mero
            for (j = 0; j < k; j++)
                putchar(cadena[i]);
        }
        i++;
    }
}
