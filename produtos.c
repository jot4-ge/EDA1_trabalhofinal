#include "dados.h"
#include "utils.c"
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

void listarProdutos(Produto *lista){
    Produto *le = lista;

    if (le == NULL) {
        printf("\n>> A lista está vazia no momento.\n");
        return;
    }

    printf("\n=== Lista de Produtos ===\n");

    while(le != NULL){
        printf("--------------------------------\n");
        printf("Nome do produto: %s\n", le -> nome);
        printf("Código do produto: %d\n", le -> codigo);
        printf("Preço do produto: R$ %.2f\n", le -> preco);
        printf("Quantidade no estoque do produto: %d\n", le -> quantidade_estoque);

        le = le -> prox;
    }
    printf("--------------------------------\n");
}

Produto *buscarProduto(Produto *lista, int codigo){
    Produto *p = lista;

    while(p != NULL && p -> codigo != codigo) p = p -> prox;

    return p;
}