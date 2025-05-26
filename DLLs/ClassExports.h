#pragma once

/*

    É uma diretiva de compilação específica do compilador MSVC (Microsoft Visual C++) no Windows.
    Ela serve para linkar automaticamente uma biblioteca estática ou de importação (.lib) durante a compilação,
    sem precisar configurar isso manualmente nas propriedades do projeto.

*/

#ifdef _DEBUG
  #ifdef _WIN64
    #pragma comment(lib, "..\\x64\\Debug\\DLLs.lib")
  #else
    #pragma comment(lib, "..\\DLLs\\Debug\\dlls.lib")
  #endif
#else
  #ifdef _WIN64
    #pragma comment(lib, "..\\DLLs\\x64\\Release\\dlls.lib")
  #else
    #pragma comment(lib, "..\\DLLs\\Release\\dlls.lib")
  #endif
#endif
 