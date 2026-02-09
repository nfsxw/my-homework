#include <iostream>
#include <limits>

int main()
{
    int arr[5];
    int num;
    std::cout << "Enter your array: ";
    for(int i = 0; i < 5; i++){
        std::cin >> arr[i];
    }
    std::cout << "Enter number of element: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> num;
    num--;

    if(num < 0 || num > 4) {
        std::cout << "Error: index out of range";
        return 0;
    }
    std::cout << "Your element is: " << arr[num] << "\n";
    std::cout << "Your array's size is " << sizeof(arr) << " bytes.";
    return 0;
}