#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL, "Portuguese");
    int a, b, c;
    c = 0;
    printf("Digite a base: ");
    scanf("%d", &a);
    printf("Digite o expoente: ");
    scanf("%d", &b);
    if(b == 0){
    	c = 1;
	}else{
		if(b == 1){
			c = a;
		}else{
			a = b*b;
			c = a*a;
		}		
	}
	printf("Potência: %d", c);
	Sleep(6000);
}
