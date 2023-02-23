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

    // Pergunta para o usuário a quantidade de números (incluindo os zeros) 
    printf("Informe a quantidade de numeros: \n");

    // Lê e armazena o número informado
    scanf("%d", &totalNumeros);

    // Cria um array para amazenar os números
    int numeros[totalNumeros];

    // Pergunta para o usuário o valor do número, até a quantidade máxima
    for (int i = 0; i < totalNumeros; i++) {
        printf("Informe o proximo numero: \n");
        scanf("%d", &numeros[i]);

        // Se zero, troca o ultimo valor por zero (pra não contabilizar na soma)
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


