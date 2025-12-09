
# 🏗️ Struct em C: Organizando Dados de Forma Inteligente

## ✅ O que é uma `struct`?

Na programação, lidar com muitos dados separados pode se tornar **confuso e propenso a erros**. Para resolver isso, usamos uma estrutura chamada **`struct`** na linguagem C.

Uma **struct** permite **agrupar diferentes informações (de tipos variados) sobre um mesmo objeto** em um único bloco de dados.  
Cada variável dentro da struct é chamada de **membro** ou **campo**, e pode ter um tipo diferente.

***

### 🔍 Exemplo Conceitual

Imagine uma estrutura que representa um **aluno** com:

*   **nome** → `char`
*   **idade** → `int`
*   **média** → `float`

Assim, todos os dados do aluno ficam **encapsulados** em uma única estrutura.

***

## ✅ Benefícios do uso de `struct`

*   **Menos repetições** → Reduz redundância no código.
*   **Dados organizados** → Facilita a lógica e manutenção.
*   **Reutilização** → Estruturas podem ser usadas em várias partes do programa.
*   **Listas de estruturas** → Permite criar vetores ou listas de objetos estruturados.

***

## 🔒 Encapsulamento

Encapsular significa **esconder detalhes internos e expor apenas o necessário**.  
Com isso:

*   O código se torna **mais organizado e legível**.
*   É um conceito usado em linguagens orientadas a objetos, mas em C já pode ser praticado com **structs** e boas práticas.

***

## ✅ Exemplo prático em C

Usaremos `typedef` para simplificar a declaração da struct:

```c
#include <stdio.h>

// Usando typedef para criar o tipo Aluno
typedef struct {
    char nome[50];
    int idade;
    float media;
} Aluno;

int main() {
    // Criando e inicializando uma variável do tipo Aluno
    Aluno aluno1 = {"João", 20, 8.5};

    // Acessando dados com o operador '.'
    printf("Aluno: %s\n", aluno1.nome);
    printf("Idade: %d\n", aluno1.idade);
    printf("Média: %.2f\n", aluno1.media);

    return 0;
}
```

***

### ✅ Por que usar `typedef`?

Sem `typedef`, precisaríamos escrever `struct Aluno aluno1;` sempre que declarássemos uma variável.  
Com `typedef`, basta usar `Aluno aluno1;`, tornando o código **mais limpo e legível**.

***

## 🛠 Aplicações práticas

*   **Prontuário médico** → Agrupar nome, idade, histórico.
*   **Caixa de ferramentas** → Agrupar tipo, tamanho, peso.
*   **Jogos** → Agrupar atributos de personagens.

