#include <iostream>
#include <stdexcept>

namespace Exceptions
{
    namespace Uso
    {
        int dividir(int a, int b)
        {
            if (b == 0)
                throw std::invalid_argument("Divisão por zero!"); // Lança uma exceção

            return a / b;
        }

        int main()
        {
            try
            {
                std::cout << dividir(10, 2) << std::endl; // OK
                std::cout << dividir(10, 0) << std::endl; // Vai lançar exceção!
            }
            catch (const std::invalid_argument& e)
            {
                std::cerr << "Erro: " << e.what() << std::endl;
            }

            std::cout << "Programa segue normalmente..." << std::endl;
            return 0;
        }
    }

    namespace Generico
    {
        void funcao1()
        {
            throw std::runtime_error("Erro padrão!");
        }

        void funcao2()
        {
            throw 42; // Exceção tipo int (não padrão!)
        }

        void funcao3()
        {
            throw "Exceção tipo string literal!"; // Exceção tipo const char*
        }

        int main()
        {
            for (int i = 1; i <= 3; ++i)
            {
                try
                {
                    if (i == 1) funcao1();
                    if (i == 2) funcao2();
                    if (i == 3) funcao3();
                }
                catch (const std::exception& e)
                {
                    std::cout << "Exceção padrão capturada: " << e.what() << std::endl;
                }
                catch (...)
                {
                    std::cout << "Exceção desconhecida capturada!" << std::endl;
                }
            }

            std::cout << "Programa continua normalmente." << std::endl;
            return 0;
        }
    }

    namespace Custom
    {
        class MinhaException : public std::exception
        {
        public:
            explicit MinhaException(const std::string& msg) : mensagem(msg) {}

            const char* what() const noexcept override
            {
                return mensagem.c_str();
            }

        private:
            std::string mensagem;
        };

        void checarValor(int x)
        {
            if (x < 0)
                throw MinhaException("Valor negativo não permitido!");
        }

        int main()
        {
            try
            {
                checarValor(-5);
            }
            catch (const MinhaException& e)
            {
                std::cout << "Exceção capturada: " << e.what() << std::endl;
            }

            return 0;
        }
    }
}

/*
Boas práticas com exceções em C++
- Só lance exceções para situações realmente excepcionais!
- Não use exceções para controle de fluxo normal.
- Sempre capture por referência (catch(const T& e)), para evitar cópia desnecessária.
- Prefira lançar objetos derivados de std::exception
- Assim você pode usar o método .what() para obter a mensagem do erro.
- Evite lançar tipos primitivos como throw 42; ou throw "erro";.
- Prefira objetos.
- RAII: Objetos locais terão seus destrutores chamados corretamente no caso de exceção (garantindo liberação de recursos).

Diferenças para outras linguagens
- Em C++, exceções não são obrigatórias (não há checked exceptions como em Java).
- O uso de exceções pode ser mais custoso em termos de desempenho comparado a erros retornados por códigos, por isso é reservado para casos críticos.
- A manipulação manual de recursos (memória, arquivos) precisa ser bem feita, pois vazamentos podem ocorrer se não usar RAII ou smart pointers.
*/