#include <iostream>

namespace OperatorOverload
{
    class Vetor2D
    {
    public:
        double x, y;

        Vetor2D(double x = 0, double y = 0) : x(x), y(y) {}

        // Overload do operador +
        Vetor2D operator+(const Vetor2D& outro) const
        {
            return Vetor2D(x + outro.x, y + outro.y);
        }

        // Overload do operador -
        Vetor2D operator-(const Vetor2D& outro) const
        {
            return Vetor2D(x - outro.x, y - outro.y);
        }

        // Overload do operador * (produto escalar)
        double operator*(const Vetor2D& outro) const
        {
            return x * outro.x + y * outro.y;
        }

        // Overload do operador ==
        bool operator==(const Vetor2D& outro) const
        {
            return x == outro.x && y == outro.y;
        }

        // Overload do operador <<
        friend std::ostream& operator<<(std::ostream& os, const Vetor2D& v)
        {
            os << "(" << v.x << ", " << v.y << ")";
            return os;
        }
    };

    int main()
    {
        Vetor2D a(3, 4);
        Vetor2D b(1, 2);

        Vetor2D soma = a + b; // Chama operator+
        Vetor2D sub = a - b;  // Chama operator-
        double prodEscalar = a * b; // Chama operator*

        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
        std::cout << "Soma: " << soma << std::endl;
        std::cout << "Subtracao: " << sub << std::endl;
        std::cout << "Produto escalar: " << prodEscalar << std::endl;

        if (a == b)
            std::cout << "Vetores iguais\n";
        else
            std::cout << "Vetores diferentes\n";

        return 0;
    }
}