#include <memory>

#include "Pikachu.h"

namespace Polimorfismo
{
    int main()
    {
        std::unique_ptr<Pokemon> pikachu = std::make_unique<Pikachu>();

        //Tem acesso por que está na classe base
        pikachu->Ataque();

        return 0;
    }
}