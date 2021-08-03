#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
 
struct tAluno {
int codigo;
char nome[30];
float notas[3];
};


// Variáveis Globais
struct tAluno alunos[10];
FILE *arqDados, *arqQtdeAlunos;
int qtdeAlunos;

int recuperaDadosArquivo() {
int contador, tamanho;

// Erro
if ((arqDados = fopen("alunos.txt", "rb")) == NULL) {
return 0;
exit(1);
}

// Sucesso
else {

if ((arqQtdeAlunos = fopen("qtdeAlunos.txt", "rb")) == NULL) {
return 0;
exit(1);
}

else {
fread(&qtdeAlunos, sizeof(int), 1, arqQtdeAlunos);

for (contador = 0; contador < qtdeAlunos; contador++) {
tamanho = fread(&alunos[contador], sizeof(struct tAluno), 1, arqDados);
if (tamanho < 0) return 0;
}
}
}

fclose(arqQtdeAlunos);
fclose(arqDados);
return 1;
}

int gravaDadosnoArquivo(int qtdeAlunos) {
int contador, tamanho;

// Erro
if ((arqDados = fopen("alunos.txt", "wb")) == NULL) {
return 0;
exit(1);
}

// Sucesso
else {
  for (contador = 0; contador < qtdeAlunos; contador++) {
tamanho = fwrite(&alunos[contador], sizeof(struct tAluno), 1, arqDados);
if (tamanho < 0) return 0;
}

if ((arqQtdeAlunos = fopen("qtdeAlunos.txt", "wb")) != NULL) {
tamanho = fwrite(&qtdeAlunos, sizeof(int), 1, arqQtdeAlunos);
if (tamanho < 0) return 0;
}

}

fclose(arqQtdeAlunos);
fclose(arqDados);
return 1;
}
 
int main () {

int contador;

    printf("Informe a quantidade de alunos: ");
    scanf("%i", &qtdeAlunos);
   
    for (contador = 0; contador < qtdeAlunos; contador++) {
printf("\nInforme o código do %dº aluno:\n", contador + 1);
scanf("%d", &alunos[contador].codigo);

printf("\nInforme o nome do %dº aluno:\n", contador + 1);
fflush(stdin);
gets(alunos[contador].nome);

printf("\nInforme a nota 1 do %dº aluno:\n", contador + 1);
scanf("%f", &alunos[contador].notas[0]);

printf("\nInforme a nota 2 do %dº aluno:\n", contador + 1);
scanf("%f", &alunos[contador].notas[1]);

printf("\nInforme a nota 3 do %dº aluno:\n", contador + 1);
scanf("%f", &alunos[contador].notas[2]);
  }
   
    for (contador = 0; contador < qtdeAlunos; contador++) {
    printf("Aluno nº %d\n", contador);
printf("Codigo = %d\n", alunos[contador].codigo);
printf("Nome = %s\n", alunos[contador].nome);
printf("Nota 1 = %.2f\n", alunos[contador].notas[0]);
printf("Nota 2 = %.2f\n", alunos[contador].notas[1]);
printf("Nota 3 = %.2f\n\n", alunos[contador].notas[2]);
}
   
if (gravaDadosnoArquivo(qtdeAlunos)) printf("Dados gravados no arquivo com sucesso!\n");
else printf("Erro ao tentar abrir arquivo!\n");


if (recuperaDadosArquivo()) printf("Dados recuperados do arquivo com sucesso!\n");
else printf("Erro ao tentar abrir e recuperar dados do arquivo!\n");

    for (contador = 0; contador < qtdeAlunos; contador++) {
    printf("Aluno nº %d\n", contador);
printf("Codigo = %d\n", alunos[contador].codigo);
printf("Nome = %s\n", alunos[contador].nome);
printf("Nota 1 = %.2f\n", alunos[contador].notas[0]);
printf("Nota 2 = %.2f\n", alunos[contador].notas[1]);
printf("Nota 3 = %.2f\n\n", alunos[contador].notas[2]);
}

getch();
return 0;
}
