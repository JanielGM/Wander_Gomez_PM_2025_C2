#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Minusculas y mayusculas.
   El programa, al recibir como dato un arreglo unidimensional de tipo
   cadena de caracteres, determina el n�mero de min�sculas y may�sculas
   que hay en cada cadena. */

void minymay(char *cadena);  // Prototipo de funci�n.

void main(void)
{
    int i, n;
    char FRA[20][50]; // Arreglo de cadenas de caracteres

    printf("\nIngrese el n�mero de filas del arreglo: ");
    scanf("%d", &n);
    getchar(); // Limpia el buffer despu�s del scanf

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la l�nea %d de texto: ", i + 1);
        fgets(FRA[i], sizeof(FRA[i]), stdin);
        FRA[i][strcspn(FRA[i], "\n")] = '\0';  // Elimina el salto de l�nea
    }

    printf("\n\n");
    for (i = 0; i < n; i++)
        minymay(FRA[i]);


}

void minymay(char *cadena)
{
    int i = 0, mi = 0, ma = 0;

    while (cadena[i] != '\0')
    {
        if (islower(cadena[i]))
            mi++;
        else if (isupper(cadena[i]))
            ma++;
        i++;
    }

    printf("\nN�mero de letras min�sculas: %d", mi);
    printf("\nN�mero de letras may�sculas: %d\n", ma);
}
