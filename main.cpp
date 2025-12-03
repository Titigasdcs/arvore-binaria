#include <stdio.h>
#include "arvore.h"

int main()
{
    Arvore A = NULL;

    insertNode(&A, 'A');
    insertNode(&A, 'C');
    insertNode(&A, 'B');
    insertNode(&A, 'D');

    printf("Pré-Ordem\n");
    preOrder(A);

    printf("\nIn-Ordem\n");
    inOrder(A);

    printf("\nPós-Ordem\n");
    posOrder(A);

    printf("\n");
    return 0;
}
