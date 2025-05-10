#include <iostream>
#include <vector>

using namespace std;

namespace Vetores
{
    namespace Array
    {
        int main()
        {
            char array[10] = { 0 };
            int length = sizeof(array) / sizeof(array[0]);
            for (int i = 0; i < length; ++i)
            {
                array[i] = i + 1;
            }

            for (int i = 0; i < length; ++i)
            {
                cout << "Valor: " << array[i] << endl;
            }

            return 0;
        }
    }

    namespace Vector
    {
        int main()
        {
            vector<int> vetor;

            for (int i = 0; i < 10; ++i)
            {
                vetor.push_back(i + 1);
            }

            for (int val : vetor)
            {
                cout << "Valor: " << val << endl;
            }

            return 0;
        }
    }

    namespace Exercicio
    {
        /*
        Ler 5 números, calcular média e encontrar o maior valor
        */
        void Exercicio()
        {
            vector<int> valores(5);
            cout << "Informe um valor: ";
            for (int i = 0; i < valores.size(); ++i)
            {
                cin >> valores[i];
            }

            int maior = 0;
            int media = 0;

            for (int i = 0; i < valores.size(); ++i)
            {
                if (i == 0 || valores[i] > maior)
                    maior = valores[i];

                media = valores[i];
            }

            cout << "Maior valor: " << maior << endl;
            cout << "Media: " << media / valores.size() << endl;
        }
    }
}