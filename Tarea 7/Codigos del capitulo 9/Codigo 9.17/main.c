#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cambia(FILE *, FILE *);
/* Prototipo de funci�n. Se pasan dos archivos como par�metros. */
void main(void) {
  FILE *ar;
  FILE *ap;
  ar = fopen("arc.txt", "r");   /* Se abre el archivo aarrcc.txt para lectura. */
  ap = fopen("arc1.txt", "w");  /* Se abre el archivo aarrcc11.txt para escritura. */
  if ((ar != NULL) && (ap != NULL)) {
    cambia(ar, ap);
    fclose(ar);
    fclose(ap);
  } else
    printf("No se pueden abrir los archivos");
}
void cambia(FILE *ap1, FILE *ap2) {
  /* Esta funci�n reemplaza en la cadena de caracteres la palabra mexico escrita
  con min�sculas �la primera letra� por su forma correcta y escribe la cadena
  de caracteres en un nuevo archivo. */
  int i, j, k;
  char cad[30], *cad1 = NULL, *cad2 = NULL, aux[30]; // Initialize cad1 and cad2 to NULL
  while (!feof(ap1)) {
    fgets(cad, 30, ap1);
    cad1 = (char *)malloc(strlen(cad) + 1); // Allocate memory for cad1
    if (cad1 == NULL) {
      perror("Error allocating memory for cad1");
      return;
    }
    strcpy(cad1, cad);
    cad2 = strstr(cad1, "m�xico");
    while (cad2 != NULL) {
      cad2[0] = 'M';           /* Reemplaza la letra min�scula por la may�scula. */
      i = strlen(cad1);
      j = strlen(cad2);
      k = i - j;
      if (k) {
        strncpy(aux, cad1, k);
        /* Se copia la subcadena de kcaracteres de cad1 a aux�desde el
        inicio decad1 hasta el caracter anterior a mexico. */
        aux[k] = '\0';
        strcat(aux, cad2);
        strcpy(cad1, aux);
      } else
        strcpy(cad1, cad2);
      cad2 = strstr(cad1, "m�xico");
    }
    fputs(cad1, ap2);     /* Se escribe la cadena correcta en el archivo aapp22. */
    free(cad1); // Free allocated memory after use
    cad1 = NULL; // Set to NULL to prevent dangling pointer
  }
}
