//Aluno: Guilherme Carlos Pascini - UC19201549
//Atividade Avaliativa 1 - Estoque de Farmácia
#include<stdio.h>
#include<locale.h>
#include<windows.h>
#include<string.h>


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

struct dMedicamentos {
	
	int qtMg, qtComp, qtMl, tpMd;
	int disponibilidade, backupDisp;
	int controlador, backupRestore;
	int codMedicamento, backupCodigo;
	float vlrMedicamento, backupValor;
	char descMedicamento[50], backupDesc[50];

};

int codigoMedicamento(int qtd, struct dMedicamentos dadosMed[]) {
	int cod, flag, controle;
	flag=0;
	
	do {
		flag=0;
		printf("Digite o código da Medicação: ");
		scanf("%i", &cod);
		if (cod<0) {
			printf("Código inválido.\n");
		}
		for (controle=0; controle<qtd; controle++) {
			if (cod==dadosMed[controle].codMedicamento) {
				printf("Código já está sendo utilizado, tente novamente. \n");
				flag=1;
			}
		}
	}while(flag==1 || cod<0);

	return cod;
}
	
int qtDisponivel() {
	int qtDisp;
	do {
		printf("\nInforme a quantia disponível: ");
		scanf("%i", &qtDisp);
		if(qtDisp<0) {
			printf("Quantia inválida. ");
		}
	}while(qtDisp<0);
	
	return qtDisp;
}
		
float valorMedicamento() {
	float valor;
	
	do {
		printf("Digite o valor da Medicação: R$ ");
		scanf("%f", &valor);
		if (valor<0) {
			printf("valor inválido. \n");
		}
	} while(valor<0);

	return valor;
}

void tpMed(int qtd, struct dMedicamentos dadosMed[]) {
	int tipo, flag, controle;
	
	do {
		flag=0;
		textcolor(WHITE);
		printf("\nInformações sobre tipo de Medicamento \n\n");
		printf("1 - Comprimidos/Capsulas \n");
		printf("2 - Xarope/Liquido \n\n");
		textcolor(LIGHTMAGENTA);
		printf("Informe qual o tipo de Medicamento: ");
		scanf("%i", &dadosMed[qtd].tpMd);
		if (dadosMed[qtd].tpMd!=1 && dadosMed[qtd].tpMd!=2) {
			printf("Opção inválida, tente novamente. \n");
		}
		for (controle=0; controle<qtd; controle++) {
			if (dadosMed[qtd].tpMd==dadosMed[controle].tpMd && (strcmp(dadosMed[qtd].descMedicamento,dadosMed[controle].descMedicamento)==0)) {
				textcolor(WHITE);
				printf("\nEste medicamento já foi armazenado com este tipo. \n");
				printf("Crie está medicação com outra Caracteristica. \n");
				flag=1;
				textcolor(WHITE);
			}else
				if (dadosMed[qtd].tpMd==dadosMed[controle].tpMd && (strcmp(dadosMed[qtd].descMedicamento,dadosMed[controle].descMedicamento)==0)) {
					printf("\nEste medicamento já foi armazenado com este tipo. \n");
					printf("Crie está medicação com outra Caracteristica. \n");
					flag=1;
					textcolor(WHITE);
				}
		}
	}while(flag==1 || dadosMed[qtd].tpMd!=1 && dadosMed[qtd].tpMd!=2);
	printf("\n");
	textcolor(WHITE);
	switch(dadosMed[qtd].tpMd) {
		case 1:
			do {
				printf("Informe a quantia de COMPRIMIDOS presentes na Cartela do Medicamento: ");
				scanf("%i", &dadosMed[qtd].qtComp);
				if (dadosMed[qtd].qtComp<0) {
					printf("\nQuantia inválida. \n");
					printf("Quantia deve ser superior a 0. \n\n");
				}
			}while(dadosMed[qtd].qtComp<0);
			do {
				printf("Informe quantas MILIGRAMAS < Mg > possuem cada COMPRIMIDO: ");
				scanf("%i", &dadosMed[qtd].qtMg);
				if (dadosMed[qtd].qtMg<0) {
					printf("\nQuantia inválida. \n");
					printf("Quantia deve ser superior a 0. \n\n");
				}	
			}while(dadosMed[qtd].qtMg<0);
			break;
		case 2:
			do {
				printf("Informe a quantia de MILILITRO < Ml > presente na Solução: ");
				scanf("%i", &dadosMed[qtd].qtMl);
				if (dadosMed[qtd].qtMl<0) {
					printf("\nQuantia inválida. \n");
					printf("Quantia deve ser superior a 0. \n");
				}
				printf("\n");
			}while(dadosMed[qtd].qtMl<0);
			break;
	}
}

void descricaoMedicamento(int qtd, struct dMedicamentos dadosMed[]) {
	int flag, controle;
	do {
		printf("Digite o nome do Medicamento: ");
		fflush(stdin);
		gets(dadosMed[qtd].descMedicamento);
		if (strcmp(dadosMed[qtd].descMedicamento,"")==0) {
			printf("Nome do Medicamento não pode ser vazio. \n\n");
		}
	}while(strcmp(dadosMed[qtd].descMedicamento,"")==0);
}


void listaProduto(int qtd, struct dMedicamentos dadosMed[]) {
	int controle;
	float rcVlr;
	
	for(controle=0; controle<qtd; controle++){
		if(dadosMed[controle].codMedicamento != -1) {
			textcolor(LIGHTMAGENTA);		
			printf("Nome do Medicamento: %s\n", dadosMed[controle].descMedicamento);
			printf("Código do Medicamento: %i\n\n", dadosMed[controle].codMedicamento);

			if (dadosMed[controle].tpMd==1) {
				printf("Tipo de Medicamento: Comprimido/Capsulas \n\n");
				textcolor(WHITE);
				printf("Quantia de COMPRIMIDOS presentes na Cartela: %i \n", dadosMed[controle].qtComp);
				printf("Quantia de MILIGRAMAS presentes nos Comprimidos: %i \n\n", dadosMed[controle].qtMg);
			}else
				if (dadosMed[controle].tpMd==2) {
					printf("Tipo de Medicamento: Xarope/Soluções \n\n");
					textcolor(WHITE);
					printf("Quantia de MILILITROS: %i Ml \n\n", dadosMed[controle].qtMl);
				}
			rcVlr=dadosMed[controle].vlrMedicamento*dadosMed[controle].disponibilidade;
			printf("Valor do Medicamento (UND): R$ %.2f - - - Valor da Remessa (TOTAL): R$ %.2f\n", dadosMed[controle].vlrMedicamento, rcVlr);
			printf("Quantia do Medicamento disponível: %i \n\n\n", dadosMed[controle].disponibilidade);
			textcolor(WHITE);
		}
	}
	printf("\n");
}

void consultaProduto(int qtd, struct dMedicamentos dadosMed[]) {
	int controle, controle2, pesq, op, chave;
	float rcVlr;
	int flag, ini, meio, fim, contador;
	
	// Ordenação do vetor de código de medicamento c/ Insertion Sort
	for (controle=0; controle<qtd-1; controle++) {
		chave=dadosMed[controle].codMedicamento;
		for (controle2=qtd-1; controle2>=0 && dadosMed[controle2].codMedicamento>chave; controle2--) {
			dadosMed[controle2+1].codMedicamento = dadosMed[controle2].codMedicamento;
		}
		dadosMed[controle2+1].codMedicamento = chave;
	}
	//
	
	// Apresentação de todos códigos 
	printf("Listagem dos códigos disponíveis para busca... \n\n");
	for(controle = 0; controle < qtd; controle++) {
		printf("%i° COD - N° %i\n", controle+1, dadosMed[controle].codMedicamento);
	}
	//
	
	//Inserção da Pesquisa Binaria ao código de Medicamento
	printf("\nInforme o código do Produto: ");
	scanf("%i", &pesq);
	printf("\n");
	
	flag=0;
	ini=0;
	fim=9;
	meio=(ini+fim)/2;
	contador=0;
	do{
		if(pesq>dadosMed[meio].codMedicamento){
			ini=meio+1;
			meio=(ini+fim)/2;
		}else
			if(pesq<dadosMed[controle].codMedicamento){
				fim=meio-1;
				meio=(ini+fim)/2;
			}else
				flag=1;
		contador=contador+1;
	}while(fim>=ini && flag==0);
	
	if(flag==0){
		printf("\nCódigo não encontrado.");
	}else
		printf("Código encontrado na posição: %i", meio+1);
		printf("\n");
		printf("Quantidade de entradas no laço: %i\n\n", contador);
	//

	for(controle = 0; controle < qtd; controle++) {
		if(pesq == dadosMed[controle].codMedicamento) {
			textcolor(LIGHTMAGENTA);
			printf("Nome do Medicamento: %s\n", dadosMed[controle].descMedicamento);
			printf("Código do Medicamento: %i\n", dadosMed[controle].codMedicamento);
			printf("\n");
			textcolor(WHITE);
			if (dadosMed[controle].tpMd==1) {
				printf("Tipo de Medicamento: Comprimido/Capsulas \n\n");
				textcolor(WHITE);
				printf("Quantia de COMPRIMIDOS presentes na Cartela: %i \n", dadosMed[controle].qtComp);
				printf("Quantia de MILIGRAMAS presentes nos Comprimidos: %i \n\n", dadosMed[controle].qtMg);
			}else
				if (dadosMed[controle].tpMd==2) {
					printf("Tipo de Medicamento: Xarope/Soluções \n\n");
					textcolor(WHITE);
					printf("Quantia de MILILITROS: %i Ml \n", dadosMed[controle].qtMl);
				}
			textcolor(LIGHTMAGENTA);
			printf("\n");
			printf("Quantia do Medicamento disponível: %i \n\n", dadosMed[controle].disponibilidade);
			textcolor(WHITE);
			printf("Valor do Medicamento (UND): R$ %.2f\n", dadosMed[controle].vlrMedicamento);	
		}
	}
}

int calcRemessa(int qtd, struct dMedicamentos dadosMed[]) {
	if(qtd == 1)
	{
		return 1;
	}
	return calcRemessa(dadosMed, qtd-1) + dadosMed[qtd-1].vlrMedicamento;
}

void alteraProduto(int qtd, struct dMedicamentos dadosMed[]) {
	int controle, pesq, menu, menu2;
	float percentA, percentD, p1, soma;

	printf("Informe o código do Produto que deseja alterar: ");
	scanf("%i", &pesq);
	printf("\n");
	for(controle = 0; controle < qtd; controle++)	{
		if(pesq == dadosMed[controle].codMedicamento && dadosMed[controle].codMedicamento != -1) {
			textcolor(WHITE);
			printf("Nome do Medicamento: %s\n", dadosMed[controle].descMedicamento);
			printf("Valor do Medicamento: R$ %.2f\n", dadosMed[controle].vlrMedicamento);
			
			textcolor(LIGHTMAGENTA);
			printf("Quantia do Medicamento disponível: %i \n\n", dadosMed[controle].disponibilidade);
			
			textcolor(WHITE);
			printf("COD 1. - Alterar a Quantia de < %s > disponível. \n", dadosMed[controle].descMedicamento);
			printf("COD 2. - Alterar o valor do Medicamento. \n\n");
			printf("Informe o que deseja realizar: ");
			scanf("%i", &menu);
			fflush(stdin);
			printf("\n");
			switch(menu) {
				case 1:
					textcolor(DARKGRAY);
					printf("Digite a <NOVA> quantia de < %s > disponível: ", dadosMed[controle].descMedicamento);
					scanf("%i", &dadosMed[controle].disponibilidade);
					break;
				case 2:
					textcolor(DARKGRAY);
					printf("COD 1. - Aumentar Valor \n");
					printf("COD 2. - Diminuir Valor \n\n");
					printf("Informe o que deseja realizar: ");
					scanf("%i", &menu2);
					printf("\n");
					textcolor(WHITE);
					switch(menu2) {
						case 1:
							printf("Digite o percentual de AUMENTO do valor do Medicamento:  ");
							scanf("%f", &percentA);
							p1= (dadosMed[controle].vlrMedicamento + (dadosMed[controle].vlrMedicamento/100)*percentA);
							dadosMed[controle].vlrMedicamento=p1;
			 				printf("Novo valor do Medicamento: %.2f \n", dadosMed[controle].vlrMedicamento);
							Sleep(3000);
							break;
			 			case 2:
			 				printf("Digite o percentual de DIMINUIÇÃO do valor do Medicamento: ");
			 				scanf("%f", &percentD);
							p1= (dadosMed[controle].vlrMedicamento - (dadosMed[controle].vlrMedicamento/100)*percentD);
			 				soma= dadosMed[controle].vlrMedicamento+p1;
			 			 	dadosMed[controle].vlrMedicamento=p1;
			 				printf("Novo valor do Medicamento: %.2f \n", dadosMed[controle].vlrMedicamento);
			 				Sleep(3000);
							break;
			 		}
			}
		}
	}
}

void remocaoMedicamento(int qtd, struct dMedicamentos dadosMed[]) {
	int cod, var, var2, pos;
	int controle;
	char descricao[100];

	fflush(stdin);
	printf("Informe o código que deseja remover: ");
	scanf("%i", &cod);
	for (var=0; var<=qtd; var++) {
		if (cod==dadosMed[var].codMedicamento) {
			dadosMed[var].codMedicamento=-1;
		}
	}

	printf("\n");
	printf("Remoção concluida.\n\n");
}

void backupSystem(int qtd, struct dMedicamentos dadosMed[]) {
	int controle, backup;

	for(controle=0; controle<qtd; controle++) {
		dadosMed[controle].backupCodigo=dadosMed[controle].codMedicamento;
		dadosMed[controle].backupValor=dadosMed[controle].vlrMedicamento;
		dadosMed[controle].backupDisp=dadosMed[controle].disponibilidade;
		strcpy(dadosMed[controle].backupDesc, dadosMed[controle].descMedicamento);
	}

	printf("Backup realizado com sucesso.\n\n");
}

void restoreSystem(int qtd, struct dMedicamentos dadosMed[]) {
	int restore;

	for(restore=0; restore<qtd; restore++) {
		dadosMed[restore].codMedicamento=dadosMed[restore].backupCodigo;
		dadosMed[restore].vlrMedicamento=dadosMed[restore].backupValor;
		dadosMed[restore].disponibilidade=dadosMed[restore].backupDisp;
		strcpy(dadosMed[restore].descMedicamento, dadosMed[restore].backupDesc);
	}
	printf("Sistema reintegrado com sucesso.\n\n");
}

void apresentacao () {
	char op;
	textcolor(LIGHTMAGENTA);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t  ___          _           _        ___                     __      _              \n");
	printf("\t\t\t\t\t | _ \\ ___  __| | ___   __| | ___  | __|__ _  _ _  _ __   _/_/  __ (_) __ _  ___   \n");
	printf("\t\t\t\t\t |   // -_)/ _` |/ -_) / _` |/ -_) | _|/ _` || '_|| '  \\ / _` |/ _|| |/ _` |(_-<   \n");
	printf("\t\t\t\t\t |_|_\\\\___|\\__,_|\\___| \\__,_|\\___| |_| \\__,_||_|  |_|_|_|\\__,_|\\__||_|\\__,_|/__/   \n");
	printf("\t\t\t\t\t                                                                                   \n");
	printf("\t\t\t\t\t                ___                                                                \n");
	printf("\t\t\t\t\t               | __|__ _  _ _  _ __   __ _ __ __                                   \n");
	printf("\t\t\t\t\t               | _|/ _` || '_|| '  \\ / _` |\\ \\ /                                   \n");
	printf("\t\t\t\t\t               |_| \\__,_||_|  |_|_|_|\\__,_|/_\\_\\                                   \n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	textcolor(DARKGRAY);
	printf("Pressione qualquer tecla para avançar... ");    
	fflush(stdin);
	op=getche();     
}

int menu() {
	int opcaoMenu;
	textcolor(WHITE);
	printf("Rede de Farmácias - FARMAX ©\n\n");
	printf("Sistema de Estoque de Medicamentos\n\n");
	printf("Informe a opção desejada \n\n");
	printf("\n");
	textcolor(LIGHTMAGENTA);
	printf("Incluir um Medicamento ao Estoque  --> COD. 1 \n");
	printf("Listar Medicamentos disponíveis    --> COD. 2 \n");
	printf("Consultar Medicamento              --> COD. 3 \n");
	printf("Alterar dados de um Medicamento    --> COD. 4 \n");
	printf("Excluir Medicamento do Estoque     --> COD. 5 \n\n\n");
	textcolor(WHITE);
	printf("Armazenar dados do Sistema         --> COD. 6 \n");
	printf("Restaurar dados do Sistema         --> COD. 7 \n\n\n");
	textcolor(DARKGRAY);
	printf("Finalizar Programa                 --> COD. 0 \n\n");
	printf("\n");
	textcolor(WHITE);
	printf("Digite a sua opção: ");
	scanf("%i", &opcaoMenu);

	return opcaoMenu;
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	int qtd=0, opcaoMenu, backupQtd;
	struct dMedicamentos pMed[50];

	apresentacao ();
	system("cls");
	do {
		opcaoMenu=menu();
		system("cls");
		fflush(stdin);
		switch(opcaoMenu) {
			case 1:
				printf("Sistema de Armazenamento de Medicamentos\n\n");
				descricaoMedicamento(qtd, pMed);
				tpMed(qtd, pMed);
				pMed[qtd].vlrMedicamento=valorMedicamento();
				pMed[qtd].codMedicamento=codigoMedicamento(qtd, pMed);
				pMed[qtd].disponibilidade=qtDisponivel();
				qtd++;
				break;
			case 2:
				printf("Sistema de Listagem de Medicamentos\n\n");
				listaProduto(qtd, pMed);
				Sleep(5000);
				break;
			case 3:
				printf("Sistema de Consulta de Medicamentos\n\n");
				consultaProduto(qtd, pMed);
				printf("Valor do Medicamento (REMESSA): R$ %.2f\n", calcRemessa(qtd, pMed));
				Sleep(5000);
				break;
			case 4:
				printf("Sistema de Alteração de Medicamentos\n\n");
				alteraProduto(qtd, pMed);
				break;
			case 5:
				printf("Sistema de Remoção de Medicamentos\n\n");
				remocaoMedicamento(qtd, pMed);
				Sleep(1500);
				break;
			case 6:
				printf("Sistema de Backup de Medicamentos\n\n");
				backupSystem(qtd, pMed);
				backupQtd=qtd;
				Sleep(1500);
				break;
			case 7:
				printf("Sistema de Restauração de Medicamentos\n\n");
				restoreSystem(qtd, pMed);
				qtd=backupQtd;
				Sleep(1500);
				break;
		}
		system("cls");
	} while(opcaoMenu!=0);
	Sleep(150000);
}

