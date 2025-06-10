#include <stdio.h> // Para printf y scanf
#include <stdbool.h> // Para usar el tipo 'bool' (C99)
#include <math.h> // Para usar sqrt() para optimizaci�n

// Funci�n para verificar si un n�mero es primo
// Retorna true si es primo, false si no lo es
bool esPrimo(int numero) {
    if (numero <= 1) {
        return false; // N�meros menores o iguales a 1 no son primos
    }
    // Optimizaci�n: solo necesitamos verificar divisores hasta la ra�z cuadrada del n�mero
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false; // Si encontramos un divisor, no es primo
        }
    }
    return true; // Si no encontramos ning�n divisor, es primo
}

int main() {
    int NUM;

    printf("--- Numeros Primos Menores que un Numero Dado ---\n");
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &NUM);

    // Validar la entrada
    if (NUM <= 2) {
        printf("No hay numeros primos menores que %d.\n", NUM);
        return 0; // Termina el programa
    }

    printf("\nNumeros primos menores que %d:\n", NUM);

    // Iterar desde 2 hasta NUM-1 y verificar si cada n�mero es primo
    for (int i = 2; i < NUM; i++) {
        if (esPrimo(i)) {
            printf("%d ", i);
        }
    }
    printf("\nFin del programa.\n");

    return 0;
}
