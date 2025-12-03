#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>

struct no {
    struct no *esq;
    struct no *dir;
    char dado;
};

typedef struct no *Arvore;

void insertNode(Arvore *t, char d);
void inOrder(Arvore t);
void preOrder(Arvore t);
void posOrder(Arvore t);

int Contar_nos(Arvore t);
int Contar_folhas(Arvore t);

// ---------------------------
// Implementações
// ---------------------------

void insertNode(Arvore *t, char d)
{
    if (*t == NULL)
    {
        *t = (struct no*) malloc(sizeof(struct no));
        if (*t != NULL)
        {
            (*t)->esq = NULL;
            (*t)->dir = NULL;
            (*t)->dado = d;
        }
        else
            printf("Memoria insuficiente");
    }
    else if (d < (*t)->dado)
        insertNode(&(*t)->esq, d);
    else if (d > (*t)->dado)
        insertNode(&(*t)->dir, d);
    else
        printf("Duplicação de no\n");
}

void preOrder(Arvore t)
{
    if (t != NULL)
    {
        printf("%c", t->dado);
        preOrder(t->esq);
        preOrder(t->dir);
    }
}

void inOrder(Arvore t)
{
    if (t != NULL)
    {
        inOrder(t->esq);
        printf("%c", t->dado);
        inOrder(t->dir);
    }
}

void posOrder(Arvore t)
{
    if (t != NULL)
    {
        posOrder(t->esq);
        posOrder(t->dir);
        printf("%c", t->dado);
    }
}

// Função para contar nós
int Contar_nos(Arvore t)
{
    if (t == NULL)
        return 0;

    return 1 + Contar_nos(t->esq) + Contar_nos(t->dir);
}

// Função para contar folhas
int Contar_folhas(Arvore t)
{
    if (t == NULL)
        return 0;

    // Se é folha
    if (t->esq == NULL && t->dir == NULL)
        return 1;

    // Caso contrário soma folhas das subárvores
    return Contar_folhas(t->esq) + Contar_folhas(t->dir);
}


#endif
