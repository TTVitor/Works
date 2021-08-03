#include <stdio.h>
#include <stdlib.h>
#define QTD_MOEDAS 8


int main () {


    int qtd = 0;

    int n = 10*100;


    int moedas[QTD_MOEDAS] = {1,2,5,10,25,50,100,200};


    for(int i = QTD_MOEDAS-1; i != 0; i++){

        if(n%moedas[i] == 0){

            qtd++;

            n = n/moedas[i];


        }

    }


    printf(" Quatidade de moedas: %d ", qtd);


    return 0;

}
