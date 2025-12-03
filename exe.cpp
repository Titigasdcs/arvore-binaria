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

    printf("Pre-Ordem:\n");
    preOrder(A);

    printf("\nIn-Ordem:\n");
    inOrder(A);

    printf("\nPos-Ordem:\n");
    posOrder(A);

    printf("\nTotal de Nos: %d\n",Contar_nos(A));
    printf("\nTotal de folhas: %d\n",Contar_folhas(A));
    printf("\nTotal de filhos a direita: %d\n",Contar_Filhos_Direita(A));

    printf("\nNos com duas subarvores: \n");
    Nos_Duas_Subarvores(A);

    printf("\nNos com uma subarvore: \n");
    Nos_Uma_Subarvores(A);

    printf("\nNos de uma arvore:\n");
    Exibir_folhas(A);

    printf("\n");

    return 0;
}