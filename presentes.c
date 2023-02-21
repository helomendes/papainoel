#include <stdio.h>
#include <stdlib.h>
#include "presentes.h"

void le_presentes(int n, presente_t v[]){
	int i, valor, peso;
	for (i = 0; i < n; i++){
		scanf("%d %d", &valor, &peso);
		v[i].valor = valor;
		v[i].peso = peso;
		v[i].id = i;
	}
}

presente_t presente_nulo(){
    presente_t presente;
    presente.id = -1;
    presente.peso = -1;
    presente.valor = -1;
    return presente;
}

void inicializa_saco(saco_t *atual, int n){
    int i;
    presente_t presente = presente_nulo();
    for (i = 0; i < n; i++){
        atual->v[i] = presente;
    }
}

saco_t *cria_saco(int n){
    saco_t *atual = malloc(sizeof(saco_t));
    if (!atual)
        return NULL;
    atual->v = malloc(sizeof(presente_t)*n);
    if (!atual->v)
        return NULL;
    inicializa_saco(atual, n);
    atual->peso = 0;
    atual->valor = 0;
    atual->it = 0;
    return atual;
}

void passar_saco(saco_t *atual, saco_t *melhor, int n){
    int i = 0;
    inicializa_saco(melhor, n);
    while (atual->v[i].id != -1){
        melhor->v[i] = atual->v[i];
        i++;
    }
    melhor->peso = atual->peso;
    melhor->valor = atual->valor;
}

void adicionar_presente(saco_t *atual, presente_t presente){
    int i = atual->it;
    atual->v[i] = presente;
    atual->it++;
    atual->peso = atual->peso + presente.peso;
    atual->valor = atual->valor + presente.valor;
}

void remover_presente(saco_t *atual){
    int i = atual->it - 1;
    presente_t presente = atual->v[i]; 
    atual->v[i] = presente_nulo();
    atual->it--;
    atual->peso = atual->peso - presente.peso;
    atual->valor = atual->valor - presente.valor;
}

