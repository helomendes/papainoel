#include <stdio.h>
#include <stdlib.h>
#include "presentes.h"

struct saco *criarSaco(int pmax, int n, int i, struct saco **atual, struct saco **melhor, struct presente v[]){

	if((*atual)->peso + v[i].peso > pmax)
		return (*atual);
	adicionarPresente(&*atual, v[i]);
	if((*melhor)->valor < (*atual)->valor)
		(*melhor) = (*atual);
	i++;
	while(i<=n){
		criarSaco(pmax, n, i, &*atual, &*melhor, v);
		i++;
	}
	removerPresente(&*atual);
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

//	for(int i = 0; i<n; i++)
//		printf("v_%d: %d\tp_%d: %d\n", i, v_presentes[i].valor, i, v_presentes[i].peso);

	atual->cabeca = NULL;
	atual->peso = 0;
	atual->valor = 0;

	melhor = criarSaco(pmax, n, 0, &atual, &melhor, v_presentes);
	
	struct presente *aux = melhor->cabeca;
	while(aux->prox){
		printf("p: %d\tv: %d\n", aux->valor, aux->peso);
		aux = aux->prox;
	}

	return 0;
}
