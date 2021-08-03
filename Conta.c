par** func4(int x){ //0
	par **m; //1
	m = (par**)malloc(sizeof(par*)*x); //1
	for(int i=0;i<x;i++){ //n+1
		m[i] = (par*)malloc(sizeof(par)*x); //1
		for(int j=0;j<x;j++){ //n+1
			m[i][j].i=i; //2n+1
			m[i][j].j=j; //2n+1
		} //0
	} //0
	return m; //1
} //0

typedef struct{ 
	int i, j;
}par;

int conta(int x){ //0
	par **m = func4(x); //1
	int conta = 0; //1
	for(int i=0;i<x;i++){ //n+1
		for(int j=0;j<x;j++){ //n+1
			if(m[i][j].i>m[i][j]) //2n
				conta++; //n
		}
	}
	return conta; //1
} //0
//13+11n
