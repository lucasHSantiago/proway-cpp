#include "pch.h"
#include "Exported.h"

int Soma(int a, int b)
{
    return a + b;
}

Ponto NewPonto(int x, int y)
{
    return { x, y };
}

void PreencherPonto(Ponto* p)
{
    p->x = 10;
    p->y = 10;
}
