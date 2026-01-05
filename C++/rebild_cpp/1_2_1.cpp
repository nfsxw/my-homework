#include <iostream>
#include <limits>

int main() {
    int sum = 0, x;
    int n;
    
    std::cout << "Enter the number of digits: ";
    if(!(std::cin >> n) || n <= 0) {
        std::cout << "Wrong number of digits!" << std::endl;
        return 0;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for(int i = 0; i < n; i++) {
        if (std::cin >> x) {
            sum += x;
        } else {
            std::cout << "Invalid input, skipping!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            i--;
        }
    }
    std::cout << "Sum total: " << sum << std::endl;
}