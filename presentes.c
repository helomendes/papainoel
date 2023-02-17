#include <stdio.h>
#include <stdlib.h>
#include "presentes.h"


//le os dados de uma linha
void lePresentes(int n, presente_t v[]){
	int i, valor, peso;
	for (i = 0; i < n; i++){
		scanf("%d %d", &valor, &peso);
		v[i].valor = valor;
		v[i].peso = peso;
		v[i].id = i;
	}
}

saco_t *criaSaco(){
	
}




