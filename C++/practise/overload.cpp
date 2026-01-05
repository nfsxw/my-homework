#include <iostream>

int Max(int, int);
double Max(double, double);
int Power(int, int);

int main() {
    std::cout << Max(5, 3) << "\t" << Max (5.5, 3.3) << "\n";
    std::cout << Power(2, 4) << std::endl;
    return 0;
}

int Max(int a, int b) {
    return a > b ? a : b;
}

double Max(double a, double b) {
    return a > b ? a : b;
}

int Power(int num, int power) {
    if(power == 0) return 1;
    return num * Power(num, power - 1);
}
