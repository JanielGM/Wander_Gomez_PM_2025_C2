#include <stdio.h>
#include <ctype.h>

/* Verifica.
   El programa, al recibir como datos una cadena de caracteres y una posici�n espec�fica en la cadena,
   determina si el caracter correspondiente es una letra min�scula.   */

void main(void)
{
    char p, cad[50];
    int n;

    printf("\nIngrese la cadena de caracteres (m�ximo 50): ");
    gets(cad);  // Usando gets() como pediste (aunque est� obsoleto)

    printf("\nIngrese la posici�n en la cadena que desea verificar: ");
    scanf("%d", &n);

    if ((n >= 1) && (n <= 50))  // Posicion v�lida (1 a 50)
    {
        p = cad[n - 1];  // Se resta 1 para convertir a �ndice (0-based)
        if (islower(p))
            printf("\n%c es una letra minuscula", p);
        else
            printf("\n%c no es una letra minuscula", p);
    }
    else
    {
        printf("\nEl valor ingresado de n es incorrecto");
    }
}
