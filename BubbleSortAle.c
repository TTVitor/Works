#include<stdio.h>
int main()
{
   // Defini��o de variaveis usadas no programa
   int i, j, aux, trocas, tamanho=10;
   int vetor[tamanho];

   // Preenchimento e escrita do vetor com numeros aleatorios
   srand(time(0));
   printf("\nVetor original\n");
   for(i=0;i<10;i++)
      { vetor[i]=rand()%10;
      printf("Elemento %2d: %3d \n",i+1,vetor[i]);}
   
   // Inicializa a variavel trocas
   trocas = 0;

   // Ordena��o do vetor na t�cnica BubbleSort
   for(i=0;i<=8;i++)
      {
      for(j=i+1;j<=9;j++)
         {
         if(vetor[j]<vetor[i])
            {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            trocas++;
            }
         }
      }
   
   // Mostra vetor ordenado
   printf("\nVetor ordenado\n");
   for(i=0;i<tamanho;i++) printf("Elemento %2d: %3d \n",i+1,vetor[i]);
   printf("\n Foram Realizadas %d Trocas.\n", trocas);
   Sleep(150000);
}
