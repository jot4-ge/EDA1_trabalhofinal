#include "dados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionar_ao_carrinho(ItemCarrinho  **carrinho, Produto *head_produtos, int codigo, int qtd) {

    Produto *prod = buscarProduto(head_produtos, codigo);

    if (prod == NULL) {
        printf("\n[Erro] Produto com código %d não encontrado.\n", codigo);
        return;
    }

    if (qtd > prod->quantidade_estoque) {
        printf("\n[Erro] Estoque insuficiente! Disponivel %d\n ", prod->quantidade_estoque);
        return;
    }
    ItemCarrinho *aux = *carrinho;
    while (aux != NULL) {
        if (aux->codigo_produto == codigo) {

            if (aux->quantidade_compra + qtd > prod->quantidade_estoque) {
                printf("\n[Erro] LImite de estoque excedido (Voce ja tem %d no carrinho).\n", aux->quantidade_compra);
                return;
            }
            aux->quantidade_compra += qtd;
            printf("\n>>> +%d unidades adicionadas ao item existente <<<\n", qtd);
            return;
        }
        aux = aux->prox;
    }

    ItemCarrinho *novo = (ItemCarrinho *) malloc(sizeof(ItemCarrinho));
    if (novo == NULL) {
        printf("Erro de Memoria!\n");
        return;
    }

    novo->codigo_produto = codigo;
    strcpy(novo->nome_produto, prod->nome);
    novo->preco_unitario = prod->preco;
    novo->quantidade_compra = qtd;

    // Inserção no inicio( padrão ponteiro duplo)
    novo->prox = *carrinho;
    *carrinho = novo;

    printf("\n>>> %s adicionado ao carrinho! <<<\n", novo->nome_produto);
}

void listar_carrinho(ItemCarrinho *carrinho) {
    if (carrinho == NULL) {
        printf("\n[Seu Carrinho esta vazio]\n");
        return;
    }

    printf("\n=== CARRINHO DE COMPRAS ===\n");
    float total = 0;
    ItemCarrinho *aux = carrinho;

    while (aux != NULL) {
        float sub = aux->quantidade_compra * aux->preco_unitario;
        total += sub;
        printf("%dx %s (R$ %.2f) = R$ %.2f\n", aux->quantidade_compra, aux->nome_produto, aux->preco_unitario, sub);
        aux = aux->prox;
    }
    printf("--------------------------\n");
    printf("TOTAL A PAGAR: R$ %.2f\n", total);
}

void remover_do_carrinho(ItemCarrinho **carrinho, int codigo) {
    if (*carrinho == NULL) {
        printf("\n[Erro] O carrinho ja esta vazio.\n");
        return;
    }

    ItemCarrinho *atual = *carrinho;
    ItemCarrinho *anterior = NULL;

    while (atual != NULL && atual->codigo_produto != codigo) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("\n[Aviso] Item codigo %d nao esta no carrinho.\n", codigo);
        return;
    }

    if (anterior == NULL) {

        *carrinho = atual->prox;
    } else {

        anterior->prox = atual->prox;
    }

    free(atual);
    printf("\n>>> Item removido do carrinho com sucesso! <<<\n");
}

void finalizar_pedido(ItemCarrinho **carrinho, Produto *head_produtos) {
    if (*carrinho == NULL) {
        printf("\nCarrinho vazio. Nada para comprar.\n");
        return;
    }

    printf("\n--- PROCESSANDO PAGAMENTO ---\n");
    
    ItemCarrinho *aux = *carrinho;
    while (aux != NULL) {
        Produto *prod_estoque = buscarProduto(head_produtos, aux->codigo_produto);
        
        if (prod_estoque != NULL) {

            prod_estoque->quantidade_estoque -= aux->quantidade_compra;
            printf("Baixa de estoque: %s (Restam %d)\n", prod_estoque->nome, prod_estoque->quantidade_estoque);
        }

        ItemCarrinho *temp = aux;
        aux = aux->prox;
        free(temp);
    }

    *carrinho = NULL; 
    printf("\n>>> PEDIDO FINALIZADO COM SUCESSO! <<<\n");
}

