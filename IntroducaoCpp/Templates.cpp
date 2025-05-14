#include <iostream>

using namespace std;

namespace Templates
{
    namespace Definicao
    {
        template <typename T>
        T Soma(T a, T b)
        {
            return a + b;
        }

        int main()
        {
            int i = Soma(1, 2);
            double d = Soma(1.0, 2.0);
            float f = Soma(1.0f, 2.0f);

            return 0;
        }
    }

    namespace Especializacao
    {
        template <typename T>
        T Soma(T a, T b)
        {
            return a + b;
        }

        template<>
        double Soma(double a, double b)
        {
            std::cout << "Caiu no double" << std::endl;
            return a + b;
        }

        int main()
        {
            double d = Soma(1.0, 2.0);

            return 0;
        }
    }

    namespace Exercicio
    {
        /*
        1. Criar uma função genérica de max (maior valor)
        2. Criar para int, double, float e string
        */

        template<typename T>
        T Max(T a, T b)
        {
            if (a > b)
                return a;

            return b;
        }

        template<>
        const std::string& Max(const std::string& a, const std::string& b)
        {
            if (a.length() > b.length())
                return a;

            return b;
        }

        int main()
        {
            int i = Max(1, 2);
            double d = Max(1.0, 2.0);
            float f = Max(1.0f, 2.0f);
            std::string s = Max("abc", "a");

            return 0;
        }
    }
}
