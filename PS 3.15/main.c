#include <stdio.h> // Para printf y scanf

int main() {
    int N1, N2; // Números de entrada
    int temp;   // Variable temporal para intercambios y para almacenar el resto

    printf("--- Calculadora del Maximo Comun Divisor (MCD) ---\n");

    // Solicitar e ingresar los dos números
    printf("Ingrese el primer numero natural (N1): ");
    scanf("%d", &N1);
    printf("Ingrese el segundo numero natural (N2): ");
    scanf("%d", &N2);

    // Validar que los números sean naturales (positivos)
    if (N1 <= 0 || N2 <= 0) {
        printf("Error: Por favor, ingrese numeros naturales (positivos).\n");
        return 1; // Salir con código de error
    }

    // Algoritmo de Euclides
    // Paso 1: Asegurar que N1 sea el mayor (o igual) para simplificar el bucle
    if (N2 > N1) {
        temp = N1;
        N1 = N2;
        N2 = temp;
    }

    // Bucle principal del Algoritmo de Euclides
    // Continúa mientras N2 no sea cero
    while (N2 != 0) {
        temp = N1 % N2; // Calcular el resto de la división de N1 entre N2
        N1 = N2;        // El antiguo N2 se convierte en el nuevo N1
        N2 = temp;      // El resto se convierte en el nuevo N2
    }

    // Cuando el bucle termina, N1 contiene el MCD
    printf("\nEl Maximo Comun Divisor (MCD) es: %d\n", N1);

    printf("\nFin del programa.\n");

    return 0; // Terminar el programa exitosamente
}
