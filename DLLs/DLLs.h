#pragma once

/*

Serve para facilitar a importação e exportação de classes

*/

#ifdef _INSIDE_DLLS
#define DLLS_EXT_CLASS _declspec(dllexport)
#define DLLS_FUNCT_EXPORT extern "C" DLLS_EXT_CLASS
#else
#define DLLS_EXT_CLASS _declspec(dllimport)
#define DLLS_FUNCT_EXPORT extern "C" DLLS_EXT_CLASS

#include "ClassExports.h"
#endif
