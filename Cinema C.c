#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <windows.h>
void configuracaoInicial(float *valorIngresso, char nomeFilme[100], int *totalPoltronas);
float leValidaValor();
void leValidaFilme(char *nomeFilme);
int leValidaTotalPoltronas();
void exibeMenu(char poltronas[500], int totalPoltronas, int poltronasPorFila, int reservas[500],  int *ctrlReserva, float valorIngresso, float ingressos[500]);
void exibeOcupacaoSala(char poltronas[500], int totalPoltronas, int poltronasPorFila, int reservas[500],  int *ctrlReserva, float valorIngresso, float ingressos[500]);
void realizaReserva(char poltronas[500], int totalPoltronas, int poltronasPorFila, int reservas[500],  int *ctrlReserva, float valorIngresso, float ingressos[500]);
void cancelarReserva(char poltronas[500], int totalPoltronas, int poltronasPorFila, int reservas[500],  int *ctrlReserva, float valorIngresso, float ingressos[500]);
int leValidaIdade();
char leValidaCategoria();
float calculaIngresso(float valorIngresso, int idade, char categoria);
void confirmarVenda(char poltronas[500], int totalPoltronas, int poltronasPorFila, int reservas[500],  int *ctrlReserva, float valorIngresso, float ingressos[500]);
void relatorioVendas(char poltronas[500], int totalPoltronas, int poltronasPorFila, int reservas[500],  int *ctrlReserva, float valorIngresso, float ingressos[500]);

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

main(){
	// Síntese
	//  Objetivo: Criar um programa de cinema para a empresa CINEMAX que solicite o valor do ingresso, o nome do filme e o tamanho da sala. Exibe o menu para apresentação da sala, fazer reserva, cancelar reserva, confirmar venda e relatório de vendas. E depois exibir a quantidade de poltronas disponíveis, reservadas, confirmadas e total de vendas
	//  Entrada : Valor do ingresso, nome do filme, total de poltronas, exibir sala, fazer reserva, cancelar reserva, confirmar compra e relatório de vendas
	//  Saída   : Quantidade de cadeiras disponíveis, reservadas, confirmadas e a quantidade de compras confirmadas

	// Declarações
	setlocale(LC_ALL, "Portuguese");
	int cont, totalPoltronas, poltronasPorFila, reservas[500], ctrlReserva;	
	float valorIngresso, ingressos[500];
	char nomeFilme[100];
	char poltronas[500];

	// Obtém as configurações iniciais para o cinema
	printf("\n\n\n\n\n\n"); 
	textcolor(YELLOW);  
	printf("\t\t\t\tIniciando sistema...");
	Sleep(2000);
	system("cls");
	printf("\t\t\t\t\t\tBEM VINDO AO \n");                                               
	printf("\t\t\t\t ____   ____   ____   ____   ____   ____   ____ \n");
	printf("\t\t\t\t||C || ||I || ||N || ||E || ||M || ||A || ||X ||\n");
	printf("\t\t\t\t||__|| ||__|| ||__|| ||__|| ||__|| ||__|| ||__||\n");
	printf("\t\t\t\t|/__\\| |/__\\| |/__\\| |/__\\| |/__\\| |/__\\| |/__\\|\n");                                                                                                                                                             
	textcolor(WHITE); 
	Sleep(2000);      
	system("cls");                                                                                                             	                                                                                                                                                                                     
	configuracaoInicial(&valorIngresso, &nomeFilme, &totalPoltronas);
	poltronasPorFila = 10;
	for(cont=0;cont<=totalPoltronas-1;cont++){
		poltronas[cont]='D';
	}
	ctrlReserva=1;
	//
	exibeMenu(poltronas, totalPoltronas, poltronasPorFila, reservas, &ctrlReserva, valorIngresso, ingressos);
}

/*
 * configuracaoInicial()
 * Procedimento responsável por ler as informaçoes ou configurações iniciais necessárias
 * referente ao cinema para execução correta do programa
 */
void configuracaoInicial(float *valorIngresso, char nomeFilme[100], int *totalPoltronas)
{
	char voltar;
	textcolor(YELLOW);
	puts("CONFIGURAÇÃO INICIAL ");
	puts("----------------------------------------------------------------------");
	textcolor(WHITE);	
	*valorIngresso = leValidaValor();
	leValidaFilme(nomeFilme);
	*totalPoltronas = leValidaTotalPoltronas();
	puts("");
	puts("");
	textcolor(LIGHTBLUE);
	puts("DADOS REGISTRADOS");
	printf("\nVALOR DO INGRESSO = %2.f", *valorIngresso);
	printf("\nNOME DO FILME = %s", nomeFilme);
	printf("\nTOTAL DE POLTRONAS = %d", *totalPoltronas);
	textcolor(WHITE);
	puts("");
	puts("");
	puts("PRESSIONE QUALQUER TECLA PARA CONTINUAR: ");
	fflush(stdin);
	scanf("%c", &voltar);
}

/*
 * leValidaValor()
 * Função responsável por ler o valor do ingressso, realizando as validações de
 * valores permitidos e retornando o valor já validado
 */
float leValidaValor()
{ 
	float ingresso;
	do{
		puts("INFORME O VALOR DO INGRESSO (R$) :");
		scanf("%f", &ingresso);
		if(ingresso <= 0){
			puts("O VALOR DO INGRESSO É INVÁLIDO. TENTE NOVAMENTE.");
		}
	}while(ingresso <= 0);
	return ingresso;
}

/*
 * leValidaFilme()
 * Função responsável por ler o nome do filme, realizando as validações de
 * valores permitidos e retornando o valor já validado
 */
void leValidaFilme(char *nomeFilme)
{
	int i;
	do{
		puts("INFORME O NOME DO FILME: ");
		fflush(stdin);
		gets(nomeFilme);
		for(i=0; nomeFilme[i]!='\0'; i++){
			nomeFilme[i]=toupper(nomeFilme[i]);
		}
		if(strcmp(nomeFilme,"") == 0){
			puts("NÃO PODE SER VAZIO. TENTE NOVAMENTE.");
		}
	}while(strcmp(nomeFilme,"") == 0);
}

/*
 * leValidaTotalPoltronas()
 * Função responsável por ler a quantidade de poltronas disponíveis na sala, realizando
 *  as validações de valores permitidos e retornando o valor já validado
 */
int leValidaTotalPoltronas()
{
	int quantidade;
	do{
		puts("INFORME O TOTAL DE POLTRONAS DISPONÍVEIS NA SALA (MIN. 100/ MÁX.499): ");
		scanf("%i", &quantidade);
		if(quantidade<100 || quantidade>499){
			puts("QUANTIDADE DE POLTRONAS INVÁLIDA. TENTE NOVAMENTE.");
		}
	}while(quantidade<100 || quantidade>499);
	return quantidade;
}

/*
 * exibeMenu() 
 * Procedimento responsável por exibir o menu geral com as opções disponíveis ao usuário final
 * para: visualizar ocupação, realizar reserva, cancelar reserva, confirmar venda ou relatório
 * com as vendas já realizadas
 */
void exibeMenu(char poltronas[500], int totalPoltronas, int poltronasPorFila, int reservas[500],  int *ctrlReserva, float valorIngresso, float ingressos[500]) {
	int opcao;	
	do{	
		system("cls");
		textcolor(YELLOW);   
		puts("MENU PRINCIPAL");
		puts("----------------------------------------------------------------------");
		puts(" (1) VIZUALIZAR OCUPAÇÃO DA SALA");
		puts(" (2) EFETUAR RESERVA");
		puts(" (3) CANCELAR RESERVA");
		puts(" (4) CONFIRMAR VENDA");
		puts(" (5) RELATÓRIO DE VENDAS");
		puts("");
		puts("INFORME A OPÇÃO DESEJADA");
			
		scanf("%i", &opcao);
		if(opcao < 1 || opcao > 5){
			puts("OPÇÃO INVÁLIDA. TENTE NOVAMENTE");
		}
	}while (opcao < 1 || opcao > 5);

	switch(opcao){
		case 1:
				exibeOcupacaoSala(poltronas, totalPoltronas, poltronasPorFila, reservas, ctrlReserva, valorIngresso, ingressos);			
				break;	
		case 2:
				realizaReserva(poltronas, totalPoltronas, poltronasPorFila, reservas, ctrlReserva, valorIngresso, ingressos);
				break;	
		case 3:
				cancelarReserva(poltronas, totalPoltronas, poltronasPorFila, reservas, ctrlReserva, valorIngresso, ingressos);
				break;	
		case 4:
				confirmarVenda(poltronas, totalPoltronas, poltronasPorFila, reservas, ctrlReserva, valorIngresso, ingressos);
				break;	
		case 5:
				relatorioVendas(poltronas, totalPoltronas, poltronasPorFila, reservas, ctrlReserva, valorIngresso, ingressos);
				break;
	}
}

/*
 *exibeOcupacaoSala
 *procedimento responsável por mostrar a sala de cinema com cadeiras disponivéis, reservadas ou compradas
 *e voltar a acessar o menu 
 */
void exibeOcupacaoSala(char poltronas[500], int totalPoltronas, int poltronasPorFila, int reservas[500],  int *ctrlReserva, float valorIngresso, float ingressos[500])
{ 
	int cont1, cont2, linhas, colunas;
	char voltar;

	colunas = poltronasPorFila;
	linhas = (totalPoltronas / poltronasPorFila);
	if((totalPoltronas % poltronasPorFila) != 0){
		linhas = linhas + 1;
	}
	system("cls");
	textcolor(YELLOW);
	puts("OCUPAÇÃO DA SALA ");
	puts("----------------------------------------------------------------------");
	textcolor(WHITE);	
	for(cont1=1; cont1<=linhas; cont1++){
		for(cont2=1; cont2<=colunas; cont2++){
			if((cont1-1)*poltronasPorFila+cont2 <= totalPoltronas){
				printf("%d", (cont1-1)*poltronasPorFila+cont2);
				if((cont1-1)*poltronasPorFila+cont2<10){
					printf("  ");
				}else
					if((cont1-1)*poltronasPorFila+cont2>=10 && (cont1-1)*poltronasPorFila+cont2<100){
						printf(" ");
					}
				printf(" [ ");
				if (poltronas[(cont1-1)*poltronasPorFila+cont2-1] == 'D') {
					textcolor(LIGHTGREEN);
					printf("%c", 'D');					
				} 
				else {
					if (poltronas[(cont1-1)*poltronasPorFila+cont2-1] == 'R') {
						textcolor(LIGHTRED);
						printf("%c", 'R');					
					} 
					else {
						textcolor(LIGHTCYAN);
						printf("%c", 'C');					
					}
				}
				textcolor(WHITE);
				printf(" ] ");
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	printf("PRESSIONE QUALQUER TECLA PARA CONTINUAR: ");
	fflush(stdin);
	scanf("%c", &voltar);
	exibeMenu(poltronas, totalPoltronas, poltronasPorFila, reservas, ctrlReserva, valorIngresso, ingressos);
}

/*
 * realizaReserva()
 * procedimento que realiza a reserva de determinada poltrona indicada pelo comprador, 
 * colocando a opção de R - reservada onde estava D - disponível e acessa o menu novamente
 */
void realizaReserva(char poltronas[500], int totalPoltronas, int poltronasPorFila, int reservas[500],  int *ctrlReserva, float valorIngresso, float ingressos[500])
{

	int local, flag;
	char voltar;
	system("cls");
	textcolor(YELLOW);
	puts("EFETUAR RESERVA ");
	puts("----------------------------------------------------------------------");
	textcolor(WHITE);	
	do{
		flag=0;
		puts("INFORME A POLTRONA QUE DESEJA RESERVAR: ");
		scanf("%i", &local);
		if(local>=1 && local<=totalPoltronas){
			if(poltronas[local-1]=='D'){
				poltronas[local-1]='R';
				reservas[*ctrlReserva-1]=local-1;
				printf("RESERVA EFETUADA, Nº = %d", *ctrlReserva);
				*ctrlReserva=*ctrlReserva+1;
			}else
				{
					puts("A POLTRONA INFORMADA NÃO ESTÁ DISPONÍVEL.");
					flag=1;
				}
		}else
			{
				puts("NÚMERO DA POLTRONA INVÁLIDO.");
				flag=1;
			}
	}while(flag==1);
	puts("");
	puts("");
	puts("PRESSIONE QUALQUER TECLA PARA CONTINUAR: ");
	fflush(stdin);
	scanf("%c", &voltar);
	exibeMenu(poltronas, totalPoltronas, poltronasPorFila, reservas, ctrlReserva, valorIngresso, ingressos);
}

/*
 * cancelarReserva()
 * procedimento que realiza o cancelamento da reserva de uma poltrona a partir do seu código de reserva
 * mudando de R - reserva para D - disponível e voltando ao menu
 */
void cancelarReserva(char poltronas[500], int totalPoltronas, int poltronasPorFila, int reservas[500],  int *ctrlReserva, float valorIngresso, float ingressos[500])
{

	int cod, flag;
	char voltar;
	system("cls");
	textcolor(YELLOW);
	puts("CANCELAR RESERVA ");
	puts("----------------------------------------------------------------------");
	textcolor(WHITE);	
	do{
		flag=0;
		puts("INFORME O CÓDIGO DE RESERVA PARA CANCELAR: ");
		scanf("%i", &cod);
		if(cod<=*ctrlReserva){
			if(poltronas[reservas[cod-1]]=='R'){
				poltronas[reservas[cod-1]]='D';
				reservas[cod-1]=0;
				printf("RESERVA Nº %d CANCELADA.", cod);
			}else
			{
				puts("A RESERVA NÃO EXISTE OU JÁ FOI CONFIRMADA.");
				flag=1;
			}
		}else
		{
			puts("CÓDIGO DA RESERVA INFORMADA É INVÁLIDO.");
			flag=1;
		}
	}while(flag==1);
	puts("");
	puts("");
	puts("PRESSIONE QUALQUER TECLA PARA CONTINUAR: ");
	fflush(stdin);
	scanf("%c", &voltar);
	exibeMenu(poltronas, totalPoltronas, poltronasPorFila, reservas, ctrlReserva, valorIngresso, ingressos);
}

/*
 * leValidaIdade()
 * função que le e valida a idade do comprador não sendo a idade menor que 1 ano
 */
 int leValidaIdade()
 {

	int idade;
	do{
		puts("INFORME A IDADE DO COMPRADOR: ");
		scanf("%i", &idade);
		if(idade<1)
			puts("IDADE INFORMADA INVÁLIDA. TENTE NOVAMENTE.");
	}while(idade<1);
	return idade;
}

/*
 * leValidaCategoria
 * função que le e valida a categoria de desconto do comprador sendo elas:
 * (E - estudantes, P - pessoas com deficiência, I - idosos, D - doadores de sangue ou N - Nenhum benefício de desconto)
 */
char leValidaCategoria()
{
	char cat;
	do{
		
		puts("INFORME A CATEGORIA DE DESCONTO => (E - ESTUDANTES, P - PESSOAS COM DEFICIÊNCIA, I - IDOSOS, D - DOADORES DE SANGUE ou N - NENHUM BENEFÍCIO DE DESCONTO): ");
		cat=getche();
		cat=toupper(cat);
		if(cat!='E' && cat!='P' && cat!='I' && cat!='D' && cat!='N')
			puts("ESCOLHA DE CATEGORIA INFORMADA INVÁLIDA.");
	}while(cat!='E' && cat!='P' && cat!='I' && cat!='D' && cat!='N');
	return cat;
}

/*
 * calculaIngresso()
 * função que calcula o valor do ingresso para aplicar o desconto de 50% caso o comprador tenha
 * um dos benefícios (E - estudantes, P - pessoas com deficiência, I - idosos, D - doadores de sangue ou N - Nenhum benefício de desconto)
 * ou idade menor ou igual a 12 anos
 */
float calculaIngresso(float valorIngresso, int idade, char categoria)
{
	if(idade<=12 || categoria=='E' || categoria=='P' || categoria=='I' || categoria=='D'){
		return valorIngresso*0.5;
	}else
	{		
		return valorIngresso;
	}
}
/*
 * confirmarVenda()
 * procedimento que confirmar a venda a partir de um código de reserva e 
 * mostrar o valor final do ingresso com desconto ou não dependendo da
 * categoria e volta ao menu
 */
void confirmarVenda(char poltronas[500], int totalPoltronas, int poltronasPorFila, int reservas[500],  int *ctrlReserva, float valorIngresso, float ingressos[500])
{
	int cod, flag, idade;
	float valorFinal;
	char voltar;
	char categoria;
	system("cls");
	textcolor(YELLOW);
	puts("CONFIRMAR VENDA ");
	puts("----------------------------------------------------------------------");
	textcolor(WHITE);	
	do{
		flag=0;
		puts("DIGITE O CÓDIGO DE RESERVA PARA CONFIRMAR A COMPRA: ");
		scanf("%i", &cod);
		if(cod<*ctrlReserva){
			if(poltronas[reservas[cod-1]]=='R'){
				idade=leValidaIdade();
				categoria=leValidaCategoria();
				valorFinal=calculaIngresso(valorIngresso, idade, categoria);
				poltronas[reservas[cod-1]]='C';
				ingressos[reservas[cod-1]]=valorFinal;
				printf("\nCOMPRA CONFIRMADA COM O VALOR DO INGRESSO R$ = %2.f", valorFinal);
			}else
			{
				puts("A RESERVA NÃO EXISTE OU JÁ FOI CONFIRMADA.");
				flag=1;
			}
		}else
		{
			puts("CÓDIGO DE RESERVA INFORMADO É INVÁLIDO.");
			flag=1;
		}
	}while(flag==1);
	puts("");
	puts("");
	puts("PRESSIONE QUALQUER TECLA PARA CONTINUAR: ");
	fflush(stdin);
	scanf("%c", &voltar);
	exibeMenu(poltronas, totalPoltronas, poltronasPorFila, reservas, ctrlReserva, valorIngresso, ingressos);
}

/*
 * relatorioVendas()
 * procedimento que exibe a quantidade de poltronas disponíveis, reservadas,
 * confirmadas e o total de vendas confirmadas e volta ao menu
 */
void relatorioVendas(char poltronas[500], int totalPoltronas, int poltronasPorFila, int reservas[500],  int *ctrlReserva, float valorIngresso, float ingressos[500])
{

	int cont, contD, contR, contC;
	float totalVendas;
	char voltar;
	char tipoReserva;
	contD=0;
	contR=0;
	contC=0;
	totalVendas=0;
	system("cls");
	textcolor(YELLOW);
	puts("RELATÓRIO VENDAS ");
	puts("----------------------------------------------------------------------");
	textcolor(WHITE);	
	for(cont=0; cont<=totalPoltronas-1; cont++){
		tipoReserva=poltronas[cont];
		switch(tipoReserva){
		case 'D':
				contD=contD+1;
				break;
		case 'R':
				contR=contR+1;
				break;
		case 'C':
				contC=contC+1;
				totalVendas=totalVendas+ingressos[cont];
				break;
		}
	}
	textcolor(LIGHTGREEN);
	printf("\nA QUANTIDADE DE POLTRONAS DISPONÍVEIS É = %d", contD);
	textcolor(LIGHTRED);
	printf("\nA QUANTIDADE DE POLTRONAS COM RESERVA É = %d", contR);
	textcolor(LIGHTCYAN);
	printf("\nA QUANTIDADE DE POLTRONAS COM VENDAS CONFIRMADAS É = %d", contC);
	textcolor(LIGHTGRAY);
	printf("\nO VALOR TOTAL DE VENDAS CONFIRMADAS É = %2.f", totalVendas);
	textcolor(WHITE);
	puts("");
	puts("");
	puts("PRESSIONE QUALQUER TECLA PARA CONTINUAR: ");
	fflush(stdin);
	scanf("%c", &voltar);
	exibeMenu(poltronas, totalPoltronas, poltronasPorFila, reservas, ctrlReserva, valorIngresso, ingressos);
}
