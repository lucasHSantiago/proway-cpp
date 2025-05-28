#include <iostream>
#include <functional>

/*
Ela permite armazenar, copiar e manipular qualquer "coisa que se comporte como fun��o": fun��es normais, lambdas, m�todos de classe, functors, etc.
*/

namespace Function
{
    namespace Funcao
    {
        void imprimir(int x)
        {
            std::cout << "Valor: " << x << std::endl;
        }

        int main()
        {
            std::function<void(int)> func = imprimir;
            func(42); // Chama imprimir(42)

            return 0;
        }
    }

    namespace Lamda
    {
        int main()
        {
            std::function<int(int, int)> soma = [](int a, int b)
                {
                    return a + b;
                };

            std::cout << soma(3, 7) << std::endl; // Imprime 10

            return 0;
        }
    }

    //Objeto que se comporta como fun��o
    namespace Functor
    {
        struct Multiplicador
        {
            int fator;
            Multiplicador(int f) : fator(f) {}
            int operator()(int x) const { return x * fator; }
        };

        int main()
        {
            Multiplicador mult2(2);
            std::function<int(int)> func = mult2;
            std::cout << func(10) << std::endl; // Imprime 20

            return 0;
        }
    }

    namespace Metodo
    {
        class Calculadora
        {
        public:
            int multiplicar(int x, int y) { return x * y; }
        };

        int main()
        {
            Calculadora calc;
            // Bind para associar o m�todo ao objeto calc
            std::function<int(int, int)> func = std::bind(&Calculadora::multiplicar, &calc, std::placeholders::_1, std::placeholders::_2);
            std::cout << func(4, 5) << std::endl; // Imprime 20
        }
    }

    namespace FuncaoCallBack
    {
        void executaOperacao(int x, int y, const std::function<int(int, int)>& operacao)
        {
            std::cout << operacao(x, y) << std::endl;
        }

        int main()
        {
            executaOperacao(10, 5, [](int a, int b) { return a + b; }); // Soma
            executaOperacao(10, 5, [](int a, int b) { return a - b; }); // Subtrai
        }
    }
}