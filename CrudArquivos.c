#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

// Declaracao de tipo
struct tProduto {
    int codigo;
    char descricao[20];
    float valor;
};

int menu();
int receberCodigo();
void receberDados(struct tProduto*);
void mostrarProduto(struct tProduto);

void incluir() {
    struct tProduto produto;
    FILE *arq = fopen("produto.txt","a");
    if (arq == NULL) {
        printf("Erro de abertura!");
        exit(1);
    }
    produto.codigo = receberCodigo();
    receberDados(&produto);
    fprintf(arq, "%f,%i,%s\n", produto.valor, produto.codigo, produto.descricao);
    fclose(arq);
}

void listar() {
    struct tProduto produto;
    FILE *arq = fopen("produto.txt","r");
    if (arq == NULL) {
        printf("Erro de abertura!\n");
        exit(1);
    }
    printf("Cod   Descricao              Valor\n");
    printf("--- - -------------------- - ----------\n");
    while (fscanf(arq, "%f,%i,%s\n", &produto.valor, &produto.codigo, produto.descricao) != -1){
        printf("%d - %s - R$ %f\n", produto.codigo, produto.descricao, produto.valor);
    }
    fclose(arq);
}

void consultar() {
    struct tProduto produto;
    int codigo, achei=0;
    FILE *arq = fopen("produto.txt","r");
    if (arq == NULL) {
        printf("Erro de abertura!");
        exit(1);
    }
    codigo = receberCodigo();
    while (fscanf(arq, "%f,%i,%s\n", &produto.valor, &produto.codigo, produto.descricao) != -1){
        if (produto.codigo == codigo) {
            mostrarProduto(produto);
            achei=1;
        }
    }
    if (!achei)
        printf("Codigo nao encontrado!\n");
    fclose(arq);
}

void excluir(){
    struct tProduto produto, produtos[100];
    int i, codigo, posicao = 0, achei = 0;
    FILE *arq = fopen("produto.txt","r");

    if (arq == NULL) {
        printf("Erro de abertura!");
        exit(1);
    }
    codigo = receberCodigo();

    while (fscanf(arq, "%f,%i,%s\n", &produto.valor, &produto.codigo, produto.descricao) != -1){
        if(codigo != produto.codigo){
            produtos[posicao] = produto;
            posicao++; 
        }else
            achei=1;
    }
    fclose(arq);

    if(achei){
        arq = fopen("produto.txt", "w");
      
        if(!arq){
            printf("Erro na abertura!\n");
            exit(1);
        }

        for(i=0; i<posicao; i++){
           produto = produtos[i]; 
           fprintf(arq, "%f,%i,%s\n", produto.valor, produto.codigo, produto.descricao);
        }
        fclose(arq);
    } 
}

void excluirFisica(){
	struct tProduto prod;
	FILE *arq;
	arq = fopen("produto.txt", "r");
	if (arq == NULL) {
		printf("Erro de abertura do arquivo!\n");
		exit(1);
	}
	fscanf(arq, "%f,%i,%s\n", &prod.valor, &prod.codigo, prod.descricao);
	fclose(arq);
	remove("produto.txt");
}


int main() {
    setlocale(LC_ALL,"Portuguese");
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
                printf("\n\n*** Exclusão (LINHA)***\n");
                excluir();
                break;
            case 5:
                printf("\n\n*** Exclusão (FÍSICA)***\n");
                excluirFisica();    
                break;
		}
    } while (opcao != 0);
    return 0; 
}

//--- Menu ---------------------------------------------------------------
int menu(void) {
    int op;
    printf("\n\n*** MENU ***\n\n");
    printf("1. Inclusao\n");
    printf("2. Listagem\n");
    printf("3. Consulta\n");
    printf("4. Exclusao LINHA\n");
    printf("5. Exclusao FÍSICA\n");
    printf("0. Sair\n\n");
    printf("Digite sua opcao: ");
    scanf(" %i", &op);
    return op;
}

//--- Receber o codigo do produto ----------------------------------------
int receberCodigo() {
    int codigo;
    printf("Digite o codigo do produto...: ");
    scanf("%d", &codigo);
    return codigo;
}

//--- Receber os demais dados do produto ---------------------------------
void receberDados(struct tProduto *prod) {
    printf("Digite a descricao do produto: ");
    fflush(stdin);
    scanf("%s", (*prod).descricao);
    printf("Digite o valor do produto....: ");
    scanf("%f", &((*prod).valor));
}

//--- Mostrar dos dados (exceto codigo) do produto -----------------------
void mostrarProduto(struct tProduto prod) {
    printf("Descricao....................: %s\n", prod.descricao);
    printf("Valor........................: R$ %.2f\n", prod.valor);
}
