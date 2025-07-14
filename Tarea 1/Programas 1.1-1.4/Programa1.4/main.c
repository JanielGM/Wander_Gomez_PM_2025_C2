 #include <stdio.h>
 // Superficie del triángulo.

 void main (void)
 {
  float BAS, ALT, SUP;
printf("Ingrese la base y la altura del triángulo: ");
 scanf("%f %f", &BAS, &ALT);
 SUP = BAS * ALT / 2;
 printf("\nLa superficie del triángulo es: %5.2f", SUP);
 }
