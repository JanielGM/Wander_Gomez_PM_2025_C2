#include <stdio.h>
/* Maximo comun divisor.
El programa, al recibir como datos dos numeros enteros, calcula el maximo comun divisor de dichos numeros. */
int mod(int, int);

void main(void)
{
    int NU1, NU2, RES;
    printf("\nIngresa los dos numeros enteros: ");
    scanf("%d %d", &NU1, &NU2);
    RES = mod(NU1, NU2);
    printf("\nEl maximo comun divisor de %d y %d es: %d", NU1, NU2, RES);
}

int mod(int N1, int N2)
/* Esta funcion calcula el maximo comun divisor de los numeros N1 y N2. */
{
    int I;
    if (N1 < N2)
        I = N1 / 2;
    else
        I = N2 / 2;
    /* I se inicializa con el maximo valor posible que puede ser divisor de N1 y N2. */
    while ((N1 % I) || (N2 % I))
    /* El ciclo se mantiene activo mientras (N1 % I) o (N2 % I) sean distintos de cero. Cuando el resultado de la evaluacion sea 0, el ciclo se detiene ya que se habr� encontrado el m�ximo com�n divisor. */
        I--;
    return I;
}
