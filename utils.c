//utils.c

#include "dados.h"

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Produto *criaLeCabecaProduto(){
    Produto *head;
    head = (Produto*) malloc(sizeof(Produto));
    head -> prox = NULL;

    return head;
}