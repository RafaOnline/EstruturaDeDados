
# 📚 Conhecendo as Estruturas de Dados

## ✅ Conceito

**Estrutura de dados** é um modelo utilizado para **organizar, armazenar e manipular informações** dentro de um programa de forma eficiente.

*   **Analogia:**
    *   **Dados do programa** → “Alimentos”
    *   **Memória do computador** → “Despensa”

Organizar bem os dados é essencial para otimizar **tempo de execução**, **uso de memória** e **facilidade de manutenção**.

***

## 🔗 Estruturas de Dados Lineares

Em uma **estrutura linear**, os elementos são organizados em sequência, um após o outro, formando uma linha lógica.

### **Principais estruturas**

*   **Vetores (Arrays)**
*   **Listas**
*   **Pilhas (Stacks)**
*   **Filas (Queues)**

***

## 🛠 Onde usar na prática?

*   **LISTA** → Gerenciar os contatos de um aplicativo.
*   **FILA** → Controlar pedidos que chegam em um site de e-commerce (ordem de chegada).
*   **PILHA** → Implementar a função “desfazer” (Ctrl+Z) em um editor de texto.

***

## 🔍 Explicando cada estrutura com exemplos em C

### **1. Vetor**

Um vetor é uma coleção de elementos do mesmo tipo, armazenados em posições contíguas na memória.

```c
#include <stdio.h>

int main() {
    int numeros[5] = {10, 20, 30, 40, 50};

    for(int i = 0; i < 5; i++) {
        printf("Elemento %d: %d\n", i, numeros[i]);
    }
    return 0;
}
```

✅ **Uso:** Ideal para armazenar dados fixos, como notas de alunos.

***

### **2. Lista**

Uma lista pode ser **dinâmica**, permitindo inserção e remoção de elementos sem tamanho fixo.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* prox;
} Node;

int main() {
    Node* lista = NULL;
    Node* novo = (Node*) malloc(sizeof(Node));
    novo->valor = 10;
    novo->prox = lista;
    lista = novo;

    printf("Valor na lista: %d\n", lista->valor);
    return 0;
}
```

✅ **Uso:** Gerenciar contatos, tarefas ou qualquer coleção dinâmica.

***

### **3. Pilha (Stack)**

Segue o princípio **LIFO** (Last In, First Out).

```c
#include <stdio.h>
#define MAX 5

int pilha[MAX];
int topo = -1;

void push(int valor) {
    if(topo < MAX - 1) {
        pilha[++topo] = valor;
    }
}

int pop() {
    if(topo >= 0) {
        return pilha[topo--];
    }
    return -1;
}

int main() {
    push(10);
    push(20);
    printf("Removido: %d\n", pop());
    return 0;
}
```

✅ **Uso:** Função “desfazer” em editores.

***

### **4. Fila (Queue)**

Segue o princípio **FIFO** (First In, First Out).

```c
#include <stdio.h>
#define MAX 5

int fila[MAX];
int inicio = 0, fim = 0;

void enqueue(int valor) {
    if(fim < MAX) {
        fila[fim++] = valor;
    }
}

int dequeue() {
    if(inicio < fim) {
        return fila[inicio++];
    }
    return -1;
}

int main() {
    enqueue(10);
    enqueue(20);
    printf("Removido: %d\n", dequeue());
    return 0;
}
```

✅ **Uso:** Processamento de pedidos em ordem de chegada.

***

## 📝 Resumo

*   **Estrutura de Dados** → Organizar e manipular informações.
*   **Estruturas Lineares** → Vetores, Listas, Pilhas e Filas.
*   **Aplicação prática** → Exemplos reais e implementação em C.
