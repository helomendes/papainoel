#ifndef PRESENTES_H
#define PRESENTES_H

struct presente;

struct lista;

struct presente *recebePresente();

void criarLista(struct lista **papainoel);

int inicializarLista(struct lista **papainoel);

void destruirLista(struct lista **papainoel);

#endif
