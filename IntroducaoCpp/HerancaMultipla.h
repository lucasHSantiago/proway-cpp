#pragma once

#include <iostream>

class Caminhavel
{
public:
    void Andar()
    {
        std::cout << "Andando..." << std::endl;
    }
};

class Voador
{
public:
    void Voar()
    {
        std::cout << "Voando..." << std::endl;
    }
};

class Nadador
{
public:
    void Nadando()
    {
        std::cout << "Nadando..." << std::endl;
    }
};

class Pato : public Caminhavel, public Voador, public Nadador
{
};
