// main.c

#include "dados.h"

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


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

    int opcao;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Gestão de Clientes\n");
        printf("2. Gestão de Produtos\n");
        printf("3. Modo Venda (Carrinho)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limpar_buffer();

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
