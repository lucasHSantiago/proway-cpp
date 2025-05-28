#include <algorithm>
#include <vector>
#include <iostream>

/*
Um functor (ou “function object”/objeto função) é qualquer objeto em C++ que pode ser chamado como se fosse uma função – ou seja, usando o operador de chamada de função operator().

Na prática:
É uma classe (ou struct) que implementa o método especial operator().
Você pode criar instâncias dessa classe e chamá-las como se fossem funções normais.
Functors podem guardar estado interno (variáveis), ao contrário de funções normais.

Por que usar Functor?
Permite encapsular lógica com dados internos.
Facilita passar comportamentos customizados para algoritmos (como sort, filter, etc.).
Muito usado na STL antes da existência de lambdas (e ainda é importante em alguns cenários).
*/

namespace Functor
{
    namespace Basico
    {
        struct Multiplicador
        {
            int fator;
            // Construtor
            Multiplicador(int f) : fator(f) {}
            // Functor: define o operator()
            int operator()(int x) const
            {
                return x * fator;
            }
        };

        int main()
        {
            Multiplicador mult2(2); // Functor com fator 2
            std::cout << mult2(10) << std::endl; // Chama mult2.operator()(10), imprime 20

            Multiplicador mult5(5);
            std::cout << mult5(3) << std::endl;  // Imprime 15

            //Lambada equivalente
            auto mult2 = [fator = 2](int x) { return x * fator; };
            std::cout << mult2(10); // Imprime 20
        }
    }

    namespace STL
    {
        struct ComparadorDecrescente
        {
            bool operator()(int a, int b) const
            {
                return a > b;
            }
        };

        int main()
        {
            std::vector<int> v = { 5, 1, 4, 2 };
            std::sort(v.begin(), v.end(), ComparadorDecrescente());
            for (int n : v) std::cout << n << ' '; // Imprime: 5 4 2 1
        }
    }
}