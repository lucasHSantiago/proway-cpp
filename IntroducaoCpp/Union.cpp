#include <iostream>

/*
A union em C++ (e também em C) é um tipo especial de estrutura que permite armazenar
diferentes tipos de dados no mesmo bloco de memória, mas somente um desses tipos pode
estar ativo em um dado momento.
*/

namespace Union
{
    namespace Tipo
    {
        union Numero
        {
            int inteiro;
            float decimal;
            char caractere;
        };

        int main()
        {
            Numero n;

            n.inteiro = 65;
            std::cout << "Como inteiro: " << n.inteiro << std::endl;   // 65
            std::cout << "Como caractere: " << n.caractere << std::endl; // 'A' (ASCII 65)

            n.decimal = 3.14f;
            std::cout << "Como decimal: " << n.decimal << std::endl;   // 3.14
            std::cout << "Como inteiro depois do decimal: " << n.inteiro << std::endl; // Valor indefinido!

            return 0;
        }
    }

    namespace Flag
    {
        union Dados
        {
            uint32_t valor;
            struct
            {
                uint8_t byte0;
                uint8_t byte1;
                uint8_t byte2;
                uint8_t byte3;
            }
            bytes;
        };

        int main()
        {
            Dados d;
            d.valor = 0x11223344; // Valor em hexadecimal

            std::cout << std::hex;
            std::cout << "byte0: " << (int)d.bytes.byte0 << std::endl; // 44 (little endian)
            std::cout << "byte1: " << (int)d.bytes.byte1 << std::endl; // 33
            std::cout << "byte2: " << (int)d.bytes.byte2 << std::endl; // 22
            std::cout << "byte3: " << (int)d.bytes.byte3 << std::endl; // 11

            return 0;
        }
    }

    namespace Bitfield
    {
        union Flags
        {
            uint32_t valor;
            struct
            {
                unsigned int flagA : 1; // 1 bit
                unsigned int flagB : 3; // 3 bits
                unsigned int flagC : 4; // 4 bits
                unsigned int reservado : 24; // restante
            }
            bits;
        };

        int main()
        {
            Flags f{};
            f.valor = 0; // Zera tudo

            f.bits.flagA = 1; // Liga flagA (bit 0)
            f.bits.flagB = 5; // Coloca valor 5 nos bits 1-3
            f.bits.flagC = 12; // Coloca valor 12 nos bits 4-7

            std::cout << std::hex << "Valor: 0x" << f.valor << std::endl;

            // Acessando individualmente:
            std::cout << "FlagA: " << f.bits.flagA << std::endl;
            std::cout << "FlagB: " << f.bits.flagB << std::endl;
            std::cout << "FlagC: " << f.bits.flagC << std::endl;

            return 0;
        }
    }
}