// dados.h //
#ifndef DADOS_H
#define DADOS_H

// Estrutura para Data
typedef strutct {
    int dia, mes, ano;
} Data;

// LISTA DE CLIENTES
typedef struct Cliente {
    char cpf[15]
    char nome[100];
    char email[80];
    char telefone[20];
    Data nascimento;
    struct Cliente *prox; // Ponteiro para o próximo nó
} Cliente;

// LISTA DE PRODUTOS
typedef struct Produto {
    int codigo;
    char nome[100]; 
    float preco; 
    int quantidade_estoque;
    struct Produto *prox; // Ponteiro para o próximo nó
} Produto;

// LISTA DO CARRINHO (Modo Compra)
typedef struct ItemCarrinho {
    int codigo_produto;
    char nome_produto[100]; //Persistência de dados
    float preco_unitario; //Persistência de preço
    int quantidade_compra;
    struct ItemCarrinho *prox; // Ponteiro para o próximo nó
} ItemCarrinho;

// Gestão de Clientes
void adicionarCliente(Cliente **lista, Cliente novo_cliente);
void removerCliente(Cliente **lista, char *cpf);
void listarClientes(Cliente *lista);
Cliente* buscarCliente(Cliente *lista, char *cpf);

// Gestão de Produtos
void adicionarProduto(Produto **lista, Produto novo_produto);
void removerProduto(Produto **lista, int codigo);
void listarProdutos(Produto *lista);
Produto* buscarProduto(Produto *lista, int codigo);

// Carrinho
void adicionar_ao_carrinho(ItemCarrinho **carrinho, Produto *produto, int qtd);
void remover_do_carrinho(ItemCarrinho **carrinho, int codigo_produto);
void finalizar_pedido(ItemCarrinho **carrinho, Produto *lista_produtos); // Atualiza estoque
float calcular_total(ItemCarrinho *carrinho);

// Funções de menu principal
int menu_principal(){
    int opcao;
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("1. Gestão de Clientes\n");
    printf("2. Gestão de Produtos\n");
    printf("3. Modo Venda (Carrinho)\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    limpar_buffer();

    return opcao;    
}

//Limpa Buffer
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

#endif // DADOS_H