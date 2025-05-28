#include <iostream>
#include <stdexcept>

namespace Exceptions
{
    namespace Uso
    {
        int dividir(int a, int b)
        {
            if (b == 0)
                throw std::invalid_argument("Divis�o por zero!"); // Lan�a uma exce��o

            return a / b;
        }

        int main()
        {
            try
            {
                std::cout << dividir(10, 2) << std::endl; // OK
                std::cout << dividir(10, 0) << std::endl; // Vai lan�ar exce��o!
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
            throw std::runtime_error("Erro padr�o!");
        }

        void funcao2()
        {
            throw 42; // Exce��o tipo int (n�o padr�o!)
        }

        void funcao3()
        {
            throw "Exce��o tipo string literal!"; // Exce��o tipo const char*
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
                    std::cout << "Exce��o padr�o capturada: " << e.what() << std::endl;
                }
                catch (...)
                {
                    std::cout << "Exce��o desconhecida capturada!" << std::endl;
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
                throw MinhaException("Valor negativo n�o permitido!");
        }

        int main()
        {
            try
            {
                checarValor(-5);
            }
            catch (const MinhaException& e)
            {
                std::cout << "Exce��o capturada: " << e.what() << std::endl;
            }

            return 0;
        }
    }
}

/*
Boas pr�ticas com exce��es em C++
- S� lance exce��es para situa��es realmente excepcionais!
- N�o use exce��es para controle de fluxo normal.
- Sempre capture por refer�ncia (catch(const T& e)), para evitar c�pia desnecess�ria.
- Prefira lan�ar objetos derivados de std::exception
- Assim voc� pode usar o m�todo .what() para obter a mensagem do erro.
- Evite lan�ar tipos primitivos como throw 42; ou throw "erro";.
- Prefira objetos.
- RAII: Objetos locais ter�o seus destrutores chamados corretamente no caso de exce��o (garantindo libera��o de recursos).

Diferen�as para outras linguagens
- Em C++, exce��es n�o s�o obrigat�rias (n�o h� checked exceptions como em Java).
- O uso de exce��es pode ser mais custoso em termos de desempenho comparado a erros retornados por c�digos, por isso � reservado para casos cr�ticos.
- A manipula��o manual de recursos (mem�ria, arquivos) precisa ser bem feita, pois vazamentos podem ocorrer se n�o usar RAII ou smart pointers.
*/