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
}