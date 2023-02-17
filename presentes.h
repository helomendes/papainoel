#ifndef PRESENTES_H
#define PRESENTES_H

typedef struct presente{
	int valor;
	int peso;
	struct presente *prox;
} presente_t;

typedef struct lista{
	presente_t *cabeca;
	presente_t *cauda;
} lista_t;

presente_t *recebePresente();

void criarLista(lista_t **papainoel);

int inicializarLista(lista_t **papainoel);

void destruirLista(lista_t **papainoel);

#endif
