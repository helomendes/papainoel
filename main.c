#include <stdio.h>
#include <stdlib.h>
#include "presentes.h"

struct saco *criarSaco(int pmax, struct saco **atual, struct saco **melhor, struct presente v[]){
	if((*atual)->peso + v[0].peso <= pmax)
		adicionarPresente(&*atual, v[0]);
	(*melhor) = (*atual);
	return (*melhor);
}

int main(){
	int n;
	int pmax;

//leitura de n e do peso maximo
	scanf("%d %d", &n, &pmax);
	saco_t *atual = malloc(sizeof(struct saco));
	saco_t *melhor = malloc(sizeof(struct saco));


//inicialização do vetor de presentes
	presente_t v_presentes[n];
	lePresentes(n, v_presentes);

	for(int i = 0; i<n; i++)
		printf("v_%d: %d\tp_%d: %d\n", i, v_presentes[i].valor, i, v_presentes[i].peso);

	atual->cabeca = NULL;
	atual->peso = 0;
	atual->valor = 0;

	atual->cabeca = &v_presentes[0];
	melhor = criarSaco(pmax, &atual, &melhor, v_presentes);

	printf("melhor: %d\n", melhor->peso);

	return 0;
}
