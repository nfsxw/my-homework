#include <iostream>
int main()
{
    int a = 5;
    int& ref = a;
    ref++;
    std::cout << a << " " << ref;
}