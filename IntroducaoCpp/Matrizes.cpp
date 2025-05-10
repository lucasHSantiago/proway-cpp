#include <iostream>
#include <vector>

using namespace std;

namespace Matrizes
{
    namespace Array
    {
        int main()
        {
            char array[10][5] = {0};
            int linhas = sizeof(array) / sizeof(array[0]);
            for (int i = 0; i < linhas; ++i)
            {
                int colunas = sizeof(array[0]) / sizeof(array[0][0]);

                for (int j = 0; j < colunas; ++j)
                {
                    cout << "Valor: " << array[i][j] << endl;
                }
            }

            return 0;
        }
    }

    namespace Vector
    {
        int main()
        {
            vector<vector<int>> vetor;

            for (int i = 0; i < 10; ++i)
            {
                vector<int> colunas;
                for (int j = 0; j < 10; ++j)
                {
                    colunas.push_back(i * j);
                }

                vetor.push_back(colunas);
            }

            for (auto linhas : vetor)
            {
                for (auto val : linhas)
                {
                    cout << "Valor: " << val << endl;
                }
            }

            return 0;
        }
    }

    namespace Exercicio
    {
        /*
        Ler notas de 3 alunos em 2 provas e calcular média final
        */
        void Exercicio()
        {
            vector<vector<double>> alunosNotas(3);
            for (int i = 0; i < alunosNotas.size(); ++i)
            {
                vector<double> notas(2);
                for (int j = 0; j < notas.size(); ++j)
                {
                    cout << "Informe a nota: ";
                    cin >> notas[j];
                }

                alunosNotas[i] = notas;
            }

            for (int i = 0; i < alunosNotas.size(); ++i)
            {
                vector<double> notas = alunosNotas[i];
                double media = 0;
                for (int j = 0; j < notas.size(); ++j)
                {
                    media += notas[j];
                }

                cout << "A media do aluno " << i << "e: " << media / notas.size() << endl;
            }
        }
    }
}
