#include <stdio.h> 
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

struct FichaPacientes {
	int codigo, idade, sintomas[10];
	char nome[100], cidade[100], sexo;
};

int menu();
int receberCodigo();
void receberDados(struct FichaPacientes*);
void mostrarDados(struct FichaPacientes);

void incluir() {
    struct FihaPacientes dados;
    FILE *arq = fopen("FichaMédica.txt","a");
    if (arq == NULL) {
        printf("Erro de abertura!");
        exit(1);
    }
   dados.codigo = receberCodigo();
    receberDados(&dados);
    fprintf(arq, "%d,%s,%d,%c,%s\n", dados.codigo, dados.nome, dados.idade, dados.sexo, dados.cidade);
    fclose(arq);
    FILE *arq = fopen("FichaMédicaB.dat", "ab");
    if (arq == NULL) {
        printf("Erro de abertura!");
        exit(1);
    }
    fwrite(&dados,sizeof(dados),1,arq);
    fclose(arq);
}

void listar() {
    struct FichaPacientes dados;
    FILE *arq = fopen("FichaMédica.txt","r");
    if (arq == NULL) {
        printf("Erro de abertura!\n");
        exit(1);
    }
    printf("Cod   Nome   Idade   Sexo   Cidade\n");
    printf("--- - ---- - ----- - ---- - ---------\n");
    while (fscanf(arq, "%d,%s,%d,%c,%s\n", dados.codigo, dados.nome, dados.idade, dados.sexo, dados.cidade) != -1){
        printf("%d - %s - %d - %c - %s\n", dados.codigo, dados.nome, dados.idade, dados.sexo, dados.cidade);
    }
    fclose(arq);
}

void consultar() {
    struct FichaPacientes dados;
    int codigo, achei=0;
    FILE *arq = fopen("FichaMédica.txt","r");
    if (arq == NULL) {
        printf("Erro de abertura!");
        exit(1);
    }
    codigo = receberCodigo();
    while (fscanf(arq, "%d,%s,%d,%c,%s\n", dados.codigo, dados.nome, dados.idade, dados.sexo, dados.cidade) != -1){
        if (dados.codigo == codigo) {
            mostrarProduto(produto);
            achei=1;
        }
    }
    if (!achei)
        printf("Código nao encontrado!\n");
    fclose(arq);
}

void alterar(){
	struct FichaPacientes dados;
    int codigo, achei=0;
    FILE *arq = fopen("FichaMédica.txt","r");
    if (arq == NULL) {
        printf("Erro de abertura!");
        exit(1);
    }
    while (fscanf(arq, "%d,%s,%d,%c,%s\n", dados.codigo, dados.nome, dados.idade, dados.sexo, dados.cidade) != -1){
    	if(codigo==dados.codigo){
    	mostrarDados(dados);
    	fseek(arq,-sizeof(dados),SEEK_CUR);
    	fprintf(arq, "%d,%s,%d,%c,%s\n", dados.codigo, dados.nome, dados.idade, dados.sexo, dados.cidade)
    	fseek(arq,0,SEEK_CUR);
    	achei = 1;
		}
	}
	if (!achei)
        printf("Código nao encontrado!\n");
    fclose(arq);
}

main() {
	setlocale(LC_ALL, "Portuguese");
	int opcao;
    do {
        opcao = menu();
        switch (opcao) {
            case 1:
                printf("\n\n*** Inclusao ***\n");
                incluir();
                break;
            case 2:
                printf("\n\n*** Listagem ***\n");
                listar();
                break;
            case 3:
                printf("\n\n*** Consulta ***\n");
                consultar();
                break;
            case 4:
                printf("\n\n*** Altera ***\n");
                alterar();
                break;
            case 5:
            	printf("\n\n*** Casos COVID-19 ***\n");
            	casos();
            	break;
		}
    } while (opcao != 0);
    return 0;                                                  
	Sleep(150000);
}

void menu(void) {
	int op;
	do {
		printf("\n\n\n\t+++ DADOS MÉDICOS +++\n\n\n");
		printf(" ________________________________\n");
		printf("|       OPÇÃO       |   CÓDIGO   |\n");
		printf("|                   |            |\n");
		printf("|  CRIAR FICHAS     |     1      |\n");
		printf("|  LISTAR FICHAS    |     2      |\n");
		printf("|  CONSULTAR FICHAS |     3      |\n");	
		printf("|  ALTERAR FICHAS   |     4      |\n");
		printf("|  CASOS COVID-19   |     5      |\n");
		printf("|  SAIR DO PROGRAMA |     6      |\n");
		printf("|___________________|____________|\n\n");
		printf("Digite sua opção: ");
		scanf("%d", &op);
		if(op<1 || op>6)
			puts("\nOpção digitada é inválida. Tente novamente.");	
	} while(op<1 || op>6);
	return op;
}

int receberCodigo() {
    int codigo;
    printf("Informe o código do paciente: ");
    scanf("%d", &codigo);
    return codigo;
}

void receberDados(struct FichaPacientes *dados) {
    printf("Informe o nome do paciente: ");
    fflush(stdin);
    scanf("%s", (*dados).nome);
    printf("Informe a idade do paciente: ");
    scanf("%d", &((*dados).idade));
    printf("Informe o sexo do paciente: ");
    fflush(stdin);
    scanf("%c", &((*dados).sexo));
    printf("Informe a cidade do paciente: ");
    fflush(stdin);
    scanf("%s", (*dados).cidade);
}

void mostrarDados(struct FichaPacientes *dados){
	printf("Nome: %s/n", dados.nome);
	printf("Idade: %d/n", dados.idade);
	printf("Sexo: %c/n", dados.sexo);
	printf("Cidade: %s/n", dados.cidade);
}
