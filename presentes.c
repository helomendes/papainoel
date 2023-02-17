#include <stdio.h>
#include <stdlib.h>
#include "presentes.h"


//le os dados de uma linha
presente_t *recebePresente(){
		presente_t *novo;
		novo = malloc(sizeof(presente_t));
		scanf("%d %d", &novo->valor, &novo->peso);
		novo->prox = NULL;
		return novo;
}

//adiciona os dados recebidos à lista
void criarLista(lista_t **papainoel){
	presente_t *novo;
	novo = recebePresente();

	if(!(*papainoel)->cabeca){
		(*papainoel)->cabeca = novo;
	}
	else{
		presente_t *aux;
		aux = (*papainoel)->cabeca;
		while(aux->prox)
			aux = aux->prox;
		novo->prox = aux->prox;
		aux->prox = novo;
	}
}

int inicializarLista(lista_t **papainoel){
	(*papainoel) = malloc(sizeof(lista_t));
	(*papainoel)->cabeca = NULL;
	if(!(*papainoel)){
		printf("Alocação de memória falhou.\n");
		return 0;
	}
	return 1;
}

void destruirLista(lista_t **papainoel){
	presente_t *aux;
	while((*papainoel)->cabeca){
		aux = (*papainoel)->cabeca->prox;
		free((*papainoel)->cabeca);
		(*papainoel)->cabeca = aux;

	}
}
