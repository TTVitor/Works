#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL, "Portuguese");
	int i, j, matriz[2][2], aux;
	printf("\nDigite valor para os elementos da matriz: \n\n"); //1
 	for ( i=0; i<2; i++ ){ //n
    	for ( j=0; j<2; j++ ){ //n
      		printf ("Elemento[%d][%d] = ", i, j); //1
      		scanf ("%d", &matriz[i][j]); //0
		}
	}
	
	for ( i=0; i<2; i++ ){ //n
    	for ( j=0; j<2; j++ ){ //n
			if(matriz[i][j]>aux){ //1
				aux = matriz[i][j]; //1
			}
		}
	}
	printf("\nMaior valor da matriz [%d][%d] é o valor = %d", i, j, aux); //1
	Sleep(6000);
	//5+4n
}
