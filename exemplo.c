#include <stdio.h>
#include <stdlib.h>

//Estrutura do nó
struct lista {
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

//Inicializa lista vazia (pedido no exercício)
Lista* inicializa(void) {
    return NULL;
}

//Inserção no final da lista circular
Lista* inserirFinal(Lista* l, int valor) {

    Lista* novo = (Lista*) malloc(sizeof(Lista));

    novo->info = valor;

    // Caso lista vazia 
    if (l == NULL) {
        novo->prox = novo; // aponta para si mesmo
        return novo;
    }

    // Procurar último nó
    Lista* p = l;

    while (p->prox != l) {
        p = p->prox;
    }

    // Inserção 
    p->prox = novo;
    novo->prox = l;

    return l;
}

// Impressão da lista circular
void imprimir(Lista* l) {

    if (l == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Lista* p = l;

    // Percorre a lista 
    do {

        printf("%d -> ", p->info);

        p = p->prox;

    } while (p != l);

    printf("(inicio)\n");
}

int main(void) {

    Lista* l;

    // Inicializa lista
    l = inicializa();

    // Inserções 
    l = inserirFinal(l, 10);
    l = inserirFinal(l, 20);
    l = inserirFinal(l, 30);
    l = inserirFinal(l, 40);

    // Impressão 
    imprimir(l);

    return 0;
}
