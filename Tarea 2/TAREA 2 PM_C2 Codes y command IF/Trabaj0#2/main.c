#include <stdio.h>
#include <stdlib.h>
//Escribir un programa para definir el rango de edad de una persona
// 1- de 0 anios (anios) 1 anios - recien nacido
// 2- de 1 a 12 anios
// 3- de 12 anios a 17 es adolescente
// 4- de 18 a 25 es adulto
// 5- de 26 a 65 adulto mayor
// 6- de 66 a 86 es envejeciente
// 7- mayor de 86 es anciano

int main() {
    int edad = 0;
    printf("\nEscriba la edad del paciente: ");
    scanf("%i", &edad);

    if (edad >= 0 && edad <= 130) {
        if (edad == 0) {
            printf("Es un recien ninio, la dosis recomendada es 0 ml.");
        } else if (edad <= 12) {
            printf("Es un adolescente, la dosis recomendada es 0.5 ml.");
        } else if (edad <= 17) {
            printf("Es un adulto, la dosis recomendada es 0.75 ml.");
        } else if (edad <= 25) {
            printf("Es un adulto mayor, la dosis recomendada es 1 ml.");
        } else if (edad <= 65) {
            printf("Es un envejeciente, la dosis recomendada es 1.25 ml.");
        } else if (edad <= 86) {
            printf("Es un anciano, la dosis recomendada es 0.75 ml.");
        } else if (edad <= 130){
        }
    } else
    {
        printf("Valor no valido");
    }

    system("pause");
    return 0;
}
