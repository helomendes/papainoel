#include <stdio.h>
#include <stdlib.h>
#include "presentes.h"

struct presente{
	int valor;
	int peso;
	struct presente *prox;
};

struct lista{
	struct presente *cabeca;
};

//le os dados de uma linha
struct presente *recebePresente(){
		struct presente *novo;
		novo = malloc(sizeof(struct presente));
		scanf("%d %d", &novo->valor, &novo->peso);
		novo->prox = NULL;
		return novo;
}

//adiciona os dados recebidos à lista
void criarLista(struct lista **papainoel){
	struct presente *novo;
	novo = recebePresente();

	if(!(*papainoel)->cabeca){
		(*papainoel)->cabeca = novo;
	}
	else{
		struct presente *aux;
		aux = (*papainoel)->cabeca;
		while(aux->prox)
			aux = aux->prox;
		novo->prox = aux->prox;
		aux->prox = novo;
	}
}

int inicializarLista(struct lista **papainoel){
	(*papainoel) = malloc(sizeof(struct lista));
	(*papainoel)->cabeca = NULL;
	if(!(*papainoel)){
		printf("Alocação de memória falhou.\n");
		return 0;
	}
	return 1;
}

void destruirLista(struct lista **papainoel){
	struct presente *aux;
	while((*papainoel)->cabeca){
		aux = (*papainoel)->cabeca->prox;
		free((*papainoel)->cabeca);
		(*papainoel)->cabeca = aux;

	}
}
