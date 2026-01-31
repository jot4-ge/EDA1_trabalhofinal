#include "dados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Produto *adicionarProduto(Produto *head, int codigo, char *nome, float preco, int quantidade_estoque){
    Produto * novo = (Produto*) malloc(sizeof(Produto));

    if (novo == NULL){
        printf("Erro fatal: Memória insuficiente!\n");
        exit(1);
    }

    novo -> codigo = codigo;
    novo -> preco = preco;
    novo -> quantidade_estoque = quantidade_estoque;
    strcpy(novo -> nome, nome);

    novo -> prox = head -> prox;
    head -> prox = novo;

    return novo;
}

void listarProdutos(Produto *head){
    Produto *le = head -> prox;

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

Produto *buscarProduto(Produto *head, int codigo){
    Produto *p = head -> prox;

    while(p != NULL && p -> codigo != codigo) p = p -> prox;

    return p;
}

void imprimeProduto(Produto *p){
        printf("--------------------------------\n");
        printf("Nome do produto: %s\n", p -> nome);
        printf("Código do produto: %d\n", p -> codigo);
        printf("Preço do produto: R$ %.2f\n", p -> preco);
        printf("Quantidade no estoque do produto: %d\n", p -> quantidade_estoque);
        printf("--------------------------------\n");
        p = p -> prox;
}

void removerProduto(Produto *head, int codigo){
    if (head -> prox == NULL){
        printf("Lista vazia");
        return;
    }

    Produto *p = head;
    Produto *q = head -> prox;
    
    while(q != NULL && q -> codigo != codigo){
        p = q;
        q = q -> prox;
    }

    if (q != NULL){
        p -> prox = q -> prox;
        free(q);
        printf("[Sucesso] Produto Removido!\n");
    }
    else{
        printf("[Erro] Produto não encontrado.\n");
    }

}