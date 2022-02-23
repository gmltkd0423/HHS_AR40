#include <iostream>

int value = 0;

void Func()
{
    if (value == 30)
    {
        return;
    }

    value++;

    
    std::cout << value << " ";
    Func();
}

int main()
{
    Func();
}