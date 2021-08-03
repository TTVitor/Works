// Aluno: Vítor Gabriel Barbosa dos Santos
// Data: 12/05/2020
// Professora: Graziela Guarda
// Prova

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>

typedef enum {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
} COLORS;

static int __BACKGROUND = BLACK;
static int __FOREGROUND = LIGHTGRAY;

textcolor (int color) {
	__FOREGROUND = color;
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
	                         color + (__BACKGROUND << 4));
}

struct FichaPacientes {
	int codigo, idade, sintomas[10];
	char nome[100], cidade[100], sexo;
} dadosPacientes[100];

int qtdeCasosCOVID;
FILE *arqPacientes;

void leValidaNome(int i) {
	do {
		fflush(stdin);
		printf("\nInforme o nome do %iº paciente: ", i+1);
		gets(dadosPacientes[i].nome);
		if (strcmp(dadosPacientes[i].nome,"") == 0) {
			puts("\nO nome não pode ser vazio. Tente novamente.");
		}
	} while((dadosPacientes[i].nome,"") == 0);
}

void leValidaIdade(int i) {
	do {
		printf("\nInforme a idade do %iº paciente: ", i+1);
		scanf("%i", &dadosPacientes[i].idade);
		if (dadosPacientes[i].idade<0) {
			puts("\nA idade informada é inválida. Tente novamente.");
		}
	} while(dadosPacientes[i].idade<0);
}

void leValidaSexo(int i) {
	do {
		fflush(stdin);
		printf("\nInforme o sexo do %iº paciente: ", i+1);
		scanf("%c", &dadosPacientes[i].sexo);
		dadosPacientes[i].sexo = toupper(dadosPacientes[i].sexo);
		if (dadosPacientes[i].sexo != 'F' && dadosPacientes[i].sexo != 'M') {
			puts("\nO sexo informado é invalido. Tente novamente");
		}
	} while(dadosPacientes[i].sexo != 'F' && dadosPacientes[i].sexo != 'M');
}

void leValidaCidade(int i) {
	do {
		printf("\nInforme a cidade onde mora o %iº paciente: ", i+1);
		gets(dadosPacientes[i].cidade);
		if (strcmp(dadosPacientes[i].cidade,"") == 0) {
			puts("\nO nome não pode ser vazio. Tente novamente");
		}
	} while(strcmp(dadosPacientes[i].cidade,"") == 0);
}

void leValidaCodigo(int qtde) {
	int posicao;
	do {
		printf("\nDigite o código do paciente: ");
		scanf("%i", &dadosPacientes[qtde].codigo);
		posicao = recuperaId(qtde);
		if(posicao == -1)
			puts("\nO código informado é inválido. Tente novamente.");	
	} while(posicao == -1);
}

int recuperaId(int qtde) {
    int primeiro, ultimo, meio;
   
    primeiro = 0;
    ultimo = qtde - 1;
    meio = (primeiro + ultimo) / 2;
   
    while (primeiro <= ultimo) {
	    if (dadosPacientes[meio].codigo < dadosPacientes[qtde].codigo)
	    	primeiro = meio + 1;
	   
	    else if (dadosPacientes[meio].codigo == dadosPacientes[qtde].codigo) {
			return meio;
			break;
		}

		else
		ultimo = meio - 1;

		meio = (primeiro + ultimo) / 2;
	}

	if (primeiro > ultimo)
	return -1; 	
}

int recuperaDadosArquivo() {
	int i, erro, qtde;
	
	// Erro
	if ((arqPacientes = fopen("pacientes.txt", "r")) == NULL) {
		return 0; 
		exit(1);
	}	
	
	// Sucesso
	else {
			
		fscanf(arqPacientes, "%d", &qtde);
	
		//while (!feof(arqPacientes)) {
		for (i = 0; i < qtde; i++) {
			//fscanf(arqPacientes, "%d %d %i %i %i %i %i %i %i %i %i %i %s %s %c", &dadosPacientes[i].codigo, &dadosPacientes[i].idade, &dadosPacientes[i].sintomas[0], &dadosPacientes[i].sintomas[1], &dadosPacientes[i].sintomas[2], &dadosPacientes[i].sintomas[3], &dadosPacientes[i].sintomas[4], &dadosPacientes[i].sintomas[5], &dadosPacientes[i].sintomas[6], &dadosPacientes[i].sintomas[7], &dadosPacientes[i].sintomas[8], &dadosPacientes[i].sintomas[9], &dadosPacientes[i].nome, &dadosPacientes[i].cidade, &dadosPacientes[i].sexo);
			//i++;
			fscanf(arqPacientes, "%d %d %s %s %c", &dadosPacientes[i].codigo, &dadosPacientes[i].idade, dadosPacientes[i].nome, dadosPacientes[i].cidade, &dadosPacientes[i].sexo);
		}
		
	}
	
	fclose(arqPacientes);
	return qtde;
}
	
int gravaDadosnoArquivo(int qtde) {
	int i, erro;
	
	// Erro
	if ((arqPacientes = fopen("pacientes.txt", "w")) == NULL) {
		return 0; 
		exit(1);
	}
	
	// Sucesso
	else {
		
		fprintf(arqPacientes, "%d", qtde);
		fprintf(arqPacientes, "\n");
		
	   	for (i = 0; i < qtde; i++) {
			//fprintf(arqPacientes, "%d %d %i %i %i %i %i %i %i %i %i %i %s %s %c", dadosPacientes[i].codigo, dadosPacientes[i].idade, dadosPacientes[i].sintomas[0], dadosPacientes[i].sintomas[1], dadosPacientes[i].sintomas[2], 
				//dadosPacientes[i].sintomas[3], dadosPacientes[i].sintomas[4], dadosPacientes[i].sintomas[5], dadosPacientes[i].sintomas[6], dadosPacientes[i].sintomas[7], dadosPacientes[i].sintomas[8], dadosPacientes[i].sintomas[9], 
				//dadosPacientes[i].nome, dadosPacientes[i].cidade, dadosPacientes[i].sexo);
			fprintf(arqPacientes, "%d %d %s %s %c", dadosPacientes[i].codigo, dadosPacientes[i].idade, dadosPacientes[i].nome, dadosPacientes[i].cidade, dadosPacientes[i].sexo);
			fprintf(arqPacientes, "\n");
		}	

	}	
		
	fclose(arqPacientes);
	return 1;
}

void menu(int qtde, int tam) {
	int op, i, codigo;
	char voltar;
	i = 0;
	textcolor(YELLOW);
	do {
		printf("\n\n\t+++ DADOS MÉDICOS +++\n\n");
		printf("  ________________________________\n");
		printf(" |       OPÇÃO       |   CÓDIGO   |\n");
		printf(" |--------------------------------|\n");
		printf(" |  CRIAR FICHAS     |     1      |\n");
		printf(" |  LISTAR FICHAS    |     2      |\n");
		printf(" |  CONSULTAR FICHAS |     3      |\n");	
		printf(" |  ALTERAR FICHAS   |     4      |\n");
		printf(" |  CASOS COVID-19   |     5      |\n");
		printf(" |  RECUPERA ARQ     |     6      |\n");
		printf(" |  GRAVA EM ARQ     |     7      |\n");				
		printf(" |--------------------------------|\n");		
		printf(" |  SAIR DO PROGRAMA |     8      |\n");
		printf(" |___________________|____________|\n\n");
		printf(" Digite sua opção: ");
		scanf("%d", &op);
		
		if(op<1 || op>8)
			puts("\nOpção digitada é inválida. Tente novamente.");	
			getch();
	} while(op<1 || op>8);
	textcolor(WHITE);
	
	switch(op) {
		case 1:
			inclusao(qtde, tam);
			break;
		case 2:
			listagem(qtde, tam);
			break;
		case 3:
			leValidaCodigo(qtde);
			consulta(qtde, tam);
			break;
		case 4:
			leValidaCodigo(qtde);
			alteracao(qtde, tam);
			break;
		case 5:
			exibeCasosCOVID(qtde, tam);
			break;
		case 6:
			if (qtde = recuperaDadosArquivo()) printf("Dados recuperados do arquivo com sucesso!\n");
			else printf("Erro ao tentar abrir e recuperar dados do arquivo!\n");
			
			printf("\n");
			printf("Pressione qualquer tecla para voltar ao menu... ");
			fflush(stdin);
			scanf("%c", &voltar);
			menu(qtde, tam);
			break;
		case 7:
			if (gravaDadosnoArquivo(qtde)) printf("Dados gravados no arquivo com sucesso!\n");
			else printf("Erro ao tentar abrir arquivo!\n");
			
			printf("\n");
			printf("Pressione qualquer tecla para voltar ao menu... ");
			fflush(stdin);
			scanf("%c", &voltar);
			menu(qtde, tam);
			break;						
	}
}

int geraCodigo(int qtde){
	srand(time(0));
	int senha, posicao;
	senha = rand()%100;
	dadosPacientes[qtde].codigo = senha;
	posicao = recuperaId(qtde);
	if(posicao == -1)
		return senha;
	else
		geraCodigo(qtde);
}

void ordenaCodigo(int qtde){
	int i, j, chave;
	for ( i = 1; i < qtde; i++ ) {
		chave = dadosPacientes[i].codigo;
		j = i - 1;
		while ( j >= 0 && dadosPacientes[j].codigo > chave ) {
			dadosPacientes[j+1].codigo = dadosPacientes[j].codigo;
			j = j - 1;
			dadosPacientes[j+1].codigo = chave;
		}
	}
}

void inclusao(int qtde, int tam) {
	char voltar;
	dadosPacientes[qtde].codigo = geraCodigo(qtde+1);
	printf("\nCódigo gerado para o paciente = %d\n", dadosPacientes[qtde].codigo);
	leValidaNome(qtde);
	leValidaCidade(qtde);
	leValidaIdade(qtde);
	leValidaSexo(qtde);
	leValidaSintomas(qtde);
	ordenaCodigo(qtde+1);
	printf("\n");
	printf("\n");
	printf("Pressione qualquer tecla para voltar ao menu... ");
	fflush(stdin);
	scanf("%c", &voltar);
	menu(qtde+1, tam);
}

void consulta(int qtde, int tam){
	char voltar;
	int posicao, i;
	posicao = recuperaId(qtde);
	printf("\nCódigo: %i", dadosPacientes[posicao].codigo);
	printf("\nNome: %s", dadosPacientes[posicao].nome);
	printf("\nIdade: %i", dadosPacientes[posicao].idade);
	printf("\nSexo: %c", dadosPacientes[posicao].sexo);
	printf("\nCidade: %s", dadosPacientes[posicao].cidade);
	printf("\nSintomas:\n");
	for (i = 0; i < 10; i++) {
		if (dadosPacientes[posicao].sintomas[i] == 1) printf("- FEBRE\n");
		if (dadosPacientes[posicao].sintomas[i] == 2) printf("- DORES NO CORPO\n");
		if (dadosPacientes[posicao].sintomas[i] == 3) printf("- CORIZA\n");
		if (dadosPacientes[posicao].sintomas[i] == 4) printf("- TOSSE\n");
		if (dadosPacientes[posicao].sintomas[i] == 5) printf("- DIARRÉIA\n");
		if (dadosPacientes[posicao].sintomas[i] == 6) printf("- DOR DE CABEÇA\n");
		if (dadosPacientes[posicao].sintomas[i] == 7) printf("- FALTA DE AR\n");
		if (dadosPacientes[posicao].sintomas[i] == 8) printf("- DOR DE GARGANTA\n");
	}
	
	printf("\n");
	printf("\n");
	printf("Pressione qualquer tecla para voltar ao menu... ");
	fflush(stdin);
	scanf("%c", &voltar);
	menu(qtde, tam);
}

void listagem(int qtde, int tam) {
	char voltar;
	int i, j;
	for(i=0; i<qtde; i++) {
		printf("\nCódigo: %i", dadosPacientes[i].codigo);
		printf("\nNome: %s", dadosPacientes[i].nome);
		printf("\nIdade: %i", dadosPacientes[i].idade);
		printf("\nSexo: %c", dadosPacientes[i].sexo);
		printf("\nCidade: %s", dadosPacientes[i].cidade);
		printf("\nSintomas:\n");
		for (j = 0; j < 10; j++) {
			if (dadosPacientes[i].sintomas[j] == 1) printf("- FEBRE\n");
			if (dadosPacientes[i].sintomas[j] == 2) printf("- DORES NO CORPO\n");
			if (dadosPacientes[i].sintomas[j] == 3) printf("- CORIZA\n");
			if (dadosPacientes[i].sintomas[j] == 4) printf("- TOSSE\n");
			if (dadosPacientes[i].sintomas[j] == 5) printf("- DIARRÉIA\n");
			if (dadosPacientes[i].sintomas[j] == 6) printf("- DOR DE CABEÇA\n");
			if (dadosPacientes[i].sintomas[j] == 7) printf("- FALTA DE AR\n");
			if (dadosPacientes[i].sintomas[j] == 8) printf("- DOR DE GARGANTA\n");
		}
	}
	
	printf("\n");
	printf("\n");
	printf("Pressione qualquer tecla para voltar ao menu... ");
	fflush(stdin);
	scanf("%c", &voltar);
	menu(qtde, tam);
}

void alteracao(int qtde, int tam){
	char voltar;
	int posicao;
	posicao = recuperaId(qtde);
	leValidaNome(posicao);
	leValidaIdade(posicao);
	leValidaSexo(posicao);
	leValidaCidade(posicao);
	printf("\n");
	printf("\n");
	printf("Pressione qualquer tecla para voltar ao menu... ");
	fflush(stdin);
	scanf("%c", &voltar);
	menu(qtde, tam);
}

void leValidaSintomas(int qtde) {
	int opcao, i, flag, cont, posicao;
	
	posicao = qtde;
	cont = 0;
	
	do {
		flag = 0;
		textcolor(LIGHTGREEN);
		printf("\n\n\t+++ COVID-19 +++\n\n");
		printf("  ________________________________\n");
		printf(" |       OPÇÃO       |  CÓDIGO    |\n");
		printf(" |--------------------------------|\n");
		printf(" |   FEBRE           |    1       |\n");
		printf(" |   DORES NO CORPO  |    2       |\n");
		printf(" |   CORIZA          |    3       |\n");
		printf(" |   TOSSE           |    4       |\n");
		printf(" |   DIARRÉIA        |    5       |\n");
		printf(" |   DOR DE CABEÇA   |    6       |\n");
		printf(" |   FALTA DE AR     |    7       |\n");
		printf(" |   DOR DE GARGANTA |    8       |\n");
		printf(" |--------------------------------|\n");
		printf(" |   FINALIZAR       |    9       |\n");
		printf(" |___________________|____________|\n\n");
		
		printf("\n Informe um dos sintomas para o vírus COVID-19 listados acima: ");
		scanf("%d", &opcao);
		textcolor(WHITE);
		
		// Verifica se o sintoma já informado anteriormente para o mesmo paciente
		for (i = 0; i < 10; i++) { 
			if (dadosPacientes[posicao].sintomas[i] == opcao) {
				flag = 1;
			}
		}
		
		// Mensagem erro, sintoma já informado 
		if (flag == 1) {
			puts("\nO sintoma informado já foi informado anteriormente. Tente novamente.");
			break;
		}
		
		// Mensagem erro, código sintoma inválido
		if (opcao < 1 || opcao > 9) {
			puts("\nO código do sintoma informado é inválido. Tente novamente.");
			break;
		}
		
		// Adiciona sintoma ao vetor
		dadosPacientes[posicao].sintomas[cont] = opcao;
		cont++;
		
	} while(opcao != 9 || cont > 9);

	int covid, gripe, resfriado;
	covid = 0;
	gripe = 0;
	resfriado = 0;

	for (i = 0; i < 10; i++) {	
		switch(dadosPacientes[posicao].sintomas[i]) {
			case 1:
				covid++;
				gripe++;
				resfriado++;
				break;
			case 2:
				gripe++;
				break;
			case 3:
				gripe++;
				resfriado++;
				break;
			case 4:
				covid++;
				gripe++;
				resfriado++;
				break;
			case 6:
				gripe++;
				break;
			case 7:
				covid++;
				break;
			case 8:	
				gripe++;
				resfriado++;
				break;
		}
	}
	
//	printf("\nCOVID = %d", covid);
//	printf("\nGRIPE = %d", gripe);
//	printf("\nRESFRIADO = %d", resfriado);
	
	if (covid == 3) {
		printf("\nO paciente está com COVID-19.");
		qtdeCasosCOVID++;
	} else {
		if (resfriado == 4) {
			printf("\nO paciente está com RESFRIADO.");	
		} else {
			if (gripe > 0) {
				printf("\nO paciente está com GRIPE.");	
			}
		}
	}
}

void exibeCasosCOVID(int qtde, int tam){
	int i, totalIdades;
	float media, percentual;
	char voltar;
	
	percentual = 0;
	totalIdades = 0;
	
	for(i=0;i<qtde;i++){
		totalIdades += dadosPacientes[i].idade;
	}
	
	percentual = (qtdeCasosCOVID/qtde)*100;
	media = totalIdades/qtde;
	
	printf("\nPacientes com suspeitas de vírus COVID = %d", qtdeCasosCOVID);
	printf("\nTotal de Pacientes = %d", qtde);
	printf("\nPercentual de pacientes com COVID = %.2f%%", percentual);
	printf("\nMédia de idade dos pacientes com COVID = %.2f", media);
	
	printf("\n");
	printf("\n");
	printf("Pressione qualquer tecla para voltar ao menu... ");
	fflush(stdin);
	scanf("%c", &voltar);
	menu(qtde, tam);	
}

main() {
	setlocale(LC_ALL, "Portuguese");
	int qtde, tam;
	qtde = 0;
	tam = 0;        
	qtdeCasosCOVID = 0;                                                
	menu(qtde, tam);

	getch();
	return 0; 
}
