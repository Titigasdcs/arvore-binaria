struct no
{
struct no *esq;
struct no *dir;
char dado;
};
typedef struct no *Arvore;
void insertNode(Arvore *t, char d);
void inOrder(Arvore t);
void preOrder(Arvore t);
void posOrder(Arvore t);

void insertNode(Arvore *t, char d)
{
if (*t == NULL)
{
*t = (struct no*) malloc(sizeof(struct no));
if ( *t != NULL )
{
(*t)->esq = NULL;
(*t)->dir = NULL;
(*t)->dado = d;
}
else
printf("Memoria insuficiente");
}
else
if (d < (*t)->dado)
insertNode(&(*t)->esq, d);
else
if (d > (*t)->dado)
insertNode(&(*t)->dir, d);
else
printf("Duplicação de no");

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

