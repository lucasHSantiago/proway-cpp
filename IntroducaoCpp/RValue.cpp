#include <string>
#include <iostream>
#include <vector>

/*
Lvalues (Left Values):
São valores que têm um nome e um endereço na memória. Você pode colocar algo “à esquerda” do sinal de atribuição.
Exemplo: variáveis, elementos de arrays, referências.

Rvalues (Right Values):
São valores temporários, sem um endereço de memória identificável. Só existem enquanto aquela expressão está sendo avaliada.
Eles só podem aparecer à direita do sinal de atribuição.
Exemplos: literais (42, 3.14), resultados de expressões (a + b), valores retornados por funções que não retornam referência.
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
        processa(nome);         // Chama versão lvalue
        processa(criaStr());    // Chama versão rvalue

        return 0;
    }
}

namespace Move
{
    /*
    É uma função do C++11 em diante, usada para converter um objeto lvalue em um rvalue,
    permitindo que você aplique move semantics (semântica de movimento) — ou seja,
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

            // std::move transforma nomes1 em um rvalue (temporário)
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
            Pessoa a("João");
            Pessoa b = std::move(a); // Invoca o construtor de move

            std::cout << "a.nome: " << a.nome << "\n"; // Está vazio ou indefinido
            std::cout << "b.nome: " << b.nome << "\n"; // João

            return 0;
        }
    }
}