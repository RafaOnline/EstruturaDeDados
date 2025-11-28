
# 🧠 Alocação e Desalocação Dinâmica de Memória em C

## ✅ Conceito

A memória é onde os dados e instruções de um programa são armazenados durante sua execução.  
Em C, podemos trabalhar com dois tipos de alocação:

***

### **1. Alocação Estática (ou Automática)**

*   Ocorre quando declaramos variáveis comuns, como:

```c
int x = 10;
```

*   O compilador reserva espaço fixo na memória **em tempo de compilação**.
*   A quantidade de memória é **pré-definida**.

***

### **2. Alocação Dinâmica**

*   Usada quando **não sabemos o tamanho necessário antes da execução**.
*   Exemplo: ler uma quantidade de dados definida pelo usuário.
*   O programa solicita memória **durante a execução** e deve **liberá-la manualmente**.

***

## ✅ Funções principais para alocação dinâmica

### **malloc() – Memory Allocation**

*   Aloca um bloco de memória do tamanho especificado (em bytes).
*   **Não inicializa** os valores.
*   Retorna um **ponteiro para o início do bloco**.

**Sintaxe:**

```c
ptr = (tipo*) malloc(tamanho_em_bytes);
```

**Exemplo:**

```c
int *vetor = (int*) malloc(5 * sizeof(int));
```

***

### **calloc() – Clear Allocation**

*   Aloca memória e **inicializa todos os bytes com zero**.
*   Recebe dois parâmetros: quantidade de elementos e tamanho de cada elemento.

**Sintaxe:**

```c
ptr = (tipo*) calloc(qtd_elementos, tamanho_elemento);
```

**Exemplo:**

```c
int *vetor = (int*) calloc(5, sizeof(int));
```

***

### **free()**

*   Libera a memória alocada dinamicamente.
*   Evita **vazamentos de memória**.

**Sintaxe:**

```c
free(ptr);
```

***

## ✅ Exemplo prático com malloc e free

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("Digite a quantidade de números: ");
    scanf("%d", &n);

    // Alocando memória para n inteiros
    int *vetor = (int*) malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Lendo valores
    for (i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Exibindo valores
    printf("Valores digitados: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    // Liberando memória
    free(vetor);

    return 0;
}
```

***

## ✅ Quando usar alocação dinâmica?

*   Quando a quantidade de dados **não é conhecida antes da execução**.
*   Em estruturas como:
    *   **Listas encadeadas**
    *   **Filas**
    *   **Árvores**
    *   **Vetores redimensionáveis**

***

## ⚠️ Erros comuns e como evitar

*   **Não verificar se malloc/calloc retornou NULL** → Sempre valide.
*   **Esquecer de usar free()** → Causa vazamento de memória.
*   **Usar ponteiro após liberar memória** → Comportamento indefinido.

