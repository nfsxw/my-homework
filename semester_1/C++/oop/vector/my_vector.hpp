#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <string>

class my_vector {
    public:
        my_vector(float x, float y, std::string name);
        my_vector(float x, float y);
        my_vector(const my_vector &other);
        my_vector();
        ~my_vector();
        const my_vector operator+(const my_vector &right) const;
        const my_vector operator-(const my_vector &right) const;
        my_vector& operator=(const my_vector &other);
        float operator*(const my_vector &right) const;
        float find_length() const;
        void set_name(std::string name);
        std::string get_name() const;

        static int get_curr_id() {
            return curr_id;
        }

        static void set_curr_id(int id) {
            curr_id = id;
        }

        float get_x() const {
            return x;
        }

        float get_y() const {
            return y;
        }

        int get_id() const {
            return id;
        }

        void set_id(int id) {
            this -> id = id;
        }

    protected:
        float x, y;
        int id;
        static int curr_id;
        std::string name;
};

#endif