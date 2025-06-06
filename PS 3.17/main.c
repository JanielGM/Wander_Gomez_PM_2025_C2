#include <stdio.h> // Necesario para printf y scanf

int main() {
    int N; // Variable para almacenar el numero ingresado por el usuario
    int i, j; // Variables para los bucles de control

    printf("--- Generador de Patrones Numericos Piramidales ---\n");

    // Solicitar al usuario que ingrese un numero entero positivo
    printf("Ingrese un numero entero positivo (N): ");
    scanf("%d", &N);

    // --- Validar la entrada ---
    if (N <= 0) {
        printf("Error: Por favor, ingrese un numero entero positivo.\n");
        return 1; // Salir con un codigo de error
    }

    // --- Bucle principal para controlar las filas ---
    // 'i' representa el numero de la fila actual y el numero mas alto en esa fila
    for (i = 1; i <= N; i++) {
        // --- Parte Ascendente de la fila ---
        // Imprime numeros desde 1 hasta 'i'
        for (j = 1; j <= i; j++) {
            printf("%d ", j); // Imprime el numero y un espacio
        }

        // --- Parte Descendente de la fila ---
        // Imprime numeros desde 'i-1' hacia abajo hasta 1
        // Si i es 1, este bucle no se ejecuta (j = 0, no <= 1)
        for (j = i - 1; j >= 1; j--) {
            printf("%d ", j); // Imprime el numero y un espacio
        }

        printf("\n"); // Al final de cada fila, salta a una nueva linea
    }

    printf("\nFin del programa.\n");

    return 0; // Terminar el programa exitosamente
}
