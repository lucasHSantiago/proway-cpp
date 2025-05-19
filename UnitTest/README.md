### O que � unit test?

Unit test (teste unit�rio) � um teste que verifica individualmente uma fun��o, m�todo ou componente do seu c�digo � de forma isolada, sem depender do resto do sistema.

**Objetivos**:
- Validar se uma fun��o espec�fica faz o que deveria.
- Detectar erros mais cedo no desenvolvimento.
- Facilitar refatora��es seguras.
- Servir como documenta��o viva do comportamento esperado.

### O que � o gTest (Google Test)?

Google Test (gTest) � um framework de testes unit�rios para C++, criado pelo Google.

Ele fornece uma maneira organizada, leg�vel e poderosa de escrever e rodar testes, com v�rias funcionalidades:

**Principais recursos**:
- TEST() para definir testes.
- EXPECT_EQ, ASSERT_EQ, EXPECT_TRUE, etc.
- Agrupamento de testes em suites.
- Fixtures para reuso de configura��o.
- Integra��o com CMake e Visual Studio.

**Documenta��o**:
https://google.github.io/googletest/

### Exerc�cio:

Dado o seguinte c�digo:

```cpp
#pragma once
#include <stdexcept>

class ContaBancaria
{
public:
    ContaBancaria(int saldoInicial = 0)
        : saldo(saldoInicial) {}

public:
    int ObterSaldo() const
    {
        return saldo;
    }

    void Depositar(int valor)
    {
        if (valor < 0)
            throw std::invalid_argument("N�o � poss�vel depositar um valor negativo");

        saldo += valor;
    }

    void Sacar(int valor)
    {
        if (valor < 0)
            throw std::invalid_argument("N�o � poss�vel sacar um valor negativo");

        if (valor > saldo)
            throw std::runtime_error("Saldo insuficiente");

        saldo -= valor;
    }

private:
    int saldo;
};
```

Crie testes unit�rios para que a classe tenha 100% de coverage de testes.
