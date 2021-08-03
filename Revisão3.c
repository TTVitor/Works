#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int leValidaIdade(int cont, int cont2);
float leValidaPeso(int cont, int cont2);

main(){
	setlocale(LC_ALL, "Portuguese");
	int totalTimes, totalJ, idade[23], idadeT, idadeJ, cont, cont2;
	float peso[23], pesoT, pesoJ;
	totalTimes = 19;
	totalJ = 23;
	for(cont2=0; cont2<=totalTimes; cont2++){
		for(cont=0; cont<=totalJ; cont++){
			peso[cont] = leValidaPeso(cont, cont2);
			idade[cont] = leValidaIdade(cont, cont2);
			pesoJ += peso[cont];
			pesoT = pesoJ/totalJ;
			idadeJ += idade[cont];
			idadeT = idadeJ/totalJ;
		}
		printf("\nO peso médio do %iº time é = %2.f", cont2+1, pesoT);
		printf("\n");
		printf("\nA idade média do %iº time é = %i", cont2+1, idadeT);
		printf("\n");
	}
	Sleep(5000);
}

int leValidaIdade(int cont, int cont2){
	int x;
	do{
		printf("\nInforme a idade do %iº jogador(mín.6) do %iº time: ", cont+1, cont2+1);
		scanf("%i", &x);
		if(x<=5)
			puts("\nA idade informada é inválida. Tente novamente.");
	}while(x<=5);
	return x;
}

float leValidaPeso(int cont, int cont2){
	float y;
	do{
		printf("\nInforme o peso do %iº jogador do %iº time: ", cont+1, cont2+1);
		scanf("%f", &y);
		if(y<=0)
			puts("\nO peso informado é inválido. Tente novamente.");
	}while(y<=0);
	return y;
}
