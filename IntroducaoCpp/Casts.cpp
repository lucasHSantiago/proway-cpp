#include <iostream>

namespace Casts
{
    class BaseClass
    {
    public:
        virtual void display()
        {
            std::cout << "BaseClass\n";
        }
    };

    class DerivedClass : public BaseClass
    {
    public:
        void display()
        {
            std::cout << "DerivedClass\n";
        }
    };

    int main()
    {
        // Faz um tratamento em tempo de compilação e retorna erro em caso de tipos divergentes;
        {
            int i = 42;
            float f = static_cast<float>(i);
        }

        // Permite remover ou adicionar const em variáveis
        {
            const int original = 10;
            int* nao_constante = const_cast<int*>(&original);
            *nao_constante = 11;
        }

        //Usado para polimorfismo
        {
            BaseClass* basePtr = new DerivedClass();
            DerivedClass* derivedPtr;

            derivedPtr = dynamic_cast<DerivedClass*>(basePtr);
            if (derivedPtr)
            {
                derivedPtr->display();
            }
            else
            {
                std::cout << "Invalid type conversion.";
            }
        }

        //Permite alterar o tipo do ponteiro sem alterar o tipo do dado
        {
            int num = 42;
            int* num_ptr = &num;

            char* char_ptr = reinterpret_cast<char*>(num_ptr);

            for (size_t i = 0; i < sizeof(int); ++i)
            {
                std::cout << "Byte " << i << ": " << char_ptr[i] << '\n';
            }
        }

        return 0;
    }
}