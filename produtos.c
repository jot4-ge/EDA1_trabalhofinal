#include "dados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Produto *adicionarProduto(Produto *lista, int codigo, char *nome, float preco, int quantidade_estoque){
    Produto * novo = (Produto*) malloc(sizeof(Produto));

    if (novo == NULL){
        printf("Erro fatal: Memória insuficiente!\n");
        exit(1);
    }

    novo -> codigo = codigo;
    novo -> preco = preco;
    novo -> quantidade_estoque = quantidade_estoque;
    strcpy(novo -> nome, nome);

    novo -> prox = lista;

    return novo;
}