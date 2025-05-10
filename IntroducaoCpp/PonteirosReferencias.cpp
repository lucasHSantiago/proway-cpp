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
            int& ref = val; //Refer�ncia para valor
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
            p = nullptr; // O ponteiro original referencia uma posica��o invalida de mem�ria
        }

        void Foo(int*& p)
        {
            delete p; 
            p = nullptr; // O ponteiro origianl agora � nullptr
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
        A mem�ria stack � usada para vari�veis com dura��o de armazenamento autom�tica, como vari�veis locais e dados de chamadas de fun��o.
        A mem�ria stack � gerenciada pelo compilador, e sua aloca��o e desaloca��o s�o feitas automaticamente.
        A mem�ria stack tamb�m segue a estrutura de dados LIFO (Last In, First Out � �ltimo a entrar, primeiro a sair), o que significa que os dados alocados mais recentemente
        s�o os primeiros a serem desalocados.
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
        A mem�ria heap � usada para vari�veis com dura��o de armazenamento din�mica, como objetos criados com a palavra-chave new.
        O programador tem controle sobre a aloca��o e desaloca��o da mem�ria heap utilizando os operadores new e delete.
        A mem�ria heap � um espa�o maior do que a pilha, por�m possui um tempo de acesso mais lento
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
                // Faz o delete automaticamente quando n�o tem mais referenciais
                // Pode ser movido mas n�o copiado
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

                // Agora sptr2 � uma c�pia de sptr, ambos compartilham o mesmo recurso
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
                    std::cout << "O recurso j� foi liberado." << std::endl;
                }

                sptr.reset(); // Libera o recurso

                if (auto locked = wptr.lock()) {
                    std::cout << "Valor: " << *locked << std::endl;
                }
                else {
                    std::cout << "O recurso j� foi liberado." << std::endl;
                }

                return 0;
            }
            /*
            Saida:
            Use count (shared): 1
            Valor: 42
            O recurso j� foi liberado.
            */
        }
    }
}