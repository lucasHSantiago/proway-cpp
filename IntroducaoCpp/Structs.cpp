#include <string>

using namespace std;

namespace Structs
{
    /*
    Por padr�o os campos s�o publicos essa � a diferen�a pra classe
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