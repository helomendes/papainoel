#include <stdio.h>
#include <stdlib.h>
#include "presentes.h"

saco_t *melhor_saco(int pmax, int n, int i, saco_t *atual, saco_t *melhor, presente_t v[]){
    if (atual->peso + v[i].peso > pmax)
        return atual;
    adicionar_presente(atual, v[i]);
    if (melhor->valor < (atual)->valor)
        passar_saco(atual, melhor, n);
    i++;
    for (i=i; i<=n; i++)
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
    melhor_saco(pmax, n, 0, atual, melhor, v_presentes);
    printf("Total: %d\n", melhor->valor);
    return 0;
}