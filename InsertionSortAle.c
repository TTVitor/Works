#include<stdio.h>
int main()
{
   // Defini��o de variaveis usadas no programa
   int i, j, chave, trocas, tamanho=10;
   int vetor[tamanho];
   j=0;
   chave=0;

   // Preenchimento e escrita do vetor com numeros aleatorios
   srand(time(0));
   printf("\nVetor original\n");
   for(i=0;i<10;i++)
      { vetor[i]=rand()%10;
      printf("Elemento %2d: %3d \n",i+1,vetor[i]);}
   
   // Inicializa a variavel trocas
   trocas = 0;
   
   // Ordena��o do vetor na t�cnica InsertionSort
 	for ( i = 1; i < tamanho; i++ ) {
		chave = vetor [ i ];
		j = i - 1;
		while ( j >= 0 && vetor [ j ] > chave ) {
			vetor [ j + 1 ] = vetor [ j ];
			j = j - 1;
			vetor [ j + 1 ] = chave;
			trocas++;
		}
	}
	
    
   // Mostra vetor ordenado
   printf("\nVetor ordenado\n");
   for(i=0;i<tamanho;i++) printf("Elemento %2d: %3d \n",i+1,vetor[i]);
   printf("\n Foram Realizadas %d Trocas.\n", trocas);
   Sleep(150000);
}

