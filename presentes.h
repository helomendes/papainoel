typedef struct presente{
	int valor;       /* Valor sentimental do presente. */
	int peso;        /* Peso do presente. */
	int id;          /* Indice do presente no v_presentes. */
} presente_t;        
                     
typedef struct saco{
    int valor;       /* Soma do valor sentimental de todos os presentes no saco. */
    int peso;        /* Soma do peso de todos os presentes no saco. */
    presente_t *v;   /* Vetor de ponteiros para presentes. */
    int it;          /* Inteiro para guardar o indice do ultimo presente no em *v. */
} saco_t;

/* Le o valor e o peso de cada presente,
 * e coloca cada presente em um vetor de presentes. */
void le_presentes(int n, presente_t v[]);

/* Aloca espaco para uma variavel do tipo saco e a inicializa.
 * Retorna essa variavel caso o processo funcione, e NULL caso contrario. */
saco_t *cria_saco(int n);

/* O saco2 recebe todos os dados do saco1. */
void passar_saco(saco_t *saco1, saco_t *saco2, int n);

/* Adiciona o presente no saco, e modifica o peso e o valor do saco
 * de acordo com o presente. */
void adicionar_presente(saco_t *atual, presente_t presente);

/* Remove o ultimo presente do saco, e modifica o peso e o valor do saco
 * de acordo com o presente. */
void remover_presente(saco_t *atual);

/* Imprime o id dos presentes no saco.*/
void imprime_saco(saco_t *saco);

/* Libera a memoria alocada dinamicamente para um saco. */
saco_t *destroi_saco(saco_t *saco);

    