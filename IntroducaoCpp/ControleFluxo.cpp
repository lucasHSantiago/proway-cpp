#include <iostream>

using namespace std;

namespace ControleFluxo
{
    int main()
    {
        // Condicional
        {
            if (true)
            {

            }

            if (true)
            {

            }
            else
            {

            }

            switch (10)
            {
                case 10:
                    break;

                default:
                    break;
            }
        }

        // Loop
        {
            for (int i = 0; i < 10; ++i)
            {

            }

            while (true)
            {

            }

            do
            {

            } while (true);
        }

        return 0;
    }

    /*
    **Exerc�cio pr�tico**:

    Pe�a ao usu�rio para digitar um n�mero inteiro positivo.

    O programa deve:

    1. Verificar se o n�mero � **par ou �mpar** usando `if`/`else`.
    2. Usar um `switch` para imprimir uma mensagem especial apenas se o n�mero for 1, 3 ou 5.
    3. Contar e exibir quantos m�ltiplos de 2 existem entre 1 e o n�mero digitado, usando `for`.
    4. **Interromper** a contagem no la�o se encontrar um m�ltiplo de 10 (usar `break`).
    5. **Ignorar** o n�mero 6, caso apare�a, com `continue`.
    */
    void Exercicio2()
    {
        int numero = 0;
        cin >> numero;

        if (numero % 2 == 0)
        {
            cout << "par" << endl;
        }
        else
        {
            cout << "impar" << endl;
        }

        switch (numero)
        {
            case 1:
                cout << "seu numero e o um" << endl;
                break;

            case 3:
                cout << "seu numero e o tres" << endl;
                break;

            case 5:
                cout << "seu numero e o cinco" << endl;
                break;
        }

        int qtdMultiplos = 0;
        for (int i = 1; i <= numero; ++i)
        {
            if (i == 6)
                continue;

            if (i % 2 == 0)
                ++qtdMultiplos;

            if (i % 10 == 0)
                break;
        }

        cout << "Existem " << qtdMultiplos << " multiplos de 2" << endl;
    }
}
