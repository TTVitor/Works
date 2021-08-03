#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int potencia(int base, int expoente){
    int acumulador = 1; //1
    int p = base; //1
    int i;

    for(i = 0; i < expoente; i++){  //n
        acumulador *= p;			//n
    }

    return acumulador; //1
}

main(){
	setlocale(LC_ALL, "Portuguese");
    int a, b;						
    printf("Digite a base: ");    	//1
    scanf("%d", &a);				//0
    printf("Digite o expoente: ");  //1
    while(getchar() != '\n');       //n
    scanf("%d", &b);				//0
    printf("Potência: %d\n", potencia(a, b)); //1	
    Sleep(6000);
    //3n
}
