/*

Multithreading � a execu��o concorrente de m�ltiplas threads dentro de um �nico processo ou programa.
Isso melhora o desempenho e a efici�ncia de uma aplica��o ao permitir que v�rias tarefas sejam executadas em paralelo.

Em C++, o suporte a multithreading est� dispon�vel por meio da biblioteca thread, introduzida no padr�o C++11.

*/


/*
Concurrent:

Concorr�ncia significa �execu��o fora de ordem�. Trata-se de pegar um conjunto de instru��es que normalmente
seriam executadas em sequ�ncia e encontrar uma forma de execut�-las fora de ordem, ainda
assim produzindo o mesmo resultado.

Paralelismo:

Significa executar duas ou mais tarefas/instru��es ao mesmo tempo.

*/

#include <thread>
#include <iostream>

namespace Basico
{
    void my_function()
    {
        std::cout << "essa funcao e executada em uma thread separada" << std::endl;
    }

    int main()
    {
        std::thread t(my_function);
        t.join(); // espera a thread finalizar

        return 0;
    }
}

namespace Parametros
{
    void print_sum(int a, int b)
    {
        std::cout << "A soma e: " << a + b << std::endl;
    }

    int main()
    {
        std::thread t(print_sum, 3, 5);
        t.join();
        return 0;
    }
}

#include <mutex>

namespace MutexLocks
{
    /*
    Um mutex � um objeto que permite que apenas uma thread acesse um recurso cr�tico por vez. Ele fornece os mecanismos de travamento manual.

    Utilizado para evitar "data race"
    */
    std::mutex mtx;

    void print_block(int n, char c)
    {
        /*
        Um lock � uma abstra��o segura que usa um mutex por baixo dos panos.
        Ele automaticamente adquire o mutex no in�cio e o libera ao final do escopo, evitando erros humanos.
        */

        //Destrava no destrutor
        std::unique_lock<std::mutex> locker(mtx);
        for (int i = 0; i < n; ++i) {
            std::cout << c;
        }
        std::cout << '\n';
    }

    int main()
    {
        std::thread t1(print_block, 50, '*');
        std::thread t2(print_block, 50, '$');

        t1.join();
        t2.join();

        return 0;
    }
}

#include <shared_mutex>
#include <vector>

namespace UniqueShared
{
    std::shared_mutex shared_mtx;

    void reader(int id)
    {
        std::shared_lock<std::shared_mutex> lock(shared_mtx);
        std::cout << "Reader " << id << " reading...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "Reader " << id << " finished.\n";
    }

    void writer(int id)
    {
        std::unique_lock<std::shared_mutex> lock(shared_mtx);
        std::cout << "Writer " << id << " writing...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Writer " << id << " finished.\n";
    }

    int main()
    {
        std::vector<std::thread> threads;

        // Leitores simult�neos
        threads.emplace_back(reader, 1);
        threads.emplace_back(reader, 2);

        // Escritor (bloqueia leitores e outros escritores)
        threads.emplace_back(writer, 1);

        // Leitores adicionais (devem esperar o escritor)
        threads.emplace_back(reader, 3);
        threads.emplace_back(reader, 4);

        for (auto& t : threads) t.join();

        return 0;
    }
}

#include <iostream>
#include <future>
#include <chrono>

namespace Async
{
    /*
        Qual a diferen�a entre async e uma thread convencional?

        async voc� tem o retorno da fun��o. Criando um objeto future voc� consegue pegar num momento posterior o retorno da fun��o que rodou na thread.
    */

    int computeSquare(int x)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Simula trabalho pesado
        return x * x;
    }

    int main()
    {
        std::cout << "Iniciando tarefa ass�ncrona...\n";

        // Lan�a a fun��o computeSquare em outra thread
        std::future<int> result = std::async(std::launch::async, computeSquare, 10);

        std::cout << "Fazendo outras coisas enquanto calcula...\n";

        // Aguarda o resultado (bloqueia aqui se ainda n�o terminou)
        int value = result.get();

        std::cout << "Resultado: " << value << std::endl;

        return 0;
    }
}

#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

namespace Atomic
{

    std::atomic<int> contador(0);

    void incrementa(int vezes)
    {
        for (int i = 0; i < vezes; ++i) {
            ++contador; // Opera��o at�mica
        }
    }

    int main()
    {
        const int numThreads = 4;
        const int numIncrementos = 100000;

        std::vector<std::thread> threads;

        // Cria v�rias threads que incrementam o contador
        for (int i = 0; i < numThreads; ++i)
        {
            threads.emplace_back(incrementa, numIncrementos);
        }

        // Espera todas terminarem
        for (auto& t : threads)
        {
            t.join();
        }

        std::cout << "Valor final do contador: " << contador << std::endl;
        // Esperado: numThreads * numIncrementos = 400000

        return 0;
    }
}

#include <concurrent_vector.h>

namespace Concurrent
{
    void adicionar_valores(Concurrency::concurrent_vector<int>& vec, int inicio, int fim)
    {
        for (int i = inicio; i < fim; ++i)
        {
            vec.push_back(i); // Thread-safe
        }
    }

    int main()
    {
        Concurrency::concurrent_vector<int> vec;

        const int num_threads = 4;
        const int valores_por_thread = 1000;
        std::vector<std::thread> threads;

        for (int t = 0; t < num_threads; ++t)
        {
            int inicio = t * valores_por_thread;
            int fim = inicio + valores_por_thread;
            threads.emplace_back(adicionar_valores, std::ref(vec), inicio, fim);
        }

        for (auto& th : threads)
        {
            th.join();
        }

        std::cout << "Total de elementos: " << vec.size() << std::endl;
        std::cout << "Primeiros 10 elementos: ";
        for (int i = 0; i < 10 && i < vec.size(); ++i)
        {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        return 0;
    }
}