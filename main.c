// main.c
#include "dados.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int menu_principal() {
    int opcao;
    printf("\n--- Menu Principal ---\n");
    printf("1. Gestão de Clientes\n");
    printf("2. Gestão de Produtos\n");
    printf("3. Modo Compra\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");

    scanf("%d", &opcao);
    limpar_buffer(); // Limpa o enter após o número

    return opcao;
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

    int opcao = 0;

    do {
        opcao = menu_principal();

        switch (opcao) {
            case 1:
                printf("\n Menu Clientes ---\n");
                printf("1. Adicionar Novo \n");
                printf("2. Listar Todos \n");
                printf("3. Remover Cliente \n");
                printf("4. Buscar Cliente \n");
                printf("Escolha uma opção: ");

                int sub_op;
                scanf("%d", &sub_op);
                limpar_buffer();

                if (sub_op == 1) {
                    adicionarCliente(&lista_clientes);
                } else if (sub_op == 2) {
                    listarClientes(lista_clientes);
                } else if (sub_op == 3) {
                    char cpf_remover[15];
                    printf("Digite o CPF para remover: ");
                    fgets(cpf_remover, 15, stdin);
                    
                    // Pequeno truque para remover o \n que o fgets pega
                    size_t len = strlen(cpf_remover);
                    if (len > 0 && cpf_remover[len-1] == '\n') cpf_remover[len-1] = '\0';

                    removerCliente(&lista_clientes, cpf_remover);
                } else if (sub_op == 4) {
                    char cpf_buscar[15];
                    printf("Digite o CPF para buscar: ");
                    fgets(cpf_buscar, 15, stdin);

                    size_t len = strlen(cpf_buscar);
                    if (len > 0 && cpf_buscar[len-1] == '\n') cpf_buscar[len-1] = '\0';

                    Cliente *resultado = buscarCliente(lista_clientes, cpf_buscar);

                    if (resultado != NULL) {
                        printf("\n--- Cliente Encontrado ---\n");
                        printf("Nome: %s\n", resultado->nome);
                        printf("Email: %s\n", resultado->email);
                        printf("Telefone: %s\n", resultado->telefone);
                    } else {
                        printf("\n[Aviso] Cliente nao encontrado.\n");
                    }
                } else {
                    printf("Opcao invalida.\n");
                }
                break;
            case 2:
                // Chamar função de gestão de produtos
                printf("\n Menu Produtos ---\n");
                printf("1. Cadastrar Produto\n");
                printf("2. Listar todos os produtos\n");
                printf("3. Buscar produto pelo código\n");
                printf("4. Editar dados de um produto\n");
                printf("5. Remover um produto\n");
                
                int opcao;
                scanf("%d", &opcao);
                limpar_buffer();

                switch(opcao){
                    case 1:
                        int codigo_temp, quantidade_estoque_temp;
                        float preco_temp;
                        char nome_temp[100];

                        printf("Digite o nome do Produto:\n");
                        scanf("%99[^\n]", nome_temp);
                        limpar_buffer();

                        printf("Digite o código do Produto:\n");
                        scanf("%d", &codigo_temp);
                        limpar_buffer();

                        printf("Digite o preço do Produto:\n");
                        scanf("%f", &preco_temp);

                        printf("Digite a quantidade do produto:\n");
                        scanf("%d", &quantidade_estoque_temp);

                        lista_produtos = adicionarProduto(lista_produtos, codigo_temp, nome_temp, preco_temp, quantidade_estoque_temp);
                        
                        printf("Produto Adicionado com Sucesso!\n");
                        break;
                    case 2:
                        
                        listarProdutos(lista_produtos);
                        break;
                    case 3:

                        printf("Digite o código do produto que deseja buscar:\n");
                        scanf("%d", &codigo_temp);

                        Produto *resultado = buscarProduto(lista_produtos, codigo_temp);

                        if (resultado){
                            printf("[Sucesso] Produto encontrado!\n");
                            imprimeProduto(resultado);
                        }
                        else printf("[Aviso] Produto não encontrado com o codigo %d\n", codigo_temp);
                        break;
                    case 4:
                        // Editar Produto
                        break;
                    case 5:
                        // Remover Produto
                        break;
                    default:
                        printf("Opção inválida! Tente novamente.\n");
                }

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
