#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main()
{
    Arvore A = NULL;

    insertNode(&A, 'E');
    insertNode(&A, 'U');
    insertNode(&A, 'C');
    insertNode(&A, 'A');
    insertNode(&A, 'L');
    insertNode(&A, 'I');
    insertNode(&A, 'P');
    insertNode(&A, 'T');
    insertNode(&A, 'O');
    insertNode(&A, 'S');

    // EXERCÍCIO 1
    printf("Pre-Ordem: ");
    preOrder(A);
    printf("\nIn-Ordem: ");
    inOrder(A);
    printf("\nPos-Ordem: ");
    posOrder(A);

    // EXERCÍCIO 1 (contagens)
    printf("\n\nTotal de Nos: %d", Contar_nos(A));
    printf("\nTotal de folhas: %d", Contar_folhas(A));
    printf("\nTotal de filhos a direita: %d\n", Contar_Filhos_Direita(A));

    // EXERCÍCIO 2 e 3
    printf("\nNos com duas subarvores: ");
    Nos_Duas_Subarvores(A);
    printf("\nNos com uma subarvore: ");
    Nos_Uma_Subarvores(A);
    printf("\nFolhas da arvore: ");
    Exibir_folhas(A);

    // EXERCÍCIO 5
    struct no *p = Pesquisa(A, 'C');
    printf("\n\nEndereco do no 'C': %p\n", p);

    // EXERCÍCIO 6
    printf("\nExibir filhos de 'E':\n");
    Exibir_Filhos('E', A);

    // EXERCÍCIO 7
    printf("\nSubarvore esquerda de 'P': ");
    Exibir_SubEsq('P', A);

    // EXERCÍCIO 8
    Arvore B = NULL;
    insertNode(&B, 'E');
    insertNode(&B, 'U');
    insertNode(&B, 'C');
    insertNode(&B, 'A');
    insertNode(&B, 'L');
    insertNode(&B, 'I');
    insertNode(&B, 'P');
    insertNode(&B, 'T');
    insertNode(&B, 'O');
    insertNode(&B, 'S');
    printf("\nArvores A e B sao iguais? %d\n", Iguais(A, B));

    // EXERCÍCIO 9
    printf("\nMenor elemento: %c\n", Menor(A));

    // EXERCÍCIO 10
    struct no* suc = Sucessor(A, 'E');
    if (suc) printf("Sucessor de E: %c\n", suc->dado);

    // EXERCÍCIO 17
    printf("Altura da arvore: %d\n", Altura(A));

    // EXERCÍCIO 18 (uniao e interseção)
    Arvore C = NULL;
    insertNode(&C, 'F');
    insertNode(&C, 'A');
    insertNode(&C, 'Z');

    Arvore Inter = NULL;
    Intersecao(&Inter, A, C);

    Arvore Uni = NULL;
    Uniao(&Uni, A);
    Uniao(&Uni, C);

    printf("\nInterseccao (A ∩ C): ");
    inOrder(Inter);
    printf("\nUniao (A ∪ C): ");
    inOrder(Uni);

    // EXERCÍCIO 18 (intervalo)
    printf("\nValores entre 'C' e 'T': ");
    ValoresEntre(A, 'C', 'T');

    // EXERCÍCIO 18 (mediana)
    printf("\nMediana da arvore: %c\n", Mediana(A));

    // EXERCÍCIO 19 - 21
    printf("\nRemovendo 'E'...\n");
    A = Remover(A, 'E');
    printf("Arvore apos remocao: ");
    inOrder(A);

    // EXERCÍCIO 22
    printf("\n\nArvore por niveis:\n");
    ImprimirNiveis(A);

    printf("\n");
    return 0;
}
