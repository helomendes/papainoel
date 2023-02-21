#include <stdio.h>
#include <stdlib.h>
#include "presentes.h"

saco_t *melhor_saco(int pmax, int n, int i, saco_t *atual, saco_t *melhor, presente_t v[]){
    /* Caso base. */
    if (atual->peso + v[i].peso > pmax)
        return atual;
    adicionar_presente(atual, v[i]);
    if (melhor->valor < (atual)->valor)
        passar_saco(atual, melhor, n);
    i++;
    /* Loop para testar diferentes combinacoes. */
    for (i=i; i<n; i++)
        /* Chamada recursiva. */
        melhor_saco(pmax, n, i, atual, melhor, v);
    remover_presente(atual);
    return melhor;
}

int main(){
    int n, pmax;
    scanf("%d %d", &n, &pmax);
    saco_t *atual = cria_saco(n);
    saco_t *melhor = cria_saco(n);
    presente_t v_presentes[n];
    le_presentes(n, v_presentes);
    int i = 0;
    /* Loop para mudar o primeiro presente do saco. */
    for (i=i; i<n; i++)
        melhor_saco(pmax, n, i, atual, melhor, v_presentes);
    imprime_saco(melhor);
    atual = destroi_saco(atual);
    melhor = destroi_saco(melhor);
    return 0;
}