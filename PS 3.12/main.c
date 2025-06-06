#include <stdio.h> // Para printf y scanf
#include <stdbool.h> // Para usar el tipo 'bool' (C99)
#include <math.h> // Para usar sqrt() para optimización

// Función para verificar si un número es primo
// Retorna true si es primo, false si no lo es
bool esPrimo(int numero) {
    if (numero <= 1) {
        return false; // Números menores o iguales a 1 no son primos
    }
    // Optimización: solo necesitamos verificar divisores hasta la raíz cuadrada del número
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false; // Si encontramos un divisor, no es primo
        }
    }
    return true; // Si no encontramos ningún divisor, es primo
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

    // Iterar desde 2 hasta NUM-1 y verificar si cada número es primo
    for (int i = 2; i < NUM; i++) {
        if (esPrimo(i)) {
            printf("%d ", i);
        }
    }
    printf("\nFin del programa.\n");

    return 0;
}
