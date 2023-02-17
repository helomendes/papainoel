#include <stdio.h>
#include <stdlib.h>
#include "presentes.h"



int main(){
	int n;
	int pmax;
	int memoria;

//leitura de n e do peso maximo
	scanf("%d %d", &n, &pmax);

//inicialização da lista de presentes
	struct lista *papainoel;
	memoria = inicializarLista(&papainoel);
	if(!memoria)
		return 0;

//loop pra ler os valores e pesos dos presentes
	for(int i = 0; i<n; i++)
		criarLista(&papainoel);

//loop pra ter certeza que ta lendo os valores certos
	printf("Lista do Papai Noel:\n");
	int i = 1;
	struct presente *aux = papainoel->cabeca;
	while(aux){
		printf("v_%d: %d\t", i, aux->valor);
		printf("p_%d: %d\n", i, aux->peso);
		aux = aux->prox;
		i++;
	}

//free na lista toda
	destruirLista(&papainoel);

	return 0;
}
