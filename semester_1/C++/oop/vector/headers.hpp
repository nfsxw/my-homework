#ifndef HEADERS_HPP
#define HEADERS_HPP

#include <vector>
#include "my_vector.hpp"

void Logic();
void Clear_screen();
void Interface(const std::vector<my_vector>&);
void Show_vectors(const std::vector<my_vector>&);
int Choose_id(std::vector<my_vector>&);
void Select_items(std::vector<my_vector>&, int&, int&);
void Create_vector(std::vector<my_vector>&, std::string&, float&, float&);
void Delete_vector(std::vector<my_vector>&);
void Dot_prod (std::vector<my_vector>&, float&);
my_vector Sum (std::vector<my_vector>&);
my_vector Sub (std::vector<my_vector>&);
float Vector_length(std::vector<my_vector>&);
void Rename(std::vector<my_vector>&, std::string&);
bool Guard(const std::vector<my_vector>&);

#endif