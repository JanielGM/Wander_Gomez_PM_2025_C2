#include <stdio.h> // Para printf y scanf
#include <math.h>  // Para fabs() (valor absoluto de flotantes) y pow() (si se usara, pero lo evitamos)

int main() {
    int X_int;        // Variable para leer el número entero X
    double X_rad;     // X convertido a double para los cálculos en radianes
    double suma_seno; // Suma acumulada de la serie
    double termino_actual; // Valor del término actual en la serie
    int num_terminos; // Contador de términos utilizados
    int den_mult1;    // Multiplicador para el denominador (ej: 2)
    int den_mult2;    // Multiplicador para el denominador (ej: 3)

    printf("--- Calculadora de sen(X) por Serie de Taylor ---\n");
    printf("Ingrese un numero entero X (se interpretara como radianes): ");
    scanf("%d", &X_int);

    X_rad = (double)X_int; // Convertir X a double para precision en los calculos

    // Caso especial para sen(0)
    if (X_rad == 0.0) {
        suma_seno = 0.0;
        num_terminos = 1; // sen(0) es 0, requiere 1 termino (el propio 0)
    } else {
        // Inicializar para el primer término (X^1 / 1!)
        suma_seno = X_rad;
        termino_actual = X_rad;
        num_terminos = 1; // Ya tenemos el primer término

        // Inicializar los multiplicadores del denominador para el siguiente término (2*3)
        den_mult1 = 2;
        den_mult2 = 3;

        // Bucle para calcular los términos siguientes hasta alcanzar la precisión deseada
        // La serie es: X - X^3/3! + X^5/5! - X^7/7! ...
        // Cada nuevo termino_actual = termino_anterior * (-X^2) / (den_mult1 * den_mult2)
        while (fabs(termino_actual) > 0.001) {
            // Calcular el siguiente término
            // Nota: X_rad * X_rad es mas eficiente que pow(X_rad, 2)
            termino_actual = termino_actual * (-X_rad * X_rad) / (den_mult1 * den_mult2);

            suma_seno += termino_actual; // Añadir el nuevo término a la suma
            num_terminos++;              // Incrementar el contador de términos

            // Preparar los multiplicadores del denominador para el siguiente término
            den_mult1 += 2; // Pasa de 2 a 4, luego a 6, etc.
            den_mult2 += 2; // Pasa de 3 a 5, luego a 7, etc.
        }
    }

    // Imprimir los resultados
    printf("\nEl sen(%.0f) calculado es: %.4f\n", X_rad, suma_seno); // %.0f para mostrar X sin decimales
    printf("Numero de terminos requeridos: %d\n", num_terminos);

    printf("\nFin del programa.\n");

    return 0;
}
