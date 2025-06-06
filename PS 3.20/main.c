#include <stdio.h> // Para printf
#include <math.h>  // Para pow (potencia), aunque se puede calcular manualmente para enteros

int main() {
    int T, P, R;            // Variables para los valores que buscamos
    long long resultado_expr; // Usamos long long para evitar desbordamientos, ya que las potencias crecen rápido
    int contador_soluciones = 0; // Para llevar la cuenta de las soluciones encontradas

    printf("--- Buscador de Soluciones para 7*T^4 - 6*P^3 + 12*R^5 < 5850 ---\n");
    printf("T, P, R solo pueden tomar valores enteros positivos.\n");
    printf("-------------------------------------------------------------------\n");

    // Los límites de los bucles se han calculado para optimizar la búsqueda
    // T_max = 5 (porque 7*6^4 > 5850)
    // P_max = 12 (porque 7*5^4 + 12*3^5 - 6*13^3 < 5850 puede no cumplirse, o el término 6*P^3 crece mucho)
    // R_max = 3 (porque 12*4^5 > 5850)

    for (T = 1; T <= 5; T++) { // Bucle para T
        for (P = 1; P <= 12; P++) { // Bucle para P
            for (R = 1; R <= 3; R++) { // Bucle para R

                // Calcular los términos de la expresión.
                // Se utiliza (long long) para asegurar que la multiplicacion se haga con ese tipo
                // y prevenir desbordamientos antes de la suma/resta.
                // pow() devuelve un double, por lo que casteamos a long long.
                resultado_expr = (long long)7 * (long long)pow(T, 4) -
                                 (long long)6 * (long long)pow(P, 3) +
                                 (long long)12 * (long long)pow(R, 5);

                // Comprobar si la expresión satisface la condición
                if (resultado_expr < 5850) {
                    printf("Solucion encontrada: T = %d, P = %d, R = %d\n", T, P, R);
                    contador_soluciones++; // Incrementar el contador
                }
            }
        }
    }

    printf("-------------------------------------------------------------------\n");
    printf("Total de soluciones encontradas: %d\n", contador_soluciones);
    printf("Fin del programa.\n");

    return 0; // Terminar el programa exitosamente
}
