int Pendrive(int tam, int numArq, int capPD){
	int i;
	i = 1;
	while(i<=numArq && tam<=capPD){
		capPD = capPD-tam;
		i = i+1;
	}
	return Pendrive(1; i-1);
}
