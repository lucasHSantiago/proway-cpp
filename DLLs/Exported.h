#pragma once

/*
O extern "C" em C++ serve para indicar ao compilador que as fun��es devem usar a conven��o de liga��o (linkage) do C, ou seja, sem name mangling.

O que � name mangling?
Quando voc� declara uma fun��o em C++, o compilador altera o nome real da fun��o (nome "mangleado") para incluir informa��es sobre tipos de par�metros, namespaces, sobrecarga etc.

Desvantagens:

N�o pode usar coisas do C++ (biblioteca STL)
*/

DLLS_FUNCT_EXPORT int Soma(int a, int b);

/*
Voc� pode compartilhar structs entre cliente e DLL, desde que ambos usem o mesmo cabe�alho (.h).
*/

struct Ponto
{
    int x;
    int y;
};

DLLS_FUNCT_EXPORT Ponto NewPonto(int x, int y);

/*
O cliente pode alocar mem�ria e passar ponteiros para a DLL usar (e vice-versa), mas isso requer cuidado com a responsabilidade de aloca��o/desaloca��o.

Quem aloca e quem desaloca?

Regra importante:
- Quem aloca, desaloca. Sempre.

Por qu�? Porque a aloca��o de mem�ria pode vir de heaps diferentes, especialmente se:
- A DLL e o cliente usam runtimes diferentes (/MD vs /MT)
- Est�o em linguagens diferentes (ex: C++ e C#)
- Ou usam diferentes vers�es do CRT (C Runtime)
*/

DLLS_FUNCT_EXPORT void PreencherPonto(Ponto* p);
