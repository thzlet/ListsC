#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} Lista;

// Cria uma lista vazia
Lista* lst_cria() {
    return NULL;
}

// Insere no início da lista
Lista* lst_insere(Lista* l, int valor) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if (!novo) {
        printf("Erro de alocacao.\n");
        exit(1);
    }

    novo->info = valor;
    novo->prox = l;
    return novo;
}

// Imprime a lista
void lst_imprime(Lista* l) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox)
        printf("%d ", p->info);
    printf("\n");
}

// Busca um elemento na lista
Lista* lst_busca(Lista* l, int valor) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info == valor)
            return p;
    }
    return NULL;
}

// Função principal
int main() {
    Lista* l = lst_cria();

    // Inserindo elementos: 15, 12, 9, 6, 3
    l = lst_insere(l, 3);
    l = lst_insere(l, 6);
    l = lst_insere(l, 9);
    l = lst_insere(l, 12);
    l = lst_insere(l, 15);

    printf("Lista atual: ");
    lst_imprime(l);

    // Testando busca de valor existente
    Lista* resultado = lst_busca(l, 9);
    if (resultado != NULL)
        printf("Valor 9 encontrado: %d\n", resultado->info);
    else
        printf("Valor 9 nao encontrado.\n");

    // Testando busca de valor inexistente
    resultado = lst_busca(l, 7);
    if (resultado != NULL)
        printf("Valor 7 encontrado: %d\n", resultado->info);
    else
        printf("Valor 7 nao encontrado.\n");

    return 0;
}
