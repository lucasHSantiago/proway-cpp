#include <iostream>

using namespace std;

int main()
{
    // Tipos primitivos
    {
        int i = 10; // 4 bytes
        long l = 10; // 4 bytes
        float f = 10.1f; // 4 bytes, 7 digitos decimais
        double d = 10.1; // 8 bytes, 15 digitos decimais
        char c = 'A'; // 1 byte
        bool b = true; // 1 byte
    }

    // Modificadores
    {
        unsigned long ul = INT32_MAX * 2;
        long long ll = 10;
        unsigned long long ull = 10;
    }

    // Operadores Aritm�ticos
    {
        long x = 10 + 10;
        x = 10 - 10;
        x = 10 / 10;
        x = 10 * 10;
        x = 10 % 10;
        x++;
        x--;
    }

    // Casting Implicito
    {
        {
            long l = 10;
            double d = l;
        }

        {
            double d = 10.1;
            long l = d;
        }
    }

    // Casting explicito
    {

        {
            long l = 10;
            double d = (double)l;
        }

        {
            double d = 10.1;
            long l = (long)d;
        }
    }
}

/*
Exerc�cio pr�tico:
Criar um programa que calcula m�dia e imprime se est� aprovado
*/
void exercicio()
{
    double nota1 = 0;
    cout << "Informe a primeira nota: ";
    cin >> nota1;

    double nota2 = 0;
    cout << "Informe a primeira nota: ";
    cin >> nota2;

    double nota3 = 0;
    cout << "Informe a primeira nota: ";
    cin >> nota3;

    double media = (nota1 + nota2 + nota3) / 3;
    cout << "media = " << media << endl;
}
