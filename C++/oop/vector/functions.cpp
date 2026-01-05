#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cctype>
#include "my_vector.hpp"
#include "headers.hpp"

void Logic() {
    int answer = 1;
    float x, y;
    std::string name;
    std::vector<my_vector> items;

    while(answer != 0) {
        Clear_screen();
        Interface(items);
        std::cin >> answer;
        switch (answer) {
            case 1:
                Create_vector(items, name, x, y);
                break;
            case 2:
                Delete_vector(items);
                break;
            case 3:
                float product;
                try {
                    Dot_prod(items, product);
                    std::cout << "Dot product is " << product << std::endl;
                    break;
                } catch (int) {
                    break;
                }
            case 4:
                try {
                    items.emplace_back(Sum(items));
                    std::cout << "Enter name of your vector: ";
                    std::cin >> name;
                    items.back().set_name(name);
                    std::cout << std::endl;
                    std::cout << "Your new vector: " << name <<" ("<< items.back().get_x() 
                    << ", " << items.back().get_y() << " )" << std::endl;
                    break;
                } catch (int) {
                    break;
                }
                
            case 5:
                try {
                    items.emplace_back(Sub(items));
                    std::cout << "Enter name of your vector: ";
                    std::cin >> name;
                    items.back().set_name(name);
                    std::cout << std::endl;
                    std::cout << "Your new vector: " << name <<" ("<< items.back().get_x() 
                    << ", " << items.back().get_y() << " )" << std::endl;
                    break;
                } catch(int) {
                    break;
                }
                
            case 6:
                try {
                    std::cout << "Length of your vector is: " << Vector_length(items) << std::endl;
                    break;
                } catch (int) {
                    break;
                }
            case 7:
                    Rename(items, name);
                    break;
            default:
                break;
        }
        std::cin.ignore();
        getchar();
    }
    items.clear();
}

void Clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Interface(const std::vector<my_vector> &items) {
    std::cout << "==================VECTORS==================" << std::endl;
    std::cout << "1.Create a new vector" << std::endl;
    std::cout << "2.Delete vector" << std::endl;
    std::cout << "3.Dot product (*)" << std::endl;
    std::cout << "4.Vector addition (+)" << std::endl;
    std::cout << "5.Vector substraction (-)" << std::endl;
    std::cout << "6.Find vectors length" << std::endl;
    std::cout << "7.Rename vector" << std::endl;
    std::cout << "0.Quit" << std::endl;
    std::cout << std::endl;
    Show_vectors(items);
}

bool Guard(const std::vector<my_vector> &items){
    Clear_screen();
    if(items.empty()) {
        std::cout << "Vectors not found!" << std::endl;
        return true;
    }
    return false;
}

void Show_vectors(const std::vector<my_vector> &items) {
    if(items.empty()) return;
    std::cout << "Your vectors: " << std::endl;
    for (size_t i = 0; i < items.size(); i++){
        std::cout << i << ") " << items[i].get_name()
        << " (" << items[i].get_x() << "; " << items[i].get_y()
        << ")" << std::endl;
    }
}

int Choose_id(std::vector<my_vector> &items) {
    int id = -1;
    while(id < 0 || id >= static_cast<int>(items.size())) {
        Clear_screen();
        Show_vectors(items);
        std::cout << "Enter id of vector you want to choose: ";
        std::cin >> id;
    }
    return id;
}

void Select_items(std::vector<my_vector> &items, int &first_id, int& second_id){
    std::cout << "Select two vectors: " << std::endl;
    first_id = Choose_id(items);
    second_id = Choose_id(items);

    std::cout << "First vector is: " << items[first_id].get_name() << std::endl;
    std::cout << "Second vector is: " << items[second_id].get_name() << std::endl;
}

void Create_vector(std::vector<my_vector> &items, std::string &name, float &x, float &y) {
    Clear_screen();
    std::cout << "Enter name of your vector: ";
    std::cin >> name;
    std::cout << "Enter X cordinate: ";
    std::cin >> x;
    std::cout << "Enter Y cordinate: ";
    std::cin >> y;
    items.emplace_back(x, y, name);
    std::cout << "Your new vector: " << name <<" ("<< x << ", " << y << " )" << std::endl;
}

void Delete_vector(std::vector<my_vector> &items) {
    if(Guard(items)) return;
    items.erase(items.begin() + Choose_id(items));
    for(int i = 0; i < items.size(); i++){
        items[i].set_id(i);
    }
    my_vector::set_curr_id(items.size() - 1);
    std::cout << "Vector has been deleted." << std::endl; 
}

void Dot_prod (std::vector<my_vector> &items, float &prod) {
    if(Guard(items)) throw 1;
    int first_id, second_id;
    Select_items(items, first_id, second_id);
    prod = items[first_id] * items[second_id];
}

my_vector Sum (std::vector<my_vector> &items) {
    if(Guard(items)) throw 1;
    int first_id, second_id;
    Select_items(items, first_id, second_id);
    return items[first_id] + items[second_id];
}


my_vector Sub (std::vector<my_vector> &items) {
    if(Guard(items)) throw 1;
    int first_id, second_id;
    Select_items(items, first_id, second_id);
    return items[first_id] - items[second_id];
}

float Vector_length(std::vector<my_vector> &items) {
    if(Guard(items)) throw 1;
    return items[Choose_id(items)].find_length();
}

void Rename(std::vector<my_vector> &items, std::string &name) {
    if(Guard(items)) return;
    int id = Choose_id(items);
    std::cout << "Enter name of your vector: ";
    std::cin >> name;
    items[id].set_name(name);
    std::cout << "Your vector now is: " << name <<" ("<< items[id].get_x() << ", " << items[id].get_y() << ")" << std::endl;
}