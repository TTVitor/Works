#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10
int main()
{
 setlocale(LC_ALL, "");
 int numeros[TAM];
 int i, aux, contador;
 int trocas;
printf("Entre com dez números para preencher o array, e pressione enter após digitar cada um:\n");
 for (i = 0; i < TAM; i++) {
 scanf("%d", &numeros[i]);
 }
printf("Ordem atual dos itens no array:\n");
for (i = 0; i < TAM; i++) {
 printf("%4d", numeros[i]);
}
	trocas = 0;
// Algoritmo de ordenação Bubblesort:
 for (contador = 1; contador < TAM; contador++) {
   for (i = 0; i < TAM - 1; i++) {
     if (numeros[i] > numeros[i + 1]) {
       aux = numeros[i];
       numeros[i] = numeros[i + 1];
       numeros[i + 1] = aux;
       trocas++;
     }
   }
 }
printf("\nElementos do array em ordem crescente:\n");
for (i = 0; i < TAM; i++) {
 printf("%4d", numeros[i]);
}
printf("\n");
printf("\n Foram Realizadas %d Trocas.\n", trocas);
Sleep(150000);
return 0;
}
