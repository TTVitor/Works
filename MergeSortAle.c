#include<stdio.h>
#include<stdlib.h>
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
	mergeSort(i, j, vetor);
	
	printf("\nVetor ordenado\n");
	for(i=0;i<tamanho;i++) printf("Elemento %2d: %3d \n",i+1,vetor[i]);
	printf("\n Foram Realizadas %d Trocas.\n", trocas);
	Sleep(150000);
	
void Intercala(int p, int q, int r, int v[]){
	int i, j, k, *w;
	w = malloc ((r-p) * sizeof (int));
	i = p;
	j = q;
	k = 0;
	
	while(i < q && j < r){
		if(v[i] <= v[j]){
			w[k++] = v[i++];
		}else{
			w[k++] = v[j++];
		}
	}
	while(i < q)
		w[k++] = v[i++];
	while(j < r)
		w[k++] = v[j++];
	for(i = p; i < r; i++)
		v[i] = w[i - p];
	free(w);	
}
	
void mergeSort(int p, int r, int v[]){
	int q;
	if(p < r-1){
		q = (p+r)/2;
		mergeSort(p, q, v);
		mergeSort(q, r, v);
		Intercala(p, q, r, v);
	}
}
}
