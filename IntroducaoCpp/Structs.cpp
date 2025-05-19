#include <iostream>
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
        Funcionario funcionario{};
        funcionario.nome  = "Pedro";
        funcionario.salario = 800.50;
        funcionario.idade = 18;

        return 0;
    }

    namespace PaddingPack
    {

        /*
        Em C++, o compilador insere bytes extras (chamados de padding) dentro de structs para alinhamento.
        O objetivo é otimizar o acesso à memória — por exemplo, em processadores que leem 4 ou 8 bytes de uma vez.
        */

        //O tamanho real é 8 e não 5
        struct ExemploPadding
        {
            char a;   // 1 byte
            int b;    // 4 bytes
        };

        /*
        Packing é o processo de remover ou controlar o padding usando diretivas do compilador como `#pragma pack`.
        */

        #pragma pack(push, 1)
        struct ExemploPack
        {
            char a;  // 1 byte
            int b;   // 4 bytes
        };
        #pragma pack(pop)
    }

    namespace Exercicio
    {
        /*
        Você foi contratado para criar um sistema simples de cadastro de *pontos de interesse* em um mapa 2D. Cada ponto deve conter:

        - Suas coordenadas `x` e `y`
        - Seu tipo (por exemplo: restaurante, hospital, escola)

        Requisitos

        1. Defina uma `struct` chamada `Ponto` com:
            - Dois campos `float x` e `float y`
            - Um campo `TipoPonto tipo` (ver item 2)
        2. Defina:
            - Um `enum class TipoPonto` com os seguintes valores: `Restaurante`, `Hospital`, `Escola`
        3. Escreva uma função `exibirPonto` que receba um `Ponto` e imprima suas informações de forma legível, por exemplo:

            `Ponto em (10.5, 20.3) - Tipo: Escola`
        */

        enum class TipoPonto {
            Restaurante,
            Hospital,
            Escola
        };

        struct Ponto {
            float x;
            float y;
            TipoPonto tipo;
        };

        std::string tipoParaString(TipoPonto tipo) {
            switch (tipo) {
                case TipoPonto::Restaurante:
                    return "Restaurante";
                case TipoPonto::Hospital:
                    return "Hospital";
                case TipoPonto::Escola:
                    return "Escola";
                default:
                    return "Desconhecido";
            }
        }

        void exibirPonto(const Ponto& p) {
            std::cout << "Ponto em (" << p.x << ", " << p.y << ") - Tipo: " << tipoParaString(p.tipo) << std::endl;
        }

        int main() {
            Ponto p1 = { 10.5f, 20.3f, TipoPonto::Escola };
            Ponto p2 = { 5.0f, 12.7f, TipoPonto::Restaurante };
            Ponto p3 = { 8.2f, 3.3f, TipoPonto::Hospital };

            exibirPonto(p1);
            exibirPonto(p2);
            exibirPonto(p3);

            return 0;
        }
    }
}