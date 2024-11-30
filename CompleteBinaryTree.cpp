#include <iostream>

int main()
{
    std::cout << "Hello World!\n";

    int b = 1;
    int c = 0;

    for (int i = 0; i < 7; i++)
    {
        b = 1 << c;
		std::cout << b << std::endl;
		c++;
    }
}