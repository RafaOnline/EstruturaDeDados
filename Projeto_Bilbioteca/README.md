

# 📚 Sistema de Biblioteca em C

Gerenciamento simples de livros e empréstimos

Este projeto é um **sistema de gerenciamento de biblioteca**, desenvolvido totalmente em linguagem C.
Ele permite cadastrar livros, listar coleções, registrar empréstimos e consultar quais obras foram emprestadas, tudo utilizando **memória dinâmica, structs e funções separadas**.

---

## 📌 Funcionalidades

### ✔ Cadastro de livros

O sistema permite registrar novos livros com as seguintes informações:

* Nome do livro
* Autor
* Editora
* Edição
* Status: disponível/indisponível

### ✔ Listagem de livros cadastrados

Exibe todos os livros já cadastrados, com todos os seus detalhes.

### ✔ Empréstimo de livros

O usuário pode:

* Ver todos os livros disponíveis
* Selecionar qual livro deseja emprestar
* Registrar o nome de quem pegou o livro

O livro automaticamente fica marcado como **indisponível**.

### ✔ Listagem de empréstimos

Exibe:

* Qual livro foi emprestado
* Para qual usuário
* Preserva a referência ao livro dentro do array principal

### ✔ Gerenciamento de memória

O programa utiliza:

* `calloc()` para alocar a biblioteca
* `malloc()` para registrar empréstimos
* `free()` para liberar toda a memória ao sair do sistema

---

# 🧱 Estrutura do Código

O sistema é estruturado utilizando **structs** e funções independentes.

---

## 📦 Estrutura `Livro`

```c
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel;
};
```

Armazena todas as informações referentes a um livro.

📌 **`disponivel = 1` (sim)**
📌 **`disponivel = 0` (não)**

---

## 📦 Estrutura `Emprestimo`

```c
struct Emprestimo {
    int indiceLivro;
    char nomeUsuario[TAM_STRING];
};
```

Essa estrutura vincula **o índice do livro** com o **nome do usuário** que pegou o livro emprestado.

---

# 🧠 Lógica do Sistema

## 🏁 1. Início da Aplicação

Ao iniciar, o programa aloca dinamicamente:

```c
struct Livro *biblioteca = calloc(MAX_LIVROS, sizeof(struct Livro));
struct Emprestimo *emprestimos = malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));
```

Isso permite armazenar até:

* **50 livros**
* **100 empréstimos**

---

## 🗂 2. Menu Principal

O programa funciona em loop exibindo o seguinte menu:

```
1 - Cadastrar novo livro
2 - Listar todos os livros
3 - Realizar empréstimo
4 - Listar empréstimos
0 - Sair
```

O usuário escolhe uma das operações e a função correspondente é chamada.

---

# 🔍 Explicação das Funcionalidades

---

## 📘 1. Cadastrar Livro

Função:

```c
void cadastrarLivro(struct Livro *biblioteca, int *totalLivros);
```

O programa:

1. Pede nome, autor e editora usando `fgets()`
2. Remove o `\n` usando `strcspn()`
3. Pede a edição com `scanf()`
4. Marca o livro como **disponível**
5. Incrementa `totalLivros`

---

## 📚 2. Listar Livros

Função:

```c
void listarLivros(const struct Livro *biblioteca, int totalLivros);
```

A função percorre o array de livros e mostra:

* Nome
* Autor
* Editora
* Edição
* Status (disponível ou não)

Caso não tenha livros cadastrados, informa isso ao usuário.

---

## 🔄 3. Realizar Empréstimo

Função:

```c
void realizarEmprestimo(struct Livro *biblioteca, int totalLivros,
                        struct Emprestimo *emprestimos, int *totalEmprestimos);
```

Processo:

1. Mostra apenas livros com `disponivel == 1`
2. Usuario escolhe o número do livro
3. O nome do usuário é solicitado
4. O índice do livro é salvo em `emprestimos[]`
5. O livro passa para `disponivel = 0`
6. Incrementa o total de empréstimos

---

## 📄 4. Listar Empréstimos

Função:

```c
void listarEmprestimos(const struct Livro *biblioteca,
                       const struct Emprestimo *emprestimos,
                       int totalEmprestimos);
```

Exibe todos os empréstimos realizados:

* Nome do livro vinculado
* Nome do usuário que pegou

---

## 🧹 5. Liberação de Memória

Função:

```c
void liberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos);
```

Libera a memória alocada dinamicamente:

```c
free(biblioteca);
free(emprestimos);
```

---

# 🧪 Como Compilar

No terminal use:

```bash
gcc biblioteca.c -o biblioteca
```

Rodar o programa:

```bash
./biblioteca
```

