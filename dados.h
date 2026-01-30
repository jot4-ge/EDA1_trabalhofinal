/* dados.h */
#ifndef DADOS_H
#define DADOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura para Data
typedef struct {
    int dia, mes, ano;
} Data;

// LISTA DE CLIENTES
typedef struct Cliente {
    char cpf[15]; 
    char nome[100];
    char email[80];
    char telefone[20];
    Data nascimento;
    struct Cliente *prox; 
} Cliente;

// LISTA DE PRODUTOS
typedef struct Produto {
    int codigo;
    char nome[100]; 
    float preco; 
    int quantidade_estoque;
    struct Produto *prox; 
} Produto;

// LISTA DO CARRINHO (Modo Compra)
typedef struct ItemCarrinho {
    int codigo_produto;
    char nome_produto[100]; 
    float preco_unitario; 
    int quantidade_compra;
    struct ItemCarrinho *prox; 
} ItemCarrinho;


// Utils (implementado em utils.c)
void limpar_buffer();

// A função deve pedir os dados internamente para não poluir a main.
void adicionarCliente(Cliente **lista); 
void removerCliente(Cliente **lista, char *cpf);
void listarClientes(Cliente *lista);
Cliente* buscarCliente(Cliente *lista, char *cpf);

Produto *adicionarProduto(Produto *lista, int codigo, char *nome, float preco, int quantidade_estoque);
void removerProduto(Produto *lista, int codigo);
void listarProdutos(Produto *lista);
Produto* buscarProduto(Produto *lista, int codigo);

// Carrinho
void adicionar_ao_carrinho(ItemCarrinho **carrinho, Produto *produto, int qtd);
void remover_do_carrinho(ItemCarrinho **carrinho, int codigo_produto);
void finalizar_pedido(ItemCarrinho **carrinho, Produto *lista_produtos); 
float calcular_total(ItemCarrinho *carrinho);

// Menu
int menu_principal();

#endif // DADOS_H