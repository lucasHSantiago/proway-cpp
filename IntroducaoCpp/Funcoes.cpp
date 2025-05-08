#include <iostream>

using namespace std;

namespace Funcoes
{
    namespace Decalracao
    {
        void Foo()
        {
            cout << "Foo()" << endl;
        }

        void Soma(int a, int b)
        {
            cout << "Soma = " << a + b << endl;
        }

        // Parametro default
        void Multiplica(int a, int b = 10)
        {
            cout << "Produto = " << a * b << endl;
        }

        double Divisao(int a, int b)
        {
            return a / b;
        }

        int main()
        {
            Foo();
            Soma(1, 1);
            Multiplica(10);
            return 0;
        }
    }

    namespace Overload
    {
        int Soma(int a, int b)
        {
            return a + b;
        }

        double Soma(double a, double b)
        {
            return a + b;
        }
    }

    namespace Lambda
    {
        /*
            [capture-list](parameters) -> return_type {
                // function body
            };
        */

        int main()
        {
            // Com parametros
            {
                auto funcSoma = [](int a, int b)
                {
                    return a + b;
                };
            }

            // Usando variaveis externas
            {
                int a = 5;
                int b = 5;

                auto funcSoma = [&]()
                {
                    return a + b;
                };
            }

            return 0;
        }
    }

    namespace Exercicio
    {
        /*
        Criar funções: soma, media, maiorValor
        */
        int Soma(int a, int b)
        {
            return a + b;
        }

        int Media(int a, int b, int c)
        {
            return (a + b + c) / 3;
        }

        int MaiorValor(int a, int b)
        {
            if (a > b)
                return a;

            return b;
        }
    }
}