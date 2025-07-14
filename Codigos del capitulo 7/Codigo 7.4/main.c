#include <stdio.h>

/* Declaraci�n de cadenas de caracteres y asignaci�n de valores */

void main(void)
{
char *cad0;
    cad0 = "Canada";  // Correcto: asignaci�n de puntero
    puts(cad0);
    cad0 = "Peru";     // Correcto: cambio de puntero
    puts(cad0);

    // Ejemplo 2: Puntero no inicializado (INCORRECTO)
    char *cad1;



    char *cad2 = "";  // Reserva espacio para el terminador nulo
    // gets(cad2);  // Aunque compila, sigue siendo inseguro


    char cad3[20] = "Tailandia";
    puts(cad3);


    printf("Ingrese una cadena (m�x 19 caracteres): ");
    fgets(cad3, sizeof(cad3), stdin);  // Versi�n segura de gets()
    puts(cad3);


}
