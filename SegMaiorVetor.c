#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>

main(){
	setlocale(LC_ALL, "Portuguese");
	int i, j, maior, segMaior, vetor[5], aux;
	maior = 0; //1
	segMaior = 0; //1
	srand(time(NULL)); //0
	for(i=0;i<5;i++){ //n+1
		vetor[i] = (rand() % 100); //n
		printf("Vetor[%d] = %d\n", i, vetor[i]); //n
	} //0
	
	for(i=0;i<5;i++){ //n+1
		for(j=0;j<5;j++){ //n+1
			if(vetor[i]<vetor[j]){ //n
				aux = vetor[i]; //n
				vetor[i] = vetor[j]; //n
				vetor[j] = aux; //n
			}
		}
	}
	
	for(i=0;i<5;i++){ //n+1
		printf("\nVetor Ordenado: Vetor[%d] = %d", i, vetor[i]); //n
	}
	
	for(i=0;i<5;i++){ //n+1
		if(vetor[i]>maior){ //n
			maior = vetor[i]; //n
		}
	}
	
	for(i=0;i<5;i++){ //n+1
		if(vetor[i]>segMaior && vetor[i]!=maior) //1
			segMaior = vetor[i]; //1
	}
	
	printf("\n"); //0
	printf("\nO segundo maior valor do vetor é = %d", segMaior); //0
	Sleep(10000); //0
	//10+15n
	//Melhor Caso: 1
	//Pior Caso: n+1
	//Caso Médio: (n+1)/2
}
