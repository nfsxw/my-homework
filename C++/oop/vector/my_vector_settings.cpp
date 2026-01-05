#include "my_vector.hpp"
#include <cmath>

my_vector::my_vector(float x, float y, std::string name) : x(x), y(y), name(name), id(curr_id++) {}
my_vector::my_vector(float x, float y) : x(x), y(y), name("new_vector"), id(curr_id++) {}
my_vector::my_vector(const my_vector &other) : x(other.x), y(other.y), name(other.name) {}
my_vector::my_vector() : my_vector(1, 1, "a") {} 
my_vector::~my_vector() {}

my_vector& my_vector::operator=(const my_vector &other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        name = other.name;
    }
    return *this;
}

const my_vector my_vector:: operator+(const my_vector &right) const {
    return my_vector(x + right.x, y + right.y);
}

const my_vector my_vector:: operator-(const my_vector &right) const {
    return my_vector(x - right.x, y - right.y);
}

float my_vector:: operator*(const my_vector &right) const {
    return x*right.x + y*right.y;
}

float my_vector:: find_length() const {
    return sqrtf(x*x + y*y);
}

void my_vector:: set_name(std::string name){
    this->name = name;
}

std::string my_vector:: get_name() const {
    return name;
}
        
int my_vector:: curr_id = 0;
