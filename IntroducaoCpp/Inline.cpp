/*
O que é uma função inline?
Uma função inline é uma sugestão ao compilador para que, ao invés de gerar uma chamada
normal de função, o compilador substitua a chamada pelo próprio corpo da função,
diretamente no ponto em que ela é chamada. Isso pode, em certos casos, eliminar
o overhead de chamada de função e otimizar o desempenho, especialmente para funções
pequenas e frequentemente chamadas.

O uso de inline é apenas uma sugestão. O compilador pode ou não realmente inlinar a função dependendo de sua política de otimização.
*/

namespace FuncaoInline
{
    inline int soma(int a, int b)
    {
        return a + b;
    }

    /*
    Em C++ moderno, funções definidas dentro da declaração da classe são automaticamente consideradas candidatas a inline
    */
    struct Ponto
    {
        int x, y;
        int soma() { return x + y; } // Inline implícito
    };
}

/*

Vantagens das funções inline
- Reduz overhead de chamada: Evita o custo de empilhar argumentos, saltar para outra posição de memória e retornar.
- Pode melhorar desempenho: Especialmente em funções pequenas, chamadas dentro de loops.
- Facilita definição em headers: Funções pequenas podem ser definidas diretamente no cabeçalho, facilitando a organização do código.

Desvantagens/limitações
- Aumento do tamanho do binário: Se a função for chamada em muitos lugares, o código é duplicado, aumentando o tamanho final do executável (chamado de "code bloat").
- Funções grandes não devem ser inline: O ganho desaparece e o tamanho do código cresce muito.
- O compilador pode ignorar: Não é garantido que a função será realmente inlinada.
- Não use para funções recursivas: Funções recursivas não podem ser inlinadas.

*/