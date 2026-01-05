#include <iostream>
#include <limits>

int main() {
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    if(size <= 0) {
        std::cout << "Wrong size!" << std::endl;
        return 0;
    }

    int *arr = new int[size];
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for(int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    for(int i = 1; i <= size; i++) {
        std::cout << arr[size - i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
}