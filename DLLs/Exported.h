#pragma once

/*
O extern "C" em C++ serve para indicar ao compilador que as funções devem usar a convenção de ligação (linkage) do C, ou seja, sem name mangling.

O que é name mangling?
Quando você declara uma função em C++, o compilador altera o nome real da função (nome "mangleado") para incluir informações sobre tipos de parâmetros, namespaces, sobrecarga etc.

Desvantagens:

Não pode usar coisas do C++ (biblioteca STL)
*/

DLLS_FUNCT_EXPORT int Soma(int a, int b);

/*
Você pode compartilhar structs entre cliente e DLL, desde que ambos usem o mesmo cabeçalho (.h).
*/

struct Ponto
{
    int x;
    int y;
};

DLLS_FUNCT_EXPORT Ponto NewPonto(int x, int y);

/*
O cliente pode alocar memória e passar ponteiros para a DLL usar (e vice-versa), mas isso requer cuidado com a responsabilidade de alocação/desalocação.

Quem aloca e quem desaloca?

Regra importante:
- Quem aloca, desaloca. Sempre.

Por quê? Porque a alocação de memória pode vir de heaps diferentes, especialmente se:
- A DLL e o cliente usam runtimes diferentes (/MD vs /MT)
- Estão em linguagens diferentes (ex: C++ e C#)
- Ou usam diferentes versões do CRT (C Runtime)
*/

DLLS_FUNCT_EXPORT void PreencherPonto(Ponto* p);
