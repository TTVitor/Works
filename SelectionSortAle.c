#include<stdio.h>
int main()
{
   // Definição de variaveis usadas no programa
   int i, j, posmin, temp, trocas, tamanho=10;
   int vetor[tamanho];

   // Preenchimento e escrita do vetor com numeros aleatorios
   srand(time(0));
   printf("\nVetor original\n");
   for(i=0;i<10;i++)
      { vetor[i]=rand()%10;
      printf("Elemento %2d: %3d \n",i+1,vetor[i]);}
   
   // Inicializa a variavel trocas
   trocas = 0;
   
   // Ordenação do vetor na técnica SelectionSort
 	for (i=0; i <= tamanho -2; i++) {
		posmin = i;
		for (j=i+1; j <= tamanho -1; j++) {
			if (vetor[j] < vetor[posmin]) {
				posmin = j;
			}
		}
		temp = vetor[i];
		vetor[i] = vetor[posmin];
		vetor[posmin] = temp;
		trocas++;
    }
	
    
   // Mostra vetor ordenado
   printf("\nVetor ordenado\n");
   for(i=0;i<tamanho;i++) printf("Elemento %2d: %3d \n",i+1,vetor[i]);
   printf("\n Foram Realizadas %d Trocas.\n", trocas);
   Sleep(150000);
}

