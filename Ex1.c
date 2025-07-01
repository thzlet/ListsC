#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} Lista;

Lista* lst_cria() {
    return NULL;
}

Lista* lst_insere(Lista* l, int valor) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = l;
    return novo;
}

void lst_imprime(Lista* l) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox)
        printf("%d ", p->info);
    printf("\n");
}

int main() {
    Lista* l = lst_cria();

    l = lst_insere(l, 5);
    l = lst_insere(l, 10);
    l = lst_insere(l, 15);
    l = lst_insere(l, 20);

    lst_imprime(l); // Saída: 20 15 10 5
    return 0;
}
