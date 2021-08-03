#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int func1(int x){ //0
	int ret = 0; //1
	for(int i=0;i<x;i++){ //n+1
		for(int j=0;j<x;j++){ //n+1
			if(j%2==0)  //1
				ret+=j; //n+1
		} //0
	} //0
	return ret;	//1
	//5+4n
}
