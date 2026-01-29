#include "dados.h"

void remover_enter(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void adicionarCliente(Cliente **lista) {
    Cliente *novo_no;

    novo_no = (Cliente *) malloc(sizeof(Cliente));

    if (novo_no == NULL) {
        printf("Erro fatal: Memória insuficiente!\n");
        return;
    }

    printf(" ---Novo Cliente ---\n");

    printf("Digite o CPF: ");
    fgets(novo_no->cpf, 15, stdin);    
    remover_enter(novo_no->cpf);

    printf("Digite o nome: ");
    fgets(novo_no->nome, 100, stdin);   
    remover_enter(novo_no->nome);

    printf("Digite o email: ");
    fgets(novo_no->email, 80, stdin);
    remover_enter(novo_no->email);

    printf("Digite o telefone: ");
    fgets(novo_no->telefone, 20, stdin);   
    remover_enter(novo_no->telefone);

    novo_no->prox = *lista;

    *lista = novo_no;

    printf("Cliente adicionado com sucesso!\n");
    
}

void listarClientes(Cliente *lista) {
    // Verificação de UX
    if (lista == NULL) {
        printf("\n[Aviso] Nenhum cliente cadastrado ainda.\n");
        return;
    }

    Cliente *aux = lista;

    printf("\n--- Lista de Clientes ---\n");
    while (aux != NULL) {

        printf("CPF: %s\n", aux->cpf);
        printf("Nome: %s\n", aux->nome);
        printf("Email: %s\n", aux->email);
        printf("Telefone: %s\n", aux->telefone);
        printf("------------------------\n");
        aux = aux->prox;



    }

}

void removerCliente(Cliente **lista, char *cpf) {
    // Verifica se a lista está vazia
    if (*lista == NULL) {
        printf("\n[Erro] A lista ja esta vazia.\n");
        return;
    }

    Cliente *atual = *lista;
    Cliente *anterior = NULL;

    // strcmp retorna 0 se as strings forem iguais
    while (atual != NULL && strcmp(atual->cpf, cpf) != 0) {
        anterior = atual;       
        atual = atual->prox;    
    }

    if (atual == NULL) {
        printf("\n[Aviso] Cliente com CPF %s nao encontrado.\n", cpf);
        return;
    }

    if (anterior == NULL) {

        *lista = atual->prox; 
    } else {
        
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("\n>>> Sucesso! Cliente removido do sistema. <<<\n");
}

