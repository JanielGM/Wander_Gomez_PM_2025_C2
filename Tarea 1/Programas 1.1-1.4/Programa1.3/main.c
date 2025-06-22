#include <stdio.h>
#include <stdlib.h>

int main()
{
    int CLA;
    float SU1,SU2,SU3,SU4,SU5;
    float ING;
    float PRO;
    printf("Ingrese la clave del empleado y los 5 sueldos: \n");
    scanf("%d %f %f %f %f %f", &CLA, &SU1, &SU2, &SU3, &SU4, &SU5);

    ING = (SU1 + SU2 + SU3 + SU4 + SU5);
    PRO = ING / 5;

     printf("\nClave del empleado: %d\n"
           "Sueldo 1: %5.2f\n"
           "Sueldo 2: %5.2f\n"
           "Sueldo 3: %5.2f\n"
           "Sueldo 4: %5.2f\n"
           "Sueldo 5: %5.2f\n"
           "Ingreso Total: %5.2f\n"
           "Promedio de Sueldos: %5.2f\n",
           CLA, SU1, SU2, SU3, SU4, SU5, ING, PRO);
       return 0;

}
