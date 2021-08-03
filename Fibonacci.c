#include <stdio.h>
#include <stdlib.h>

main(){
	int f1, f2, result, i;
	f1 = 1; //1
	f2 = 0; //1
	result = 0;
	printf("%d,", f2); //1
	printf("%d,", f1); //1
	for(i=0; i<18; i++){ //n+1
		result = f1+f2; //n+1
		f2 = f1; //n+1
		f1 = result; //n+1
		printf("%d,", result); //1
	}
	Sleep(6000);
	//5+4n+4
}
