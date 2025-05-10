#pragma once

#include <string>

using namespace std;

class Funcionario
{
public:
    Funcionario(string nome, double salario, unsigned int idade);
    ~Funcionario();

public:
    void SetNome(string nome);
    string GetNome();

    void SetSalario(double salario);
    double GetSalario();

    void SetIdade(int idade);
    int GetIdade();

private:
    string nome;
    double salario = 0;
    unsigned int idade = 0;
};
