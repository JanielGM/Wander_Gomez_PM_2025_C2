#include <stdio.h>   // Para printf y scanf
#include <stdbool.h> // Para usar el tipo 'bool' (true/false)
#include <math.h>    // Para usar sqrt() en la optimización de esPrimo

// Función para verificar si un número es primo
// Retorna true si es primo, false si no lo es
bool esPrimo(int numero) {
    if (numero <= 1) {
        return false; // Números menores o iguales a 1 no son primos
    }
    // Optimización: solo necesitamos verificar divisores hasta la raíz cuadrada del número
    // Un número es primo si no tiene divisores aparte de 1 y él mismo.
    // Si un número tiene un divisor mayor que su raíz cuadrada,
    // también debe tener un divisor menor que su raíz cuadrada.
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false; // Si encontramos un divisor, no es primo
        }
    }
    return true; // Si no encontramos ningún divisor en el rango, es primo
}

int main() {
    int N1, N2;
    int contador_primos_gemelos = 0; // Para saber si encontramos alguno

    printf("--- Buscador de Primos Gemelos ---\n");
    printf("Ingrese el primer numero entero positivo (N1): ");
    scanf("%d", &N1);
    printf("Ingrese el segundo numero entero positivo (N2, N2 > N1): ");
    scanf("%d", &N2);

    // Validar la entrada
    if (N1 <= 0 || N2 <= 0 || N1 >= N2) {
        printf("Error: Por favor, ingrese dos numeros positivos donde N1 sea menor que N2.\n");
        return 1; // Salir con un código de error
    }

    printf("\nPrimos gemelos entre %d y %d:\n", N1, N2);

    // Iterar desde N1 hasta N2-2 (para que N2 pueda ser el segundo primo del par)
    for (int i = N1; i <= N2 - 2; i++) {
        // Si 'i' es primo Y 'i + 2' también es primo, entonces son primos gemelos
        if (esPrimo(i) && esPrimo(i + 2)) {
            printf("(%d, %d)\n", i, i + 2);
            contador_primos_gemelos++; // Incrementa el contador
        }
    }

    if (contador_primos_gemelos == 0) {
        printf("No se encontraron primos gemelos en el rango especificado.\n");
    }

    printf("\nFin del programa.\n");

    return 0; // Terminar el programa exitosamente
}
