#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>

struct no {
    struct no *esq;
    struct no *dir;
    char dado;
};
typedef struct no* Arvore;

void preOrder(Arvore t);
void inOrder(Arvore t);
void posOrder(Arvore t);

void insertNode(Arvore *t, char d);
struct no* Pesquisa(Arvore t, char d);

int Contar_nos(Arvore t);
int Contar_folhas(Arvore t);
int Contar_Filhos_Direita(Arvore t);
void Nos_Duas_Subarvores(Arvore t);
void Nos_Uma_Subarvores(Arvore t);
void Exibir_folhas(Arvore t);

void Exibir_Filhos(char d, Arvore t);
void Exibir_SubEsq(char d, Arvore t);
int Iguais(Arvore A, Arvore B);
char Menor(Arvore t);
struct no* Sucessor(Arvore t, char d);

void Uniao(Arvore *R, Arvore B);
void Intersecao(Arvore *R, Arvore A, Arvore B);
void ValoresEntre(Arvore t, char a, char b);
void Armazenar(Arvore t, char v[], int *i);
char Mediana(Arvore t);
Arvore Remover(Arvore t, char d);
int Altura(Arvore t);
void ImprimirNiveis(Arvore t);

#endif
