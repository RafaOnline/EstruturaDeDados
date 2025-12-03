
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


