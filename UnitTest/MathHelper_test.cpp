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
            // Voc� pode fazer o trabalho de configura��o para cada teste aqui.
        }

        ~MathTest() override
        {
            // Voc� pode fazer a limpeza que n�o lan�a exce��es aqui.
        }

        // Se o construtor e o destrutor n�o forem suficientes para configurar
        // e limpar cada teste, voc� pode definir os seguintes m�todos:

        void SetUp() override
        {
            // O c�digo aqui ser� chamado imediatamente ap�s o construtor (logo
            // antes de cada teste).
        }

        void TearDown() override
        {
            // O c�digo aqui ser� chamado imediatamente ap�s cada teste (logo
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
