#include <stdio.h> // Necesario para printf y scanf

int main() {
    int N; // Número de años

    printf("--- Calculadora de Produccion de Vino ---\n");
    printf("Ingrese el numero de anos para los que tiene datos de produccion: ");
    scanf("%d", &N);

    // Validar que N sea positivo
    if (N <= 0) {
        printf("Error: El numero de anos debe ser positivo.\n");
        return 1; // Salir con error
    }

    // Declaracion de la matriz (VLA) y arreglos para totales
    float vin[N][4]; // N años, 4 tipos de vino
    float total_por_anio[N]; // Para la produccion total de cada año
    float total_por_tipo[4] = {0.0, 0.0, 0.0, 0.0}; // Para la produccion total de cada tipo

    // Inicializar total_por_anio a cero (importante para acumular)
    for (int i = 0; i < N; i++) {
        total_por_anio[i] = 0.0;
    }

    // --- Entrada de Datos y Acumulacion de Totales ---
    printf("\n--- Ingrese las cantidades de litros de vino ---\n");
    for (int i = 0; i < N; i++) { // Bucle para los años
        printf("\n--- Año %d ---\n", i + 1);
        for (int j = 0; j < 4; j++) { // Bucle para los tipos de vino
            printf("  Cantidad de vino Tipo %d: ", j + 1);
            scanf("%f", &vin[i][j]);

            // Acumular directamente los totales mientras se leen los datos
            total_por_anio[i] += vin[i][j];
            total_por_tipo[j] += vin[i][j];
        }
    }

    // --- Mostrar Resultados ---
    printf("\n\n--- Resumen de Produccion de Vino ---\n");

    // a. Total producido de cada tipo de vino
    printf("\nTotal producido por cada tipo de vino:\n");
    for (int j = 0; j < 4; j++) {
        printf("  Vino Tipo %d: %.2f litros\n", j + 1, total_por_tipo[j]);
    }

    // b. Total de la produccion anual
    printf("\nProduccion total por año:\n");
    for (int i = 0; i < N; i++) {
        printf("  Año %d: %.2f litros\n", i + 1, total_por_anio[i]);
    }

    printf("\n--- Fin del Programa ---\n");

    return 0;
}

