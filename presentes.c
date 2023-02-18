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

void adicionarPresente(struct saco **atual, struct presente presente){
	if((*atual)->cabeca != NULL){
		(*atual)->cabeca = &presente;
		(*atual)->peso = (*atual)->peso + presente.peso;
		}
	else{
		presente_t *aux = (*atual)->cabeca;
		while(aux->prox)
			aux = aux->prox;
		aux->prox = &presente;
		(*atual)->peso = (*atual)->peso + presente.peso;
	}
}
