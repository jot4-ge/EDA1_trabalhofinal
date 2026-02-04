# 🛒 Sistema de Gestão Comercial - Listas Encadeadas em C

> **Trabalho Prático:** Estruturas de Dados e Algoritmos 1 (EDA)  
> **Linguagem:** C (Padrão C99/ANSI)  
> **Arquitetura:** Modular (Cabeçalhos e Implementações separadas)

## 📄 Sobre o Projeto

Este projeto consiste em um sistema de gerenciamento para uma empresa de pequeno porte, executado via terminal. O objetivo principal foi implementar estruturas de dados dinâmicas (**Listas Simplesmente Encadeadas**) para realizar operações de **CRUD** (Create, Read, Update, Delete) em Clientes e Produtos, além de um módulo de Vendas (Carrinho) integrado.

O sistema foi desenvolvido seguindo rigorosamente os princípios de **alocação dinâmica de memória**, **modularização** e **não utilização de variáveis globais**.

---

## ✨ Funcionalidades

### 👥 1. Gestão de Clientes
- [x] **Cadastrar:** Inserção de novos clientes (CPF, Nome, Email, Telefone, Data de Nascimento).
- [x] **Listar:** Visualização de todos os clientes cadastrados.
- [x] **Buscar:** Consulta rápida por CPF.
- [x] **Editar:** Atualização de dados cadastrais.
- [x] **Remover:** Exclusão de clientes da base de dados.

### 📦 2. Gestão de Produtos
- [x] **Cadastrar:** Inserção de produtos com controle de estoque.
- [x] **Listar:** Relatório de produtos disponíveis.
- [x] **Buscar:** Consulta por código único.
- [x] **Editar:** Ajuste de preços ou reposição de estoque.
- [x] **Remover:** Exclusão de produtos do catálogo.

### 🛒 3. Modo Compra (Caixa)
- [x] **Login do Cliente:** Barreira de segurança que exige um CPF válido para abrir o carrinho.
- [x] **Adicionar ao Carrinho:** Seleção de produtos com **validação de estoque em tempo real**.
- [x] **Visualizar Carrinho:** Listagem parcial com cálculo de subtotal.
- [x] **Remover do Carrinho:** Possibilidade de desistência de itens antes da compra.
- [x] **Finalizar Pedido:** Baixa automática no estoque oficial e limpeza da memória do carrinho.

---

## 🛠️ Decisões de Engenharia e Estruturas de Dados

Para demonstrar domínio sobre diferentes técnicas de manipulação de listas, adotamos estratégias distintas para cada módulo:

| Módulo | Estrutura Adotada | Justificativa |
| :--- | :--- | :--- |
| **Clientes** | **Ponteiro Simples / Duplo** | Implementação clássica. Uso de `Cliente **` para inserção/remoção, permitindo alteração direta do ponteiro inicial da lista. |
| **Produtos** | **Célula Cabeça (Dummy Head)** | Utilização de um nó sentinela vazio no início da lista para simplificar a lógica de remoção e evitar *edge cases* no primeiro elemento. |
| **Carrinho** | **Ponteiro Duplo (Sem Cabeça)** | Como o carrinho é uma lista temporária de alta rotatividade (criada e destruída frequentemente), optamos pela estrutura mais leve (sem nó extra) para otimizar alocação. |

### 🛡️ Prevenção de Erros (Sanitização)
Implementamos no módulo `utils.c` a função `limpar_buffer()`, utilizada em todo o sistema para limpar o buffer do teclado (`stdin`), prevenindo erros de leitura comuns ao usar `scanf` em C.

---

## 📂 Estrutura de Arquivos

O projeto foi dividido para garantir a responsabilidade única de cada arquivo:

* `main.c`: Orquestrador do sistema, menus e loop principal.
* `dados.h`: "Contrato" do sistema. Contém as definições de `structs` e protótipos de funções.
* `clientes.c`: Lógica de negócios referente aos clientes.
* `produtos.c`: Lógica de negócios referente aos produtos.
* `carrinho.c`: Lógica de vendas e integração entre Clientes e Produtos.
* `utils.c`: Funções auxiliares (limpeza de buffer, inicialização de listas).

---

## 🚀 Como Compilar e Rodar

Pré-requisitos: Compilador **GCC**.

1.  **Clone o repositório:**
    ```bash
    git clone [https://github.com/seu-usuario/seu-repo.git](https://github.com/seu-usuario/seu-repo.git)
    cd seu-repo
    ```

2.  **Compile o projeto:**
    ```bash
    gcc main.c clientes.c produtos.c carrinho.c utils.c -o projeto
    ```

3.  **Execute:**
    * **Windows:**
        ```bash
        ./projeto.exe
        ```
    * **Linux/Mac:**
        ```bash
        ./projeto
        ```

---

## ✅ Checklist de Requisitos Técnicos

* [x] Implementação exclusivamente em C.
* [x] Uso obrigatório de listas simplesmente encadeadas.
* [x] Alocação dinâmica (`malloc`, `free`).
* [x] **Sem variáveis globais.**
* [x] Manipulação por passagem de parâmetros (Referência).
* [x] Limpeza de memória (Free) ao encerrar o programa.

---

### 👨‍💻 Autores

* **João Guilherme | 242004742**
* **Heitor Pinheiro | 242028682**

---
*Trabalho desenvolvido para a disciplina de Estruturas de Dados 1 - Fevereiro/2026.*
