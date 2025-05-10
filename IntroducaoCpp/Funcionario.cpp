#include "Funcionario.h"

Funcionario::Funcionario(string nome, double salario, unsigned int idade)
{
    this->nome = nome;
    this->salario = salario;
    this->idade = idade;
}

Funcionario::~Funcionario()
{
}

void Funcionario::SetNome(string nome)
{
    this->nome = nome;
}

string Funcionario::GetNome()
{
    return this->nome;
}

void Funcionario::SetSalario(double salario)
{
    this->salario = salario;
}

double Funcionario::GetSalario()
{
    return this->salario;
}

void Funcionario::SetIdade(int idade)
{
    this->idade = idade;
}

int Funcionario::GetIdade()
{
    return this->idade;
}

