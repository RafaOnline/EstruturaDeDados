# Conceito e manipulação de ponteiros

- & : Operador de endereço
- * : Operador de direção

**Exemplo Código**
```c
#include <stdio.h>

int main () {
    int x = 10;
    int* p = &x; // O ponteiro 'p' recebe o endereço de 'x'

    printf("Valor de x: %d\n", x);    
    printf("Endereço de x: %p\n", &x);  
    printf("Conteúdo de p (o endereço): %p\n", p);  
    printf("Valor apontado por p: %d\n", *p);  

    // Modificando valor através do ponteiro
    *p = 20;

    printf("Novo valor de X: %d\n", x); // Vai imprimir 20!

    return 0;
}
```
