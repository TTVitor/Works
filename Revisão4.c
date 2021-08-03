#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

struct tNo {
	struct tNo *esq;
	struct tNo *dir;
	int dado;
};

void inicializar(struct tNo **raiz) {
	(*raiz) = NULL;
}

int menu() {
	int op;
	
	printf("***  Menu  ***\n");
	printf("1 - Inclusão\n");
	printf("2 - Lista Pos Order\n");
	printf("3 - Representação\n");
	printf("4 - Maior Valor da Árvore\n");
	printf("0 - Sair\n\n");
	printf("Digite uma opção: ");
	scanf("%d",&op);
	
	return op;
}


void incluir(struct tNo **raiz, struct tNo *p) 
{
	if((*raiz) == NULL) { //sem nós na arvore
		(*raiz) = p;
		p->esq = p->dir = NULL;
	} else {
		if(p->dado < (*raiz)->dado) 
		{
			incluir(&((*raiz)->esq), p);
		} else
			incluir(&((*raiz)->dir), p);
	}
}

void posordem(struct tNo *raiz) 
{
	if(raiz == NULL)
		return;
	posordem(raiz->esq);
	posordem(raiz->dir);
	printf("->%i\n", raiz->dado);
}



void representa(struct tNo *raiz) 
{
	if(raiz == NULL)
		return;
		
	printf("( %i", raiz->dado);
	representa(raiz->esq);
	representa(raiz->dir);
	printf(")");
}


void maiorValorAB(struct tNo *raiz) 
{	
	int recebe;
	if(raiz==NULL)
		return;
	if(raiz->dir==NULL){
		recebe = raiz->dado;
		printf("Maior: %i\n", recebe);
	}
	maiorValorAB(raiz->dir);
}


int main(void) {
	int opcao, pesqCod;
	int maior;
	struct tNo *arvore, *no, *p, *q;
	
	setlocale(LC_ALL,"Portuguese");

	inicializar(&arvore);

	do {
		
		opcao = menu();

		switch(opcao) {
			case 1:
				no = malloc(sizeof(struct tNo));
				printf("***  Inclusão  ***\n\n");
				printf("Digite o código do produto: ");
				scanf("%i", &(no->dado));
				incluir(&arvore, no);
				break;
			case 2:
				printf("***  Lista Pos Order  ***\n\n");
				posordem(arvore);
				getch();
				break;
			case 3:
				representa(arvore);
				getch();
				break;
			case 4:
				maiorValorAB(arvore);
				getch();
				break;		
		}
	} while(opcao!=0);

	return 0;
}
