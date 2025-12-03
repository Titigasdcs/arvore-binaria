#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main()
{
    Arvore A = NULL;

    // Inserindo as letras de "EUCALIPTOS"
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

    printf("Pré-Ordem:\n");
    preOrder(A);

    printf("\nIn-Ordem:\n");
    inOrder(A);

    printf("\nPós-Ordem:\n");
    posOrder(A);

    printf("\n");

    return 0;
}
