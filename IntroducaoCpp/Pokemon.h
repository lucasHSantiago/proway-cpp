#pragma once

#include <string>

using uint = unsigned int;

class Pokemon
{
public:
    //Força as classes bases a sobreescreverem
    virtual void Ataque() = 0;

public:
    void SetNumero(uint numero);
    uint GetNumero();

    void SetAtaque(uint ataque);
    uint GetAtaque();

    void SetNome(std::string nome);
    std::string GetNome();

private:
    uint numero = 0;
    uint ataque = 0;
    std::string nome;
};

