#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

main(){
	setlocale(LC_ALL, "Portuguese");
	int menor, *vetor, tam, i, aux, j;
	menor = 0; //1
	aux = 0; //1
	printf("Informe o tamanho do vetor: "); //1
	scanf("%d", &tam); //0
	vetor = (int*) malloc( sizeof(int*) *tam);  //1
    for(i=0; i<tam; i++){ //n
    	printf("Informe números inteiros: "); //1
		scanf("%d", &vetor[i]); //0
		if(i==0){menor=vetor[i];} //1
		if(vetor[i]<menor){ //n
			menor = vetor[i]; //n
		}
	}
	for(i=0;i<tam;i++){ //n
		for(j=0;j<tam;j++){ //n
			if(vetor[i]<vetor[j]){ //n
				aux = vetor[i]; //n
				vetor[i] = vetor[j]; //n
				vetor[j] = aux; //n
			}
		}
	}
	for(i=0;i<tam;i++){ //n
		printf("Vetor Ordenado : %d\n", vetor[i]); //1
	}
	for(i=0;i<tam;i++){ //n
		printf("Vetor Ordenado : %d\n", vetor[i]); //1
		vetor[i+1] = vetor[i]; //n
	}
	printf("O menor valor do vetor é = %d", menor); //1
	Sleep(6000);
	//9+12n
}
