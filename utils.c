//utils.c

#include "dados.h"

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

Produto *criaLeCabecaProduto(){
    Produto *le;
    le = malloc(sizeof(Produto));
    le -> prox = NULL;

    return le;
}