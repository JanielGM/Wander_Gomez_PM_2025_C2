#include <stdio.h> // Necesario para printf y scanf

int main() {
    int N; // Almacena el número ingresado por el usuario (tamaño del patrón)
    int i, j, k; // Variables para los bucles de control

    printf("--- Generador de Patrones Numericos Simetricos ---\n");

    // Solicita al usuario que ingrese un número entero positivo
    printf("Ingrese un numero entero positivo (N): ");
    scanf("%d", &N);

    // --- Validar la entrada ---
    // Aseguramos que N sea un número positivo.
    if (N <= 0) {
        printf("Error: Por favor, ingrese un numero entero positivo.\n");
        return 1; // Sale del programa con un código de error.
    }

    // --- Bucle principal para controlar las filas ---
    // 'i' representa el número de la fila actual, desde 1 hasta N.
    for (i = 1; i <= N; i++) {
        // --- Parte Izquierda (Ascendente) ---
        // Este bucle imprime los números que suben.
        // El límite superior (N - i + 1) hace que la secuencia se acorte en cada fila.
        for (j = 1; j <= (N - i + 1); j++) {
            printf("%d ", j); // Imprime el número actual y un espacio.
        }

        // --- Espacios Centrales ---
        // Este bucle imprime los espacios en el centro.
        // La cantidad de espacios (2 * (i - 1)) aumenta con cada fila.
        // Se usan dos espacios "  " para mantener una buena alineación, ya que cada número ocupa "d ".
        for (k = 1; k <= 2 * (i - 1); k++) {
            printf("  ");
        }

        // --- Parte Derecha (Descendente) ---
        // Este bucle imprime los números que bajan, espejo de la parte izquierda.
        // Comienza desde el mismo número en el que terminó la parte izquierda y baja hasta 1.
        for (j = (N - i + 1); j >= 1; j--) {
            printf("%d ", j); // Imprime el número actual y un espacio.
        }

        printf("\n"); // Al final de cada fila, salta a la siguiente línea.
    }

    printf("\nFin del programa.\n");

    return 0; // Termina el programa exitosamente.
}
