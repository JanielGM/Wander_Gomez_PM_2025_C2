#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para malloc y free //

/*El programa muestra la manera en que se declara una estructura, asi como la
forma en que se tiene acceso a los campos de los apuntadores de tipo estructura
tanto para lectura como para escritura. Se utiliza ademas una funcion que
recibe como parametro un apuntador de tipo estructura */
struct alumno /* Declaracion de la estructura. */
{
    int matricula;
    char nombre[20];
    char carrera[20]; /* Campos de la estructura alumno. */
    float promedio;
    char direccion[20];
};

void Lectura(struct alumno *); /* Prototipo de funcion. */

int main(void)
{
    struct alumno a0 = {120, "Maria", "Contabilidad", 8.9, "Queretaro"};
    struct alumno *a3, *a4, *a5, a6;

    /* Asignar a3 la direccion de a0 */
    a3 = &a0;

    /* Asignar memoria dinamicamente para a4 */
    a4 = (struct alumno *)malloc(sizeof(struct alumno));
    if (a4 == NULL) {
        printf("\nError: No se pudo asignar memoria para a4.\n");
        return 1;
    }

    /* Leer datos para a4 usando ambos formatos de acceso */
    printf("\nIngrese la matricula del alumno 4: ");
    scanf("%d", &(*a4).matricula);
    while (getchar() != '\n'); /* Limpiar buffer */

    printf("Ingrese el nombre del alumno 4: ");
    if (fgets(a4->nombre, sizeof(a4->nombre), stdin) != NULL) {
        a4->nombre[strcspn(a4->nombre, "\n")] = '\0';
    }

    printf("Ingrese la carrera del alumno 4: ");
    if (fgets((*a4).carrera, sizeof((*a4).carrera), stdin) != NULL) {
        (*a4).carrera[strcspn((*a4).carrera, "\n")] = '\0';
    }

    printf("Ingrese el promedio del alumno 4: ");
    scanf("%f", &a4->promedio);
    while (getchar() != '\n'); /* Limpiar buffer */

    printf("Ingrese la direccion del alumno 4: ");
    if (fgets(a4->direccion, sizeof(a4->direccion), stdin) != NULL) {
        a4->direccion[strcspn(a4->direccion, "\n")] = '\0';
    }

    /* Asignar memoria dinamicamente para a5 */
    a5 = (struct alumno *)malloc(sizeof(struct alumno));
    if (a5 == NULL) {
        printf("\nError: No se pudo asignar memoria para a5.\n");
        free(a4); /* Liberar memoria asignada a a4 */
        return 1;
    }

    Lectura(a5); /* Pasar apuntador a5 a la funcion Lectura */
    Lectura(&a6); /* Pasar direccion de a6 a la funcion Lectura */

    /* Imprimir datos */
    printf("\nDatos del alumno 3\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a3->matricula, a3->nombre, a3->carrera,
           a3->promedio, a3->direccion);

    printf("Datos del alumno 4\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a4->matricula, a4->nombre, a4->carrera,
           a4->promedio, a4->direccion);

    printf("Datos del alumno 5\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a5->matricula, a5->nombre, a5->carrera,
           a5->promedio, a5->direccion);

    printf("Datos del alumno 6\n");
    printf("%d\t%s\t%s\t%.2f\t%s\n", a6.matricula, a6.nombre, a6.carrera,
           a6.promedio, a6.direccion);

    /* Liberar memoria asignada dinamicamente */
    free(a4);
    free(a5);

    return 0; /* Retorno estandar */
}

void Lectura(struct alumno *a)
{
    /* Esta funcion permite leer los campos de un apuntador de tipo estructura alumno. */
    printf("\nIngrese la matricula del alumno: ");
    scanf("%d", &(*a).matricula);
    while (getchar() != '\n'); /* Limpiar buffer */

    printf("Ingrese el nombre del alumno: ");
    if (fgets(a->nombre, sizeof(a->nombre), stdin) != NULL) {
        a->nombre[strcspn(a->nombre, "\n")] = '\0';
    }

    printf("Ingrese la carrera del alumno: ");
    if (fgets(a->carrera, sizeof(a->carrera), stdin) != NULL) {
        a->carrera[strcspn(a->carrera, "\n")] = '\0';
    }

    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &a->promedio);
    while (getchar() != '\n'); /* Limpiar buffer */

    printf("Ingrese la direccion del alumno: ");
    if (fgets(a->direccion, sizeof(a->direccion), stdin) != NULL) {
        a->direccion[strcspn(a->direccion, "\n")] = '\0';
    }
}
