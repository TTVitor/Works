/**
* Zero para Cancelar
*
*/


int ultimoNumValido(int arr[], int pos) {
    if (arr[pos] != 0) return pos;
    else return ultimoNumValido(arr, pos-1);
}

#include <stdio.h>

int main() {

    int totalNumeros;
    int aux = 0, soma;

    // Pergunta para o usu�rio a quantidade de n�meros (incluindo os zeros) 
    printf("Informe a quantidade de numeros: \n");

    // L� e armazena o n�mero informado
    scanf("%d", &totalNumeros);

    // Cria um array para amazenar os n�meros
    int numeros[totalNumeros];

    // Pergunta para o usu�rio o valor do n�mero, at� a quantidade m�xima
    for (int i = 0; i < totalNumeros; i++) {
        printf("Informe o proximo numero: \n");
        scanf("%d", &numeros[i]);

        // Se zero, troca o ultimo valor por zero (pra n�o contabilizar na soma)
        if (numeros[i] == 0) {
            aux = ultimoNumValido(numeros, i);
            numeros[aux] = 0;
        } 
    }

    // Soma todos os valores do array
    for (int i = 0; i < totalNumeros; i++) {
        soma += numeros[i];
        printf("\n%d", numeros[i]);
    }

    // Imprime o resultado
    printf("\n\nResultado = %d", soma);
}


