#include <string>

using namespace std;

namespace Strings
{
    int main()
    {
        string nome = "Lucas";
        nome += " Santiago";

        int tamanho = nome.length();

        auto findPosicao = find(nome.begin(), nome.end(), "S");

        string primeiroNome = nome.substr(0, 5);

        return 0;
    }
}