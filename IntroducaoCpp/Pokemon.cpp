#include "Pokemon.h"

void Pokemon::SetNumero(uint numero)
{
    this->numero = numero;
}

uint Pokemon::GetNumero()
{
    return this->numero;
}

void Pokemon::SetAtaque(uint ataque)
{
    this->ataque = ataque;
}

uint Pokemon::GetAtaque()
{
    return this->ataque;
}

void Pokemon::SetNome(std::string nome)
{
    this->nome = nome;
}

std::string Pokemon::GetNome()
{
    return this->nome;
}
