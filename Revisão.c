#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
int leValidaFuncionarios();
float leValidaSalarios(int cont);
char leValidaSexo(int cont);
int leValidaFilhos(int cont);
int leValidaTempoTrab(int cont);
main(){
	setlocale(LC_ALL,"Portuguese");
	int numFuncionarios, tempoTrab[100], numFilhos[100], cont;
	float salario[100], reajuste;
	char sexo[100];
	numFuncionarios = leValidaFuncionarios();
	for(cont=0; cont<numFuncionarios; cont++){
		salario[cont] = leValidaSalarios(cont);
		sexo[cont] = leValidaSexo(cont);
		if(sexo[cont]=='f' || sexo[cont]=='F')
			numFilhos[cont] = leValidaFilhos(cont);
		if(sexo[cont]=='m' || sexo[cont]=='M')
			tempoTrab[cont] = leValidaTempoTrab(cont);
	}
	for(cont=0; cont<numFuncionarios; cont++){
		reajuste = salario[cont];
		if((sexo[cont]=='f' || sexo[cont]=='F') && numFilhos[cont]>=2)
			reajuste *= 1.03;
		if((sexo[cont]=='m' || sexo[cont]=='M') && tempoTrab[cont]>=3)
			reajuste *= 1.02;
		printf("\nO sal�rio reajustado do %i�(�)funcion�rio(a) do sexo %c � = R$ %2.f ", cont+1, sexo[cont], reajuste);				
	}
	Sleep(5000);
}

int leValidaFuncionarios(){
	int num;
	do{
		puts("\nInforme o n�mero de funcion�rios da empresa(m�x 100): ");
		scanf("%d", &num);
		if(num<=0 || num>100)
			puts("\nO n�mero informado de funcion�rios � inv�lido. Tente novamente.");
	}while(num<=0 || num>100);
	return num;
}

float leValidaSalarios(int cont){
	float sal;
	do{
		printf("\nInforme o sal�rio do %i� funcion�rio(m�n 1000): ", cont+1);
		scanf("%f", &sal);
		if(sal<1000)
			puts("\nO sal�rio informado � inv�lido. Tente novamente.");
	}while(sal<1000);
	return sal;
}

char leValidaSexo(int cont){
	char sexo;
	do{
		printf("\nInforme o sexo do %i� funcion�rio: ", cont+1);
		sexo = getche();
		if((sexo!='m' && sexo!='M') && (sexo!='f' && sexo!='F'))
			puts("\nO sexo informado � inv�lido. Tente novamente.");
	}while((sexo!='m' && sexo!='M') && (sexo!='f' && sexo!='F'));
	return sexo;
}

int leValidaFilhos(int cont){
	int numF;
	do{
		printf("\nInforme o n�mero de filhos da %i� funcion�ria: ", cont+1);
		scanf("%d", &numF);
		if(numF<0)
			puts("\nO n�mero de filhos informado � inv�lido. Tente novamente.");
	}while(numF<0);
	return numF;
}

int leValidaTempoTrab(int cont){
	int numT;
	do{
		printf("\nInforme o tempo de trabalho na empresa do %i� funcion�rio: ", cont+1);
		scanf("%d", &numT);
		if(numT<0)
			puts("\nO tempo de trabalho informado � inv�lido. Tente novamente.");
	}while(numT<0);
	return numT;
}
