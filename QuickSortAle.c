#include<stdio.h>
int main()
{
   // Definição de variaveis usadas no programa
   int i, j, trocas, tamanho=10;
   int vetor[tamanho];

   // Preenchimento e escrita do vetor com numeros aleatorios
   srand(time(0));
   printf("\nVetor original\n");
   for(i=0;i<10;i++)
      { vetor[i]=rand()%10;
      printf("Elemento %2d: %3d \n",i+1,vetor[i]);
	}
	
	trocas = 0;
	quicksort(j, i, vetor);
	
	printf("\nVetor ordenado\n");
	for(i=0;i<tamanho;i++) printf("Elemento %2d: %3d \n",i+1,vetor[i]);
	printf("\n Foram Realizadas %d Trocas.\n", trocas);
	Sleep(150000);
}
      
int particao (int p, int r, int v[]) {
	int i, j, temp, pivo;
	pivo = v[r];
	j = p;
	for (i = p; i < r; i ++) {
		if (v[i] < pivo) {
			temp = v[j];
			v[j] = v[i];
			v[i] = temp;
			j++;
		}
	}
	v[r] = v[j];
	v[j] = pivo;
	return j;	
}

void quicksort(int p, int r, int v[]) { 
int q;
    if (p < r) {
	q = particao(p,r,v);
	quicksort(p, q-1, v);
	quicksort(q+1, r, v);
    }
}
