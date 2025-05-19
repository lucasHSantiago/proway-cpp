### O que é unit test?

Unit test (teste unitário) é um teste que verifica individualmente uma função, método ou componente do seu código — de forma isolada, sem depender do resto do sistema.

**Objetivos**:
- Validar se uma função específica faz o que deveria.
- Detectar erros mais cedo no desenvolvimento.
- Facilitar refatorações seguras.
- Servir como documentação viva do comportamento esperado.

### O que é o gTest (Google Test)?

Google Test (gTest) é um framework de testes unitários para C++, criado pelo Google.

Ele fornece uma maneira organizada, legível e poderosa de escrever e rodar testes, com várias funcionalidades:

**Principais recursos**:
- TEST() para definir testes.
- EXPECT_EQ, ASSERT_EQ, EXPECT_TRUE, etc.
- Agrupamento de testes em suites.
- Fixtures para reuso de configuração.
- Integração com CMake e Visual Studio.

**Documentação**:
https://google.github.io/googletest/

### Exercício:

Dado o seguinte código:

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
            throw std::invalid_argument("Não é possível depositar um valor negativo");

        saldo += valor;
    }

    void Sacar(int valor)
    {
        if (valor < 0)
            throw std::invalid_argument("Não é possível sacar um valor negativo");

        if (valor > saldo)
            throw std::runtime_error("Saldo insuficiente");

        saldo -= valor;
    }

private:
    int saldo;
};
```

Crie testes unitários para que a classe tenha 100% de coverage de testes.
