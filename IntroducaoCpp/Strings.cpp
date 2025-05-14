#include <string>
#include <iostream>

using namespace std;

namespace Strings
{
    int main()
    {
        string nome = "Lucas";
        nome += " Santiago";

        size_t tamanho = nome.length();

        string primeiroNome = nome.substr(0, 5);

        return 0;
    }

    namespace Exercicio
    {
        /*
            1. Peça ao usuário para digitar duas frases.
            2. Mostre o tamanho (número de caracteres) de cada frase.
            3. Verifique se as frases são iguais.
        */
        int main()
        {
            std::string frase1, frase2;

            std::cout << "Digite a primeira frase: ";
            std::getline(std::cin, frase1);

            std::cout << "Digite a segunda frase: ";
            std::getline(std::cin, frase2);

            std::cout << "\nTamanho da primeira frase: " << frase1.length() << " caracteres\n";
            std::cout << "Tamanho da segunda frase: " << frase2.length() << " caracteres\n";

            if (frase1 == frase2)
            {
                std::cout << "As frases sao iguais.\n";

            }
            else
            {
                std::cout << "As frases sao diferentes.\n";
            }

            return 0;
        }
    }
}