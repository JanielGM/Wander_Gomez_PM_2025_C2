#include <stdio.h>

int main(void) {
    // Declaración de variables
    // SALARIOS_PROFESORES será un arreglo para guardar los salarios de 4 profesores
    float SALARIOS_PROFESORES[4];
    float nomina_bruta = 0.0;
    float impuesto_total = 0.0;
    float nomina_neta = 0.0;

    printf("--- Calculadora de Nómina e Impuestos (Versión Corta) ---\n\n");

    // Bucle para pedir y procesar el salario de cada profesor
    for (int i = 0; i < 4; i++) { // El bucle va de 0 a 3 para acceder a los 4 elementos del arreglo
        printf("Ingrese el salario del profesor %d: ", i + 1); // i+1 para mostrar Profesor 1, 2, etc.
        scanf("%f", &SALARIOS_PROFESORES[i]); // Guardamos el salario en la posición 'i' del arreglo

        float salario_actual = SALARIOS_PROFESORES[i];
        float impuesto_individual = salario_actual * 0.20;
        float salario_neto_individual = salario_actual - impuesto_individual;

        // Acumular los totales
        nomina_bruta += salario_actual;
        impuesto_total += impuesto_individual;
        nomina_neta += salario_neto_individual;

        // Imprimir el pago del profesor individual menos el 20%
        printf("  Salario original: %.2f\n", salario_actual);
        printf("  Impuesto (20%%):   %.2f\n", impuesto_individual);
        printf("  Pago neto al profesor %d: %.2f\n", i + 1, salario_neto_individual);
    }

    // --- Resumen de la Nómina ---
    printf("\n--- Resumen de la Nómina ---\n");
    printf("El total de la nomina bruta (sin impuesto) es: %.2f\n", nomina_bruta);
    printf("El total a pagar a los profesores (ya con impuesto descontado) es: %.2f\n", nomina_neta);
    printf("El total de impuesto retenido es: %.2f\n", impuesto_total);
    printf("\nFin de programa\n");

    return 0;
}
