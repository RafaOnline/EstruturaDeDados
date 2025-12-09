/*
PRÁTICA: SISTEMA DE BIBLIOTECA
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes Globais
#define MAX_LIVROS 50
#define TAM_STRING 100
#define MAX_EMPRESTIMOS 100

// Definição da estrutura (Struct)
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel;
};

// Struct para armazenar informações de empréstimo
struct Emprestimo {
    int indiceLivro;
    char nomeUsuario[TAM_STRING];
};

// Protótipos das funções
void limparBufferEntrada();
void exibirMenu();
void cadastrarLivro(struct Livro *biblioteca, int *totalLivros);
void listarLivros(const struct Livro *biblioteca, int totalLivros);
void realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int *totalEmprestimos);
void listarEmprestimos(const struct Livro *biblioteca, const struct Emprestimo *emprestimos, int totalEmprestimos);
void liberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos);

// Função principal
int main() {
    struct Livro *biblioteca = (struct Livro *)calloc(MAX_LIVROS, sizeof(struct Livro));
    struct Emprestimo *emprestimos = (struct Emprestimo *)malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    if (biblioteca == NULL || emprestimos == NULL) {
        printf("Erro: Falha ao alocar memória.\n");
        return 1;
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
        case 1:
            cadastrarLivro(biblioteca, &totalLivros);
            break;

        case 2:
            listarLivros(biblioteca, totalLivros);
            break;

        case 3:
            realizarEmprestimo(biblioteca, totalLivros, emprestimos, &totalEmprestimos);
            break;

        case 4:
            listarEmprestimos(biblioteca, emprestimos, totalEmprestimos);
            break;

        case 0:
            printf("\nSaindo do sistema...\n");
            break;

        default:
            printf("\nOpção inválida! Tente novamente.\n");
            printf("Pressione ENTER para continuar...");
            getchar();
            break;
        }

    } while (opcao != 0);

    liberarMemoria(biblioteca, emprestimos);
    return 0;
}

// Funções

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibirMenu() {
    printf("\n================================================\n");
    printf("           BIBLIOTECA VIRTUAL\n");
    printf("================================================\n");
    printf("1- Cadastrar novo livro\n");
    printf("2- Listar todos os livros\n");
    printf("3- Realizar empréstimo\n");
    printf("4- Listar empréstimos\n");
    printf("0- Sair\n");
    printf("------------------------------------------------\n");
    printf("Escolha uma opção: ");
}

void cadastrarLivro(struct Livro *biblioteca, int *totalLivros) {
    printf("\n--- Cadastro de Novo Livro ---\n");

    if (*totalLivros < MAX_LIVROS) {
        int i = *totalLivros;

        printf("Digite o nome do livro: ");
        fgets(biblioteca[i].nome, TAM_STRING, stdin);

        printf("Digite o autor: ");
        fgets(biblioteca[i].autor, TAM_STRING, stdin);

        printf("Digite a editora: ");
        fgets(biblioteca[i].editora, TAM_STRING, stdin);

        biblioteca[i].nome[strcspn(biblioteca[i].nome, "\n")] = '\0';
        biblioteca[i].autor[strcspn(biblioteca[i].autor, "\n")] = '\0';
        biblioteca[i].editora[strcspn(biblioteca[i].editora, "\n")] = '\0';

        printf("Digite a edição: ");
        scanf("%d", &biblioteca[i].edicao);
        limparBufferEntrada();

        biblioteca[i].disponivel = 1;

        (*totalLivros)++;
        printf("\nLivro cadastrado com sucesso!\n");

    } else {
        printf("Biblioteca cheia! Não é possível cadastrar mais livros.\n");
    }

    printf("\nPressione ENTER para continuar...");
    getchar();
}

void listarLivros(const struct Livro *biblioteca, int totalLivros) {
    printf("\n--- Lista de Livros Cadastrados ---\n");

    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
    } else {

        for (int i = 0; i < totalLivros; i++) {
            printf("-------------------------------------\n");
            printf("LIVRO %d\n", i + 1);
            printf("Nome: %s\n", biblioteca[i].nome);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Editora: %s\n", biblioteca[i].editora);
            printf("Edição: %d\n", biblioteca[i].edicao);
            printf("Disponível: %s\n", biblioteca[i].disponivel ? "Sim" : "Não");
        }
        printf("-------------------------------------\n");
    }

    printf("\nPressione ENTER para continuar...");
    getchar();
}

void realizarEmprestimo(struct Livro *biblioteca, int totalLivros, struct Emprestimo *emprestimos, int *totalEmprestimos) {
    printf("\n--- Realizar Empréstimo ---\n");

    if (*totalEmprestimos >= MAX_EMPRESTIMOS) {
        printf("Limite de empréstimos atingido.\n\n");
        return;
    }

    printf("Livros disponíveis:\n");
    int disponiveis = 0;

    for (int i = 0; i < totalLivros; i++) {
        if (biblioteca[i].disponivel) {
            printf("%d - %s\n", i + 1, biblioteca[i].nome);
            disponiveis++;
        }
    }

    if (disponiveis == 0) {
        printf("Nenhum livro disponível para empréstimo.\n");
        return;
    }

    printf("\nDigite o número do livro que deseja emprestar: ");
    int numLivro;
    scanf("%d", &numLivro);
    limparBufferEntrada();

    int indice = numLivro - 1;

    if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel) {

        printf("Digite o nome do usuário: ");
        fgets(emprestimos[*totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
        emprestimos[*totalEmprestimos].nomeUsuario[strcspn(emprestimos[*totalEmprestimos].nomeUsuario, "\n")] = '\0';

        emprestimos[*totalEmprestimos].indiceLivro = indice;
        biblioteca[indice].disponivel = 0;

        (*totalEmprestimos)++;

        printf("\nEmpréstimo realizado com sucesso!\n");

    } else {
        printf("\nNúmero inválido ou livro indisponível.\n");
    }

    printf("\nPressione ENTER para continuar...");
    getchar();
}

void listarEmprestimos(const struct Livro *biblioteca, const struct Emprestimo *emprestimos, int totalEmprestimos) {
    printf("\n--- Lista de Empréstimos ---\n");

    if (totalEmprestimos == 0) {
        printf("Nenhum empréstimo realizado.\n");
    } else {
        for (int i = 0; i < totalEmprestimos; i++) {
            int indice = emprestimos[i].indiceLivro;

            printf("-------------------------------------\n");
            printf("Empréstimo %d\n", i + 1);
            printf("Livro: %s\n", biblioteca[indice].nome);
            printf("Usuário: %s\n", emprestimos[i].nomeUsuario);
        }
        printf("-------------------------------------\n");
    }

    printf("\nPressione ENTER para continuar...");
    getchar();
}

void liberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos) {
    free(biblioteca);
    free(emprestimos);

    printf("Memória liberada com sucesso.\n");
}
