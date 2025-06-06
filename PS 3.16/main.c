#include <stdio.h> // Necesario para printf y scanf

int main() {
    int N; // Variable para almacenar el número ingresado por el usuario
    int i, j; // Variables para los bucles de control

    printf("--- Generador de Figuras Numericas ---\n");

    // Solicitar al usuario que ingrese un número entero positivo
    printf("Ingrese un numero entero positivo (N): ");
    scanf("%d", &N);

    // --- Validar la entrada ---
    if (N <= 0) {
        printf("Error: Por favor, ingrese un numero entero positivo.\n");
        return 1; // Salir con un código de error
    }

    // --- Parte Ascendente de la Figura ---
    // Este bucle controla las filas, desde 1 hasta N
    for (i = 1; i <= N; i++) {
        // Este bucle controla los números a imprimir en cada fila
        // Imprime números desde 1 hasta el valor actual de 'i'
        for (j = 1; j <= i; j++) {
            printf("%d ", j); // Imprime el número y un espacio
        }
        printf("\n"); // Al final de cada fila, salta a una nueva línea
    }

    // --- Parte Descendente de la Figura ---
    // Este bucle controla las filas, desde N-1 hacia abajo hasta 1
    // Empezamos en N-1 para no repetir la fila mas larga (la de N)
    for (i = N - 1; i >= 1; i--) {
        // Este bucle controla los números a imprimir en cada fila
        // Imprime números desde 1 hasta el valor actual de 'i'
        for (j = 1; j <= i; j++) {
            printf("%d ", j); // Imprime el número y un espacio
        }
        printf("\n"); // Al final de cada fila, salta a una nueva línea
    }

    printf("\nFin del programa.\n");

    return 0; // Terminar el programa exitosamente
}
