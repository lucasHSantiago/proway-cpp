#pragma once

class Animal
{
    void Come()
    {
    }
};

class Mamifero : virtual public Animal
{
};

class Ave : virtual public Animal
{
};

class Morcego : public Mamifero, public Ave
{
};
