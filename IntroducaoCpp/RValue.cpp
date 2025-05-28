#include <string>
#include <iostream>
#include <vector>

/*
Lvalues (Left Values):
S�o valores que t�m um nome e um endere�o na mem�ria. Voc� pode colocar algo �� esquerda� do sinal de atribui��o.
Exemplo: vari�veis, elementos de arrays, refer�ncias.

Rvalues (Right Values):
S�o valores tempor�rios, sem um endere�o de mem�ria identific�vel. S� existem enquanto aquela express�o est� sendo avaliada.
Eles s� podem aparecer � direita do sinal de atribui��o.
Exemplos: literais (42, 3.14), resultados de express�es (a + b), valores retornados por fun��es que n�o retornam refer�ncia.
*/

namespace Variavel
{
    int main()
    {
        int&& rvalue = 1;

        return 0;
    }
}

namespace Overload
{
    void processa(const std::string& s)
    {
        std::cout << "Recebi um lvalue\n";
    }

    void processa(std::string&& s)
    {
        std::cout << "Recebi um rvalue\n";
    }

    std::string criaStr() { return "texto"; }

    int main()
    {
        std::string nome = "Maria";
        processa(nome);         // Chama vers�o lvalue
        processa(criaStr());    // Chama vers�o rvalue

        return 0;
    }
}

namespace Move
{
    /*
    � uma fun��o do C++11 em diante, usada para converter um objeto lvalue em um rvalue,
    permitindo que voc� aplique move semantics (sem�ntica de movimento) � ou seja,
    transferir recursos internos de um objeto para outro, em vez de copiar.
    */
    namespace Variavel
    {
        int main()
        {
            std::vector<std::string> nomes1;
            nomes1.push_back("Ana");
            nomes1.push_back("Bruno");
            nomes1.push_back("Carlos");

            std::cout << "Antes do move:\n";
            std::cout << "nomes1.size(): " << nomes1.size() << "\n";

            // std::move transforma nomes1 em um rvalue (tempor�rio)
            std::vector<std::string> nomes2 = std::move(nomes1);

            std::cout << "Depois do move:\n";
            std::cout << "nomes1.size(): " << nomes1.size() << "\n"; // Deve ser 0 ou indefinido
            std::cout << "nomes2.size(): " << nomes2.size() << "\n"; // Deve ser 3

            for (const auto& nome : nomes2)
            {
                std::cout << nome << "\n";
            }

            return 0;
        }
    }

    namespace Construtor
    {
        class Pessoa
        {
        public:
            std::string nome;

            Pessoa(const std::string& n) : nome(n)
            {
                std::cout << "Construtor comum\n";
            }

            // Move constructor
            Pessoa(Pessoa&& outra) noexcept
                : nome(std::move(outra.nome))
            {
                std::cout << "Construtor de move\n";
            }
        };

        int main() {
            Pessoa a("Jo�o");
            Pessoa b = std::move(a); // Invoca o construtor de move

            std::cout << "a.nome: " << a.nome << "\n"; // Est� vazio ou indefinido
            std::cout << "b.nome: " << b.nome << "\n"; // Jo�o

            return 0;
        }
    }
}