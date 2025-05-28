#include <algorithm>
#include <vector>
#include <iostream>

/*
Um functor (ou �function object�/objeto fun��o) � qualquer objeto em C++ que pode ser chamado como se fosse uma fun��o � ou seja, usando o operador de chamada de fun��o operator().

Na pr�tica:
� uma classe (ou struct) que implementa o m�todo especial operator().
Voc� pode criar inst�ncias dessa classe e cham�-las como se fossem fun��es normais.
Functors podem guardar estado interno (vari�veis), ao contr�rio de fun��es normais.

Por que usar Functor?
Permite encapsular l�gica com dados internos.
Facilita passar comportamentos customizados para algoritmos (como sort, filter, etc.).
Muito usado na STL antes da exist�ncia de lambdas (e ainda � importante em alguns cen�rios).
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