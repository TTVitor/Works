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
		printf("\nO peso m�dio do %i� time � = %2.f", cont2+1, pesoT);
		printf("\n");
		printf("\nA idade m�dia do %i� time � = %i", cont2+1, idadeT);
		printf("\n");
	}
	Sleep(5000);
}

int leValidaIdade(int cont, int cont2){
	int x;
	do{
		printf("\nInforme a idade do %i� jogador(m�n.6) do %i� time: ", cont+1, cont2+1);
		scanf("%i", &x);
		if(x<=5)
			puts("\nA idade informada � inv�lida. Tente novamente.");
	}while(x<=5);
	return x;
}

float leValidaPeso(int cont, int cont2){
	float y;
	do{
		printf("\nInforme o peso do %i� jogador do %i� time: ", cont+1, cont2+1);
		scanf("%f", &y);
		if(y<=0)
			puts("\nO peso informado � inv�lido. Tente novamente.");
	}while(y<=0);
	return y;
}
