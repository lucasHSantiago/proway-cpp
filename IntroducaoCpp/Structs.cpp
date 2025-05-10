#include <string>

using namespace std;

namespace Structs
{
    /*
    Por padrão os campos são publicos essa é a diferença pra classe
    */
    struct Funcionario
    {
        string nome;
        double salario;
        unsigned int idade;
    };

    int main()
    {
        Funcionario funcionario;
        funcionario.nome  = "Pedro";
        funcionario.salario = 800.50;
        funcionario.idade = 18;

        return 0;
    }
}