#include <stdio.h> // Necesario para printf y scanf

int main() {
    int N; // Variable para almacenar el numero de filas (N)
    int i; // Bucle para controlar las filas (desde 1 hasta N)
    int j; // Bucle para controlar los numeros dentro de cada fila
    int current_num; // Almacena el numero actual a imprimir en la fila

    printf("--- Generador de Patrones Numericos Especiales ---\n");

    // Solicitar al usuario que ingrese el numero de filas (N)
    // El ejemplo muestra 10 filas, pero el programa sera flexible.
    printf("Ingrese el numero de filas (N) para la figura: ");
    scanf("%d", &N);

    // --- Validar la entrada ---
    // Aseguramos que N sea un numero entero positivo.
    if (N <= 0) {
        printf("Error: Por favor, ingrese un numero entero positivo.\n");
        return 1; // Salir con un codigo de error
    }

    // --- Bucle principal para controlar las filas ---
    // 'i' representa el numero de la fila actual (1-indexed).
    // Tambien es el numero con el que comienza cada fila.
    for (i = 1; i <= N; i++) {
        current_num = i; // Cada fila comienza con su numero de fila 'i'

        // --- Parte Ascendente de la fila ---
        // Imprime 'i' numeros, desde 'i' hasta el pico.
        for (j = 1; j <= i; j++) {
            printf("%d ", current_num % 10); // Imprime el digito (modulo 10)
            current_num++;                   // Incrementa para el siguiente numero
        }

        // --- Parte Descendente de la fila ---
        // El 'current_num' ahora esta en 'pico + 1'.
        // Necesitamos retroceder 2 para empezar desde 'pico - 1'.
        // Ejemplo: si pico es 5, current_num es 6. Queremos empezar a imprimir 4.
        current_num -= 2;

        // Imprime 'i - 1' numeros, desde (pico - 1) hacia abajo hasta 'i'.
        for (j = 1; j <= i - 1; j++) {
            printf("%d ", current_num % 10); // Imprime el digito (modulo 10)
            current_num--;                   // Decrementa para el siguiente numero
        }

        printf("\n"); // Al final de cada fila, salta a una nueva linea
    }

    printf("\nFin del programa.\n");

    return 0; // Terminar el programa exitosamente
}
