#include <iostream>

int multiply(int, int);
void increment(int&);

int main()
{
    int a = 5;
    int b = 3;
    std::cout << multiply(a, b);
    increment(a);
    std::cout << "\t" << a;
}

int multiply(int a, int b) {
    return a*b;
}

void increment(int& ref){
    ref++;
}