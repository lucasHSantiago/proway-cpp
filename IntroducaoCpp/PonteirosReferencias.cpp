#include <iostream>
#include <memory>

using namespace std;

namespace PonteirosReferencias
{
    namespace Referencias
    {
        int main()
        {
            int val = 10;
            int& ref = val; //Referência para valor
            ref = 1; //Agora val == 1

            return 0;
        }

        void Troca(int& a, int& b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
    }

    namespace Ponteiros
    {
        int main()
        {
            int* p = new int;
            *p = 10;
            delete p;
            p = nullptr;

            return 0;
        }

        void Foo(int* p)
        {
            delete p; 
            p = nullptr; // O ponteiro original referencia uma posicação invalida de memória
        }

        void Foo(int*& p)
        {
            delete p; 
            p = nullptr; // O ponteiro origianl agora é nullptr
        }

        void Array()
        {
            int* p = new int[10];
            delete[] p; // Chama o destrutor para cada item
        }

        void String()
        {
            const char* texto = "exemplo";
        }
    }

    namespace Memoria
    {
        /*
        A memória stack é usada para variáveis com duração de armazenamento automática, como variáveis locais e dados de chamadas de função.
        A memória stack é gerenciada pelo compilador, e sua alocação e desalocação são feitas automaticamente.
        A memória stack também segue a estrutura de dados LIFO (Last In, First Out – último a entrar, primeiro a sair), o que significa que os dados alocados mais recentemente
        são os primeiros a serem desalocados.
        */
        namespace Stack
        {
            int main()
            {
                int x = 10; // alocado na stack

                return 0;
            }
        }

        /*
        A memória heap é usada para variáveis com duração de armazenamento dinâmica, como objetos criados com a palavra-chave new.
        O programador tem controle sobre a alocação e desalocação da memória heap utilizando os operadores new e delete.
        A memória heap é um espaço maior do que a pilha, porém possui um tempo de acesso mais lento
        */
        namespace Heap
        {
            int main()
            {
                int* p = new int; //alocado no heap
                *p = 10;
                delete p;
                p = nullptr;

                return 0;
            }
        }
    }

    namespace SmartPointers
    {
        namespace UniquePointer
        {
            int main()
            {
                // Faz o delete automaticamente quando não tem mais referenciais
                // Pode ser movido mas não copiado
                unique_ptr<int> uptr = make_unique<int>(10);

                //std::unique_ptr<int> uptr2 = uptr; // erro de compilacao
                unique_ptr<int> uptr2 = move(uptr); // transferencia de "ownership"

                return 0;
            }
        }

        namespace SharedPointer
        {
            int main()
            {
                // Cria um shared_ptr que gerencia um inteiro com valor 10
                shared_ptr<int> sptr = make_shared<int>(10);

                // Agora sptr2 é uma cópia de sptr, ambos compartilham o mesmo recurso
                shared_ptr<int> sptr2 = sptr;

                cout << "Valor: " << *sptr << endl;
                cout << "Use count: " << sptr.use_count() << endl; // Deve mostrar 2

                return 0;
            }
        }

        namespace WeakPointer
        {
            int main()
            {
                std::shared_ptr<int> sptr = std::make_shared<int>(42);
                std::weak_ptr<int> wptr = sptr;

                std::cout << "Use count (shared): " << sptr.use_count() << std::endl;

                if (auto locked = wptr.lock()) {
                    std::cout << "Valor: " << *locked << std::endl;
                }
                else {
                    std::cout << "O recurso já foi liberado." << std::endl;
                }

                sptr.reset(); // Libera o recurso

                if (auto locked = wptr.lock()) {
                    std::cout << "Valor: " << *locked << std::endl;
                }
                else {
                    std::cout << "O recurso já foi liberado." << std::endl;
                }

                return 0;
            }
            /*
            Saida:
            Use count (shared): 1
            Valor: 42
            O recurso já foi liberado.
            */
        }
    }
}