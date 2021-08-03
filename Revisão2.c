#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int leValidaQuantidadeAlunos();
float leValidaNota1(int cont);
float leValidaNota2(int cont);
float leValidaNota3(int cont);
int leValidaFrequencia(int cont);

main(){
	setlocale(LC_ALL, "Portuguese");
	int qtdAlunos, freqAulas[50], cont, contR, contA;
	float nota1[50], nota2[50], nota3[50], medFinalA[50], notaTurma, medTurma;
	qtdAlunos = leValidaQuantidadeAlunos();
	for(cont=0; cont<qtdAlunos; cont++){
		nota1[cont] = leValidaNota1(cont);
		nota2[cont] = leValidaNota2(cont);
		nota3[cont] = leValidaNota3(cont);
		freqAulas[cont] = leValidaFrequencia(cont);
		medFinalA[cont] = (nota1[cont]+nota2[cont]+nota3[cont])/3;
		printf("\nA média final do %iº aluno é = %2.f", cont+1, medFinalA[cont]);
		printf("\n");
		if(medFinalA[cont]<6 && freqAulas[cont]<45)
			contR += 1;
		notaTurma += medFinalA[cont];
		medTurma = notaTurma/qtdAlunos;
		if(medFinalA[cont]>medTurma)
			contA += 1;
	}
	printf("\nO total de alunos reprovados é = %i", contR-1);
	printf("\nA média da turma é = %2.f", medTurma);
	printf("\nO total de alunos que ficaram acima da média da turma é = %i", contA-1);
	Sleep(5000);
}

int leValidaQuantidadeAlunos(){
	int alunos;
	do{
		puts("\nInforme a quantidade de alunos da sala: ");
		scanf("%i", &alunos);
		if(alunos<2)
			puts("\nO número de alunos informados é inválido. Tente novamente.");
	}while(alunos<2);
	return alunos;
}

float leValidaNota1(int cont){
	float n1;
	do{
		printf("\nInforme a nota da A1 do %iº aluno: ", cont+1);
		scanf("%f", &n1);
		if(n1<0 || n1>10)
			puts("\nA nota informada é inválida(máx.10). Tente novamente.");
	}while(n1<0 || n1>10);
	return n1;
}

float leValidaNota2(int cont){
	float n2;
	do{
		printf("\nInforme a nota da A2 do %iº aluno: ", cont+1);
		scanf("%f", &n2);
		if(n2<0 || n2>10)
			puts("\nA nota informada é inválida(máx.10). Tente novamente.");
	}while(n2<0 || n2>10);
	return n2;
}

float leValidaNota3(int cont){
	float n3;
	do{
		printf("\nInforme a nota da A3 do %iº aluno: ", cont+1);
		scanf("%f", &n3);
		if(n3<0 || n3>10)
			puts("\nA nota informada é inválida(máx.10). Tente novamente.");
	}while(n3<0 || n3>10);
	return n3;
}

int leValidaFrequencia(int cont){
	int f;
	do{
		printf("\nInforme a frequência do %iº aluno em número de aulas: ", cont+1);
		scanf("%i", &f);
		if(f<0 || f>60)
			puts("\nO número de frequência de aulas é inválido(máx.60). Tente novamente.");
	}while(f<0 || f>60);
	return f;
}

