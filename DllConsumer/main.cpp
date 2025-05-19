#include <iostream>
#include <Windows.h>

#include "../DLLs/DLLs.h"
#include "../DLLs/Exported.h"
#include "../DLLs/MathHelper.h"

typedef int (*SomaFunc)(int, int);

int main()
{
    //Carregamento implicito gerenciado pelo sistema operacional
    int x = Soma(1, 2);

    std::cout << "x: " << x << std::endl;

    //Carregamento din�mico da DLL controlada pelo c�digo
    HMODULE dllHandle = LoadLibrary("DLLs.dll");
    if (!dllHandle) {
        return 1;
    }

    // Pega o ponteiro da fun��o
    SomaFunc soma = (SomaFunc)GetProcAddress(dllHandle, "Soma");
    if (!soma) {
        FreeLibrary(dllHandle);
        return 1;
    }

    x = soma(3, 4);
    std::cout << "x: " << x << std::endl;
    FreeLibrary(dllHandle);

    x = MathHelper::Soma(5, 6);
    std::cout << "x: " << x << std::endl;

    return 0;
}