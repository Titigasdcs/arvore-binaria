#include "arvore.h"

void insertNode(Arvore *t, char d)
{
    if (*t == NULL)
    {
        *t = (struct no*) malloc(sizeof(struct no));
        (*t)->esq = NULL;
        (*t)->dir = NULL;
        (*t)->dado = d;
        return;
    }

    if (d < (*t)->dado)
        insertNode(&(*t)->esq, d);
    else if (d > (*t)->dado)
        insertNode(&(*t)->dir, d);
    else
        printf("Duplicacao de no\n");
}

void preOrder(Arvore t)
{
    if (t != NULL)
    {
        printf("%c ", t->dado);
        preOrder(t->esq);
        preOrder(t->dir);
    }
}

void inOrder(Arvore t)
{
    if (t != NULL)
    {
        inOrder(t->esq);
        printf("%c ", t->dado);
        inOrder(t->dir);
    }
}

void posOrder(Arvore t)
{
    if (t != NULL)
    {
        posOrder(t->esq);
        posOrder(t->dir);
        printf("%c ", t->dado);
    }
}


// EXERCÍCIO 1

int Contar_nos(Arvore t)
{
    if (t == NULL) return 0;
    return 1 + Contar_nos(t->esq) + Contar_nos(t->dir);
}

int Contar_folhas(Arvore t)
{
    if (t == NULL) return 0;
    if (t->esq == NULL && t->dir == NULL) return 1;

    return Contar_folhas(t->esq) + Contar_folhas(t->dir);
}

int Contar_Filhos_Direita(Arvore t)
{
    if (t == NULL) return 0;

    int soma = (t->dir != NULL ? 1 : 0);

    return soma +
           Contar_Filhos_Direita(t->esq) +
           Contar_Filhos_Direita(t->dir);
}

// EXERCÍCIO 2

void Nos_Duas_Subarvores(Arvore t)
{
    if (t == NULL) return;

    if (t->esq != NULL && t->dir != NULL)
        printf("%c ", t->dado);

    Nos_Duas_Subarvores(t->esq);
    Nos_Duas_Subarvores(t->dir);
}

// EXERCÍCIO 3 

void Nos_Uma_Subarvores(Arvore t)
{
    if (t == NULL) return;

    if ((t->esq != NULL && t->dir == NULL) ||
        (t->esq == NULL && t->dir != NULL))
        printf("%c ", t->dado);

    Nos_Uma_Subarvores(t->esq);
    Nos_Uma_Subarvores(t->dir);
}

// EXERCÍCIO 4 

void Exibir_folhas(Arvore t)
{
    if (t == NULL) return;

    if (t->esq == NULL && t->dir == NULL)
        printf("%c ", t->dado);

    Exibir_folhas(t->esq);
    Exibir_folhas(t->dir);
}

// EXERCÍCIO 5 

struct no* Pesquisa(Arvore t, char d)
{
    if (t == NULL) return NULL;

    if (d == t->dado) return t;

    if (d < t->dado)
        return Pesquisa(t->esq, d);
    else
        return Pesquisa(t->dir, d);
}

// EXERCÍCIO 6

void Exibir_Filhos(char d, Arvore t)
{
    struct no* p = Pesquisa(t, d);

    if (p == NULL)
    {
        printf("Item nao encontrado.\n");
        return;
    }

    printf("Filhos de %c: ", d);

    if (p->esq != NULL) printf("Esq=%c ", p->esq->dado);
    if (p->dir != NULL) printf("Dir=%c ", p->dir->dado);
    if (p->esq == NULL && p->dir == NULL) printf("Nao possui filhos.");

    printf("\n");
}

// EXERCÍCIO 7

void Exibir_SubEsq(char d, Arvore t)
{
    struct no* p = Pesquisa(t, d);

    if (p == NULL)
    {
        printf("Item nao encontrado\n");
        return;
    }

    printf("Subarvore esquerda de %c: ", d);
    preOrder(p->esq);
    printf("\n");
}

// EXERCÍCIO 8

int Iguais(Arvore A, Arvore B)
{
    if (A == NULL && B == NULL) return 1;
    if (A == NULL || B == NULL) return 0;

    return (A->dado == B->dado &&
            Iguais(A->esq, B->esq) &&
            Iguais(A->dir, B->dir));
}

// EXERCÍCIO 9

char Menor(Arvore t)
{
    if (t == NULL) return '#';

    while (t->esq != NULL)
        t = t->esq;

    return t->dado;
}


// EXERCÍCIO 10 

struct no* Sucessor(Arvore t, char d)
{
    struct no* p = Pesquisa(t, d);
    if (p == NULL) return NULL;

    if (p->dir != NULL)
    {
        p = p->dir;
        while (p->esq != NULL)
            p = p->esq;
        return p;
    }

    return NULL;
}


// EXERCÍCIO 17 

int Altura(Arvore t)
{
    if (t == NULL) return -1;

    int h1 = Altura(t->esq);
    int h2 = Altura(t->dir);

    return 1 + (h1 > h2 ? h1 : h2);
}

// EXERCÍCIO 18 

void Uniao(Arvore *R, Arvore B)
{
    if (B == NULL) return;

    insertNode(R, B->dado);
    Uniao(R, B->esq);
    Uniao(R, B->dir);
}

void Intersecao(Arvore *R, Arvore A, Arvore B)
{
    if (A == NULL || B == NULL) return;

    if (Pesquisa(B, A->dado) != NULL)
        insertNode(R, A->dado);

    Intersecao(R, A->esq, B);
    Intersecao(R, A->dir, B);
}


void ValoresEntre(Arvore t, char a, char b)
{
    if (t == NULL) return;

    if (t->dado > a)
        ValoresEntre(t->esq, a, b);

    if (t->dado > a && t->dado < b)
        printf("%c ", t->dado);

    if (t->dado < b)
        ValoresEntre(t->dir, a, b);
}

void Armazenar(Arvore t, char v[], int *i)
{
    if (t == NULL) return;

    Armazenar(t->esq, v, i);
    v[(*i)++] = t->dado;
    Armazenar(t->dir, v, i);
}


char Mediana(Arvore t)
{
    char v[100];
    int i = 0;

    Armazenar(t, v, &i);

    if (i == 0) return '#';

    int pos = (i - 1) / 2;

    return v[pos];
}


// EXERCÍCIO 19 - 21

Arvore Remover(Arvore t, char d)
{
    if (t == NULL) return NULL;

    if (d < t->dado)
        t->esq = Remover(t->esq, d);
    else if (d > t->dado)
        t->dir = Remover(t->dir, d);
    else
    {
        if (t->esq == NULL)
        {
            Arvore aux = t->dir;
            free(t);
            return aux;
        }
        else if (t->dir == NULL)
        {
            Arvore aux = t->esq;
            free(t);
            return aux;
        }
        else
        {
            struct no* suc = t->dir;
            while (suc->esq != NULL)
                suc = suc->esq;

            t->dado = suc->dado;
            t->dir = Remover(t->dir, suc->dado);
        }
    }

    return t;
}

// EXERCÍCIO 22 

void ImprimirNiveis(Arvore t)
{
    if (t == NULL) return;

    Arvore fila[200];
    int ini = 0, fim = 0;

    fila[fim++] = t;

    while (ini < fim)
    {
        Arvore atual = fila[ini++];

        printf("%c ", atual->dado);

        if (atual->esq != NULL)
            fila[fim++] = atual->esq;

        if (atual->dir != NULL)
            fila[fim++] = atual->dir;
    }
}
