/*
O que � uma fun��o inline?
Uma fun��o inline � uma sugest�o ao compilador para que, ao inv�s de gerar uma chamada
normal de fun��o, o compilador substitua a chamada pelo pr�prio corpo da fun��o,
diretamente no ponto em que ela � chamada. Isso pode, em certos casos, eliminar
o overhead de chamada de fun��o e otimizar o desempenho, especialmente para fun��es
pequenas e frequentemente chamadas.

O uso de inline � apenas uma sugest�o. O compilador pode ou n�o realmente inlinar a fun��o dependendo de sua pol�tica de otimiza��o.
*/

namespace FuncaoInline
{
    inline int soma(int a, int b)
    {
        return a + b;
    }

    /*
    Em C++ moderno, fun��es definidas dentro da declara��o da classe s�o automaticamente consideradas candidatas a inline
    */
    struct Ponto
    {
        int x, y;
        int soma() { return x + y; } // Inline impl�cito
    };
}

/*

Vantagens das fun��es inline
- Reduz overhead de chamada: Evita o custo de empilhar argumentos, saltar para outra posi��o de mem�ria e retornar.
- Pode melhorar desempenho: Especialmente em fun��es pequenas, chamadas dentro de loops.
- Facilita defini��o em headers: Fun��es pequenas podem ser definidas diretamente no cabe�alho, facilitando a organiza��o do c�digo.

Desvantagens/limita��es
- Aumento do tamanho do bin�rio: Se a fun��o for chamada em muitos lugares, o c�digo � duplicado, aumentando o tamanho final do execut�vel (chamado de "code bloat").
- Fun��es grandes n�o devem ser inline: O ganho desaparece e o tamanho do c�digo cresce muito.
- O compilador pode ignorar: N�o � garantido que a fun��o ser� realmente inlinada.
- N�o use para fun��es recursivas: Fun��es recursivas n�o podem ser inlinadas.

*/