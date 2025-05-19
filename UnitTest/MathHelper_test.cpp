#include "pch.h"

#include "../DLLs/DLLs.h"
#include "../DLLs/MathHelper.h"

namespace Math
{
    class MathTest : public testing::Test
    {
    protected:
        MathTest()
        {
            // Você pode fazer o trabalho de configuração para cada teste aqui.
        }

        ~MathTest() override
        {
            // Você pode fazer a limpeza que não lança exceções aqui.
        }

        // Se o construtor e o destrutor não forem suficientes para configurar
        // e limpar cada teste, você pode definir os seguintes métodos:

        void SetUp() override
        {
            // O código aqui será chamado imediatamente após o construtor (logo
            // antes de cada teste).
        }

        void TearDown() override
        {
            // O código aqui será chamado imediatamente após cada teste (logo
            // antes do destrutor).
        }

        // Membros da classe declarados aqui podem ser usados por todos os testes no conjunto de testes
    };

    TEST_F(MathTest, Positivos)
    {
        int x = MathHelper::Soma(2, 3);
        EXPECT_EQ(x, 5);
    }

    TEST(Soma, Negativos)
    {
        int x = MathHelper::Soma(-2, -3);
        EXPECT_EQ(x, -5);
    }
}
