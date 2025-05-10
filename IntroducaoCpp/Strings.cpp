#include <string>

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
}