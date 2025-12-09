

# 🔐 Escopo de Variáveis em C — Entendendo Escopo Local e Global

O **escopo** define **onde uma variável pode ser acessada dentro de um programa**.
Em C, isso determina **visibilidade**, **tempo de vida** e **segurança do código**.

---

## 🏨 Analogia Simples: Hotel

* Um hóspede tem uma chave que **abre somente o seu quarto** → **escopo local**
* O gerente tem um cartão que **abre todos os quartos** → **escopo global**

Essa comparação mostra como variáveis podem ter acesso limitado ou total no programa.

---

## 📌 O que é Escopo?

Em programação, escopo é **a região do código onde uma variável é válida**.

Entender escopo ajuda a:

* evitar conflitos de nomes
* controlar o uso da memória
* impedir acessos indevidos
* organizar melhor o código

Em C, as variáveis podem ter dois tipos principais de escopo: **local** e **global**.

---

# 🧩 Tipos de Escopo

## 🔸 1. Escopo Local

Uma variável é **local** quando é declarada **dentro de uma função**.
Ela existe somente naquela função.

📌 **Analogia:**
Um copo d’água servido no almoço — serve apenas para aquele momento.

📌 **Exemplo:**
Se você escreve uma lista de compras e guarda no seu bolso, só você acessa — escopo local.

```c
void funcao() {
    int x = 10; // variável local
}
```

* Só pode ser usada dentro dessa função.
* Deixa o código mais seguro e organizado.
* Evita acessos indevidos de outras partes do programa.

---

## 🔸 2. Escopo Global

Uma variável é **global** quando é declarada **fora de qualquer função**.
Ela pode ser acessada por **todo o programa**.

📌 **Analogia:**
Um quadro na cozinha com a lista de compras — todos da casa podem ver e alterar.

```c
int contador = 0; // variável global

void funcao1() {
    contador++;
}

void funcao2() {
    contador += 2;
}
```

⚠️ **Cuidado!**
Variáveis globais podem gerar problemas se muitas partes do código alterarem seus valores sem controle.

---

# 🧪 Exemplo Completo na Prática

```c
#include <stdio.h>

int global = 5; // variável global

int main() {
    int local = 10; // variável local
    printf("Global: %d\n", global);
    printf("Local: %d\n", local);
    return 0;
}
```

✔️ `global` pode ser usada em qualquer função
✔️ `local` existe apenas dentro da função `main()`

---

# ✅ Resumo

| Tipo de Escopo | Onde é Declarado  | Onde é Acessível      | Vantagens                   | Riscos               |
| -------------- | ----------------- | --------------------- | --------------------------- | -------------------- |
| **Local**      | Dentro de funções | Apenas naquela função | Seguro, organizado          | Não compartilhado    |
| **Global**     | Fora de funções   | Em todo o programa    | Compartilhado entre módulos | Difícil de controlar |

