#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <algorithm>

int main()
{
    int a = 0;
    float b = 0.0f;
    double c = 0.0;
    std::string input;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> input;
    std::replace(input.begin(), input.end(), ',', '.');
    try{
        b = static_cast<float>(std::stod(input));
    } catch (const std::invalid_argument&) {
        std::cout << "Invalid input!" << std::endl;
        return 1;
    }
    input.clear();

    std::cout << "Enter c: ";
    std::cin >> input;
    std::replace(input.begin(), input.end(), ',', '.');
    try{
        c = std::stod(input);
    } catch (const std::invalid_argument&) {
        std::cout << "Invalid input!" << std::endl;
        return 1;
    }

    std::cout << "Size of int: " << sizeof(a) << "\n";
    std::cout << "Size of float: " << sizeof(b) << "\n";
    std::cout << "Size of double: " << sizeof(c) << "\n";

    std::cout << std::fixed << std:: setprecision(5) << "Sum is: "
    << static_cast <double> (a) + static_cast <double> (b) + c << "\n";
    return 0;
}
