// main.c
#include "dados.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void liberar_memoria(Cliente *c, Produto *p, ItemCarrinho *k) {
    printf("\n[Sistema] Liberando memória e encerrando...\n");
    // TODO: Implementar free() recursivo ou iterativo aqui

}

int main() {

    setlocale(LC_ALL, "Portuguese");

    // INICIALIZAÇÃO DE PONTEIROS
    Cliente *lista_clientes = NULL;
    Produto *lista_produtos = NULL;
    ItemCarrinho *carrinho = NULL;

    int opcao = 0;

    do {
        opcao = menu_principal();

        switch (opcao) {
            case 1:
                // Chamar função de gestão de clientes
                break;
            case 2:
                // Chamar função de gestão de produtos
                break;
            case 3:
                // Chamar função do modo compra
                break;
            case 0:
                liberar_memoria(lista_clientes, lista_produtos, carrinho);
                printf("Encerrando o programa. Até logo!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
