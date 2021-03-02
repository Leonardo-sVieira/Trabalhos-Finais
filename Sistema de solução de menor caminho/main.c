/*
	Nome: Leonardo da Silva Vieira
	Curso: Ciência da Computação
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define PAI(i) ((i - 1) / 2)
#define FILHO_ESQ(i) (2 * i + 1)
#define FILHO_DIR(i) (2 * i + 2)

typedef struct vertice{
	int nomeVertice;
	int tamanhoAresta;
	int limiteSuperior;
	struct vertice *prox;
}Vertice;

typedef Vertice Grafo;

typedef struct elemento{
	int nomeVertice;
	int *pLimiteSuperior;
}Elemento;

typedef Elemento Conjunto;

void *mallocSafe(unsigned nbytes)
{
	void *p;
	p = malloc(nbytes);

	if (p == NULL)
	{
		printf("Deu ruim! malloc devolveu NULL!\n");
		exit(EXIT_FAILURE);
	}

	return p;
}

//-------------------------------------------------------HEAP's

void troca(Elemento *x, Elemento *y)
{
	Elemento aux;
	aux = *x;
	*x = *y;
	*y = aux;
}

void sobeHeap(Conjunto v[], int m)
{
	int f = m;

	while (f > 0 && *v[PAI(f)].pLimiteSuperior > *v[f].pLimiteSuperior)
	{
		troca(&v[f], &v[PAI(f)]);
		f = PAI(f);
	}
}

int insereConjunto(Conjunto v[], int m, Vertice *novo)
{
	Elemento x;
	x.nomeVertice = novo->nomeVertice;
	x.pLimiteSuperior = &novo->limiteSuperior;
	v[m] = x;
	sobeHeap(v, m);
	return m + 1;
}

void desceHeap(Conjunto v[], int m, int k)
{
	int p = k, f;

	while (FILHO_ESQ(p) < m && (*v[FILHO_ESQ(p)].pLimiteSuperior < *v[p].pLimiteSuperior || (FILHO_DIR(p) < m && *v[FILHO_DIR(p)].pLimiteSuperior < *v[p].pLimiteSuperior)))
	{
		f = FILHO_ESQ(p); // Existe?

		if (FILHO_DIR(p) < m && *v[FILHO_DIR(p)].pLimiteSuperior < *v[f].pLimiteSuperior)
			f = FILHO_DIR(p);

		troca(&v[p], &v[f]);

		p = f;
	}
}

int removeConjunto(Conjunto v[], int m)
{
	troca(&v[0], &v[m - 1]);
	desceHeap(v, m, 0);

	return m - 1;
}

//-------------------------------------------------------GRAFO

void insereGrafo(Grafo *G[], int vertice_origem, int nomeVertice, int tamanhoAresta);void insereGrafo(Grafo *G[], int vertice_origem, int nomeVertice, int tamanhoAresta)
{
	Vertice *nova;
	nova = malloc(sizeof(Vertice));
	nova->nomeVertice = nomeVertice;
	nova->tamanhoAresta = tamanhoAresta;
	nova->prox = G[vertice_origem]->prox;
	G[vertice_origem]->prox = nova;
}

void initialize_sigle_source(Grafo *G[], int qtd_V, int vertice_origem)
{
	for(int i = 0; i < qtd_V; i++)
	{
		if(i != vertice_origem)
		{
		    G[i]->nomeVertice = i;
			G[i]->limiteSuperior = INT_MAX;
		}
		else
		{
		    G[vertice_origem]->nomeVertice = vertice_origem;
			G[vertice_origem]->limiteSuperior = 0;
		}
	}
}

void relax(Grafo *G[], Elemento u, Vertice *v, int tamanhoAresta)
{
	if(G[v->nomeVertice]->limiteSuperior > *u.pLimiteSuperior + tamanhoAresta)
		G[v->nomeVertice]->limiteSuperior = *u.pLimiteSuperior + tamanhoAresta;
}

int existe_no_conjunto_Saida(int vIndice, Conjunto S[], int tamS){
    for(int i = 0; i < tamS; i++)
        if(vIndice == S[i].nomeVertice)
            return 1;

    return 0;
}

void algoritmoDijkstra(Grafo *G[], int qtdVertices, int vertice_origem){
	Grafo *aux;
	int tamQ = 0, tamS = 0;

	initialize_sigle_source(G, qtdVertices, vertice_origem);

	Conjunto Q[qtdVertices], S[qtdVertices];

	for(int i = 0; i < qtdVertices; i++)
		tamQ = insereConjunto(Q, tamQ, G[i]);

	while(tamQ > 0)
	{
		Elemento u = Q[0];
		Vertice uAux;

		uAux.nomeVertice = u.nomeVertice;
		uAux.limiteSuperior = *u.pLimiteSuperior;

		tamQ = removeConjunto(Q, tamQ);

		tamS = insereConjunto(S, tamS, &uAux);

		aux = G[u.nomeVertice]->prox;

		while(aux != NULL)
		{
			relax(G, u, aux, aux->tamanhoAresta);
			aux = aux->prox;
		}

		int tamAux = 0;

		for(int i = 0; i < qtdVertices; i++){
            if(!existe_no_conjunto_Saida(i, S, tamS))
                tamAux = insereConjunto(Q, tamAux, G[i]);
        }

		tamQ = tamAux;
	}
}

//-------------------------------------------------------PRINCIPAL

int main(){
	int E, V, A, B, C;
	Grafo **G;

	scanf("%d %d", &V, &E);

	G = mallocSafe(V*sizeof(G));

	for(int i = 0; i < V; i++){
		G[i] = mallocSafe(sizeof(Vertice));
		G[i]->prox = NULL;
	}

	for(int i = 0; i < E; i++){
		scanf("%d %d %d", &A, &B, &C);

		insereGrafo(G, A, B, C);
	}

	algoritmoDijkstra(G, V, 0);

	printf("%d", G[V-1]->limiteSuperior);

	return 0;
}