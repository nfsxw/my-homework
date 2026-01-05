#include <iostream>
#include <string>

int main()
{
    int group_num;
    float gpa;
    std::string Name;
    std::cout << "Enter your group number: ";
    std::cin >> group_num;
    std::cout << "Enter your full name: ";
    std::cin.ignore();
    std::getline(std::cin, Name);
    std::cout << "Enter your GPA: ";
    std::cin >> gpa;
    std::cout << "You are " << Name << ", student of B25-" << group_num << ", your GPA is " << gpa << std::endl;
    return 0;
}