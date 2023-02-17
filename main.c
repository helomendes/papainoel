#include <stdio.h>
#include <stdlib.h>
#include "presentes.h"



int main(){
	int n;
	int pmax;
	int memoria;

//leitura de n e do peso maximo
	scanf("%d %d", &n, &pmax);
	saco_t *atual, *melhor;
//inicialização do vetor de presentes
	presente_t v_presentes[n];
	lePresentes(n, v_presentes);
	atual->peso = 0;
	atual->valor = 0;

	



	return 0;
}
