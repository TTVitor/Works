#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float mediaVetor(int vet[], int tam){
	float soma = 0;
	int i;
	for(i=0;i<tam;i++){
		soma += vet[i];
	}
	return soma/tam;
}

main(){
	setlocale(LC_ALL, "Portuguese");
	int i, vetor[] = {2,3,5,7,13};
	float media;
	media = mediaVetor(vetor, 5);
	printf("Média dos valores do vetor: %2.f", media);
	for(i=0;i<5;i++){
		if(vetor[i]>media)
		printf("\nOs valores acima da média são: %d", vetor[i]);
	}
	Sleep(6000);
}
