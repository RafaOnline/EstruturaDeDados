
# 📘 Passagem de Parâmetros por Valor em C

Neste capítulo, você vai entender como funciona a passagem de parâmetros por valor na linguagem C e por que esse mecanismo deixa o programa mais seguro, previsível e fácil de entender.

---

## 🔄 O que é passar parâmetros?

Quando criamos funções em programação, muitas vezes precisamos enviar informações para elas realizarem alguma tarefa.
Esse envio de dados é chamado de **passagem de parâmetros**.

Em outras palavras:

> Passar um parâmetro é entregar uma informação para a função trabalhar.

Existem várias formas de fazer isso, e uma das mais comuns em C é a **passagem por valor**.

---

## 🛡️ O que é a passagem por valor?

Na passagem por valor:

* A função recebe **uma cópia** da variável original.
* Modificações feitas na cópia **não alteram** a variável real.
* A variável original permanece intacta na memória.

### 📝 Analogia para facilitar:

Imagine que você tem uma receita no seu caderno.
Você faz uma **cópia** e entrega ao seu amigo.
Ele pode riscar, adicionar ingredientes ou dobrar o papel — mas **sua receita original continua igual**.

Isso é exatamente o que acontece na passagem por valor.

---

## 🎯 Quando usar a passagem por valor?

Esse tipo de passagem é ideal quando:

* você quer apenas consultar ou usar dados para cálculo;
* você quer exibir informações sem alterar o valor original;
* quer evitar efeitos colaterais no código;
* busca segurança e previsibilidade em aplicações maiores.

Funções que consultam, verificam, exibem ou calculam valores normalmente **usam passagem por valor**, porque não precisam modificar o dado original.

---

## 🧪 Exemplo prático em C

O objetivo do código a seguir é mostrar que a função recebe apenas uma cópia da variável:

```c
#include <stdio.h>

void dobrar(int x) {
    x = x * 2;
    printf("Dentro da função: %d\n", x);
}

int main() {
    int numero = 5;

    dobrar(numero);

    printf("Fora da função: %d\n", numero);

    return 0;
}
```

---

## 📤 Saída esperada

```
Dentro da função: 10
Fora da função: 5
```

### Por que isso acontece?

* A função `dobrar(int x)` recebe uma **cópia** de `numero`.
* A alteração ocorre **apenas dentro da função**.
* Fora da função, a variável original `numero` continua com valor 5.

Para alterar o valor original, seria necessário usar **ponteiros** (passagem por referência).

---

## ✅ Conclusão

* A passagem por valor é o comportamento **padrão** da linguagem C.
* Ela mantém o programa seguro e fácil de entender.
* Use quando não houver necessidade de alterar diretamente os dados originais.

---

# 🔗 Passagem de Parâmetros por Referência em C

Neste capítulo, você vai entender como funciona a passagem de parâmetros por referência na linguagem C, como usar ponteiros para modificar valores diretamente e ver um exemplo prático usando a função `dobrar()`.

---

## 🧠 O que é passagem por referência?

Na passagem por referência:

* A função **não recebe uma cópia** da variável.
* Em vez disso, ela recebe o **endereço de memória** onde a variável está armazenada.
* Com esse endereço, a função consegue **alterar o valor original**.

### 📘 Analogia simples

Na passagem por valor, você entrega **uma cópia** da sua receita de brigadeiro.

Na passagem por referência, você entrega **a receita original**.
Se alguém riscar, adicionar ingredientes ou alterar algo, as mudanças ficam registradas na versão original.

---

## 📍 O que é endereço de memória?

Toda variável em C é armazenada em alguma posição da memória, que possui um tipo de "número da casa" — isso é o **endereço**.

### 🧭 E o que é um ponteiro?

Um ponteiro é uma variável especial que **guarda um endereço de memória**, e não um valor diretamente.

* `*` → usado para declarar e acessar o valor apontado
* `&` → usado para obter o endereço de uma variável

### 💡 Analogia prática

Um ponteiro funciona como o endereço da casa de alguém.
Você não está com o presente na mão (valor da variável), mas sabe exatamente **onde entregar** ou **onde modificar** o presente (endereço da memória).

---

## 💬 Pensando de outro jeito…

Imagine uma carta guardada em uma gaveta:

* A carta = variável
* A gaveta = endereço
* O ponteiro = papelzinho com o endereço da gaveta

Quem tem o endereço consegue abrir a gaveta e **alterar diretamente a carta original**.

---

## 🧪 Exemplo prático: dobrando um número

A seguir, temos uma função que recebe um **ponteiro para inteiro**, permitindo alterar o valor original da variável:

```c
#include <stdio.h>

void dobrar(int *x) {
    *x = (*x) * 2;
    printf("Número dobrado: %d\n", *x);
}

int main() {
    int numero = 5;

    dobrar(&numero);

    return 0;
}
```

---

## 📤 Saída esperada

```
Número dobrado: 10
```

### Por que funcionou?

* `int *x` → a função recebe um ponteiro (endereço)
* `&numero` → enviamos o endereço da variável numero
* `*x` → acessamos e modificamos o valor guardado nesse endereço

Como o valor foi alterado **pela referência**, a mudança acontece diretamente na variável original.

---

## 🧭 Quando usar passagem por referência?

Use quando você **precisar alterar o dado original**, como em:

* atualização de saldos
* alteração de vetores e matrizes
* preenchimento de structs
* troca de valores entre variáveis
* funções que precisam retornar múltiplos valores

---

## ⚠️ Cuidados ao usar ponteiros

Ponteiros são poderosos, mas exigem atenção:

* nunca use ponteiros **não inicializados**
* evite acessar áreas inválidas da memória
* sempre garanta que o ponteiro aponta para um endereço válido

Erros com ponteiros podem causar falhas no programa.



