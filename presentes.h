#ifndef PRESENTES_H
#define PRESENTES_H

typedef struct presente{
	int valor;
	int peso;
	int id;
	struct presente *prox;
} presente_t;

typedef struct saco{
	presente_t *cabeca;
	int peso;
	int valor;
} saco_t;

void lePresentes(int n, presente_t v[]);

saco_t *criaSaco();



#endif
