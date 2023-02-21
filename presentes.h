typedef struct presente{
	int valor;
	int peso;
	int id;
} presente_t;

typedef struct saco{
    int valor;
    int peso;
    presente_t *v;
    int it;
} saco_t;

void le_presentes(int n, presente_t v[]);

saco_t *cria_saco(int n);

void passar_saco(saco_t *atual, saco_t *melhor, int n);

void adicionar_presente(saco_t *atual, presente_t presente);

void remover_presente(saco_t *atual);


    