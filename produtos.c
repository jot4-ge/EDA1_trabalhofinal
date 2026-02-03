#include "dados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionarProduto(Produto *head, int codigo, char *nome, float preco, int quantidade_estoque){
    Produto * novo = (Produto*) malloc(sizeof(Produto));

    if (novo == NULL){
        printf("Erro fatal: Memoria insuficiente!\n");
        exit(1);
    }

    novo -> codigo = codigo;
    novo -> preco = preco;
    novo -> quantidade_estoque = quantidade_estoque;
    strcpy(novo -> nome, nome);

    novo -> prox = head -> prox;
    head -> prox = novo;

}

void listarProdutos(Produto *head){
    Produto *le = head -> prox;

    if (le == NULL) {
        printf("\n>> A lista esta vazia no momento.\n");
        return;
    }

    printf("\n=== Lista de Produtos ===\n");

    while(le != NULL){
        printf("--------------------------------\n");
        printf("Nome do produto: %s\n", le -> nome);
        printf("Codigo do produto: %d\n", le -> codigo);
        printf("Preco do produto: R$ %.2f\n", le -> preco);
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
        printf("Codigo do produto: %d\n", p -> codigo);
        printf("Preco do produto: R$ %.2f\n", p -> preco);
        printf("Quantidade no estoque do produto: %d\n", p -> quantidade_estoque);
        printf("--------------------------------\n");
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
        printf("[Erro] Produto nao encontrado.\n");
    }

}

void editarProduto(Produto *head, int codigo){
    Produto *objeto = buscarProduto(head, codigo);

    if(objeto == NULL){
        printf("\n[Erro] Produto com codigo %d nao encontrado.\n", codigo);
        return;
    }
    
    int escolha;
    printf("O que deseja editar?\n");
    printf("(1) Nome\n(2) Codigo\n(3) Preço\n(4) Quantidade\n");
    scanf("%d", &escolha);
    limpar_buffer();
    char nome[100]; int novo_codigo,quantidade; float preco;
        switch (escolha){
            case 1:
                printf("Digite o novo nome:\n");
                scanf("%99[^\n]", nome);
                limpar_buffer();
                strcpy(objeto -> nome, nome);
                printf("[Sucesso] Nome Alterado!");
                break;
            
            case 2:
                printf("Digite o novo codigo:\n");
                scanf("%d", &novo_codigo);
                limpar_buffer();
                objeto -> codigo = codigo;
                printf("[Sucesso] Codigo Alterado!\n");
                break;
            case 3:
                printf("Digite o novo preco:\n");
                scanf("%f", &preco);
                limpar_buffer();
                objeto -> preco = preco;
                printf("[Sucesso] Preco Alterado!\n");
                break;
            case 4:
                printf("Digite a nova quantidade:\n");
                scanf("%d", &quantidade);
                limpar_buffer();
                objeto -> quantidade_estoque = quantidade;
                printf("[Sucesso] Quantidade Alterada!\n");
                break;
            default:
                printf("Opção Invalida, nada alterado.\n");
                break;
            }
}